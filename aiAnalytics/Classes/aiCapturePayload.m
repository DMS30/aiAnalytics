#import "aiCapturePayload.h"


@implementation aiCapturePayload


- (instancetype)initWithEvent:(NSString *)event
                   properties:(NSDictionary *)properties
{
    if (self = [super init]) {
        _event = [event copy];
        _properties = [properties copy];
    }
    return self;
}

@end
