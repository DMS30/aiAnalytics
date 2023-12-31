#import <Foundation/Foundation.h>
#import "aiCrypto.h"


@interface PHGAES256Crypto : NSObject <aiCrypto>

@property (nonatomic, readonly, nonnull) NSString *password;
@property (nonatomic, readonly, nonnull) NSData *salt;
@property (nonatomic, readonly, nonnull) NSData *iv;

- (instancetype _Nonnull)initWithPassword:(NSString *_Nonnull)password salt:(NSData *_Nonnull)salt iv:(NSData *_Nonnull)iv;
// Convenient shorthand. Will randomly generate salt and iv.
- (instancetype _Nonnull)initWithPassword:(NSString *_Nonnull)password;

+ (NSData *_Nonnull)randomDataOfLength:(size_t)length;

@end
