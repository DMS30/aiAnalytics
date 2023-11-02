#import <Foundation/Foundation.h>
#import "aiPayload.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiCapturePayload : aiPayload

@property (nonatomic, readonly) NSString *event;

@property (nonatomic, readonly, nullable) NSDictionary *properties;

- (instancetype)initWithEvent:(NSString *)event
                   properties:(NSDictionary *_Nullable)properties;

@end

NS_ASSUME_NONNULL_END
