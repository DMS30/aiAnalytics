#import <Foundation/Foundation.h>
#import "aiPayload.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiAliasPayload : aiPayload

@property (nonatomic, readonly) NSString *alias;

- (instancetype)initWithAlias:(NSString *)alias;

@end

NS_ASSUME_NONNULL_END
