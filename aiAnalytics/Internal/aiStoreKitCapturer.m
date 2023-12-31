#import "aiStoreKitCapturer.h"


@interface aiStoreKitCapturer ()

@property (nonatomic, readonly) aiHog *posthog;
@property (nonatomic, readonly) NSMutableDictionary *transactions;
@property (nonatomic, readonly) NSMutableDictionary *productRequests;

@end


@implementation aiStoreKitCapturer

+ (instancetype)captureTransactionsForPostHog:(aiHog *)posthog
{
    return [[aiStoreKitCapturer alloc] initWithPostHog:posthog];
}

- (instancetype)initWithPostHog:(aiHog *)posthog
{
    if (self = [self init]) {
        _posthog = posthog;
        _productRequests = [NSMutableDictionary dictionaryWithCapacity:1];
        _transactions = [NSMutableDictionary dictionaryWithCapacity:1];

        [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
    }
    return self;
}

- (void)dealloc
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];
}

#pragma mark - SKPaymentQueue Observer
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions
{
    for (SKPaymentTransaction *transaction in transactions) {
        if (transaction.transactionState != SKPaymentTransactionStatePurchased) {
            continue;
        }

        SKProductsRequest *request = [[SKProductsRequest alloc] initWithProductIdentifiers:[NSSet setWithObject:transaction.payment.productIdentifier]];
        @synchronized(self)
        {
            [self.transactions setObject:transaction forKey:transaction.payment.productIdentifier];
            [self.productRequests setObject:request forKey:transaction.payment.productIdentifier];
        }
        request.delegate = self;
        [request start];
    }
}

#pragma mark - SKProductsRequest delegate
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response
{
    for (SKProduct *product in response.products) {
        @synchronized(self)
        {
            SKPaymentTransaction *transaction = [self.transactions objectForKey:product.productIdentifier];
            [self captureTransaction:transaction forProduct:product];
            [self.transactions removeObjectForKey:product.productIdentifier];
            [self.productRequests removeObjectForKey:product.productIdentifier];
        }
    }
}

#pragma mark - Capture
- (void)captureTransaction:(SKPaymentTransaction *)transaction forProduct:(SKProduct *)product
{
    // it seems the identifier is nil for renewable subscriptions
    // see http://stackoverflow.com/questions/14827059/skpaymenttransactions-originaltransaction-transactionreceipt-nil-for-restore-on
    if (transaction.transactionIdentifier == nil) {
        return;
    }

    NSString *currency = [product.priceLocale objectForKey:NSLocaleCurrencyCode];

    [self.posthog capture:@"Order Completed" properties:@{
        @"orderId" : transaction.transactionIdentifier,
        @"affiliation" : @"App Store",
        @"currency" : currency ?: @"",
        @"products" : @[
            @{
               @"sku" : transaction.transactionIdentifier,
               @"quantity" : @(transaction.payment.quantity),
               @"productId" : product.productIdentifier ?: @"",
               @"price" : product.price ?: @0,
               @"name" : product.localizedTitle ?: @"",
            }
        ]
    }];
}

@end
