#import <Foundation/Foundation.h>
#import "aiHTTPClient.h"
#import "aiIntegration.h"
#import "aiStorage.h"

@class aiIdentifyPayload;
@class aiCapturePayload;
@class aiScreenPayload;
@class aiAliasPayload;
@class aiGroupPayload;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const aiHogDidSendRequestNotification;
extern NSString *const aiHogRequestDidSucceedNotification;
extern NSString *const aiHogRequestDidFailNotification;


@interface aiHogIntegration : NSObject <aiIntegration>

@property (nonatomic, copy, nullable) NSString *distinctId;

- (id)initWithPostHog:(aiHog *)posthog httpClient:(aiHTTPClient *)httpClient fileStorage:(id<aiStorage>)fileStorage userDefaultsStorage:(id<aiStorage>)userDefaultsStorage;
- (NSDictionary *)staticContext;
- (NSDictionary *)liveContext;
- (void)saveDistinctId:(NSString *)distinctId;

- (NSDictionary *_Nonnull)getGroups;
- (void)saveGroup:(NSString *_Nonnull)groupType groupKey:(NSString *_Nonnull)groupKey;

- (NSArray *_Nonnull)getFeatureFlags;
- (NSDictionary *)getFeatureFlagsAndValues;
- (NSDictionary *)getFeatureFlagPayloads;
- (void)receivedFeatureFlags:(NSDictionary *)flags payloads:(NSDictionary *)payloads;

@end

NS_ASSUME_NONNULL_END
