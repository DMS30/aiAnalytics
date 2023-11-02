#import <Foundation/Foundation.h>
#import "aiStorage.h"


@interface aiFileStorage : NSObject <aiStorage>

@property (nonatomic, strong, nullable) id<aiCrypto> crypto;

- (instancetype _Nonnull)initWithFolder:(NSURL *_Nonnull)folderURL crypto:(id<aiCrypto> _Nullable)crypto;

- (NSURL *_Nonnull)urlForKey:(NSString *_Nonnull)key;
- (void)resetAll;

+ (NSURL *_Nullable)applicationSupportDirectoryURL;
+ (NSURL *_Nullable)cachesDirectoryURL;

@end
