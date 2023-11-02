#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "aiHog.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiStoreKitCapturer : NSObject <SKPaymentTransactionObserver, SKProductsRequestDelegate>

+ (instancetype)captureTransactionsForPostHog:(aiHog *)posthog;

@end

NS_ASSUME_NONNULL_END
