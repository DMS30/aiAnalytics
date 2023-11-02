#import <Foundation/Foundation.h>
#import "aiPayload.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiScreenPayload : aiPayload

@property (nonatomic, readonly) NSString *name;

@property (nonatomic, readonly, nullable) NSDictionary *properties;

- (instancetype)initWithName:(NSString *)name
                  properties:(NSDictionary *_Nullable)properties;

@end

NS_ASSUME_NONNULL_END
