#import <Foundation/Foundation.h>
#import "aiStorage.h"


@interface aiUserDefaultsStorage : NSObject <aiStorage>

@property (nonatomic, strong, nullable) id<aiCrypto> crypto;
@property (nonnull, nonatomic, readonly) NSUserDefaults *defaults;
@property (nullable, nonatomic, readonly) NSString *namespacePrefix;

- (instancetype _Nonnull)initWithDefaults:(NSUserDefaults *_Nonnull)defaults namespacePrefix:(NSString *_Nullable)namespacePrefix crypto:(id<aiCrypto> _Nullable)crypto;

@end
