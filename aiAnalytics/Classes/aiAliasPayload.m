#import "aiAliasPayload.h"


@implementation aiAliasPayload

- (instancetype)initWithAlias:(NSString *)alias
{
    if (self = [super init]) {
        _alias = [alias copy];
    }
    return self;
}

@end
