#import "aiScreenPayload.h"


@implementation aiScreenPayload

- (instancetype)initWithName:(NSString *)name
                  properties:(NSDictionary *)properties
{
    if (self = [super init]) {
        _name = [name copy];
        _properties = [properties copy];
    }
    return self;
}

@end
