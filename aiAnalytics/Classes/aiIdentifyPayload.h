#import <Foundation/Foundation.h>
#import "aiPayload.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiIdentifyPayload : aiPayload

@property (nonatomic, readonly, nullable) NSString *distinctId;

@property (nonatomic, readonly, nullable) NSString *anonymousId;

@property (nonatomic, readonly, nullable) JSON_DICT properties;

- (instancetype)initWithDistinctId:(NSString *)distinctId
                       anonymousId:(NSString *_Nullable)anonymousId
                        properties:(JSON_DICT _Nullable)properties;

@end

NS_ASSUME_NONNULL_END
