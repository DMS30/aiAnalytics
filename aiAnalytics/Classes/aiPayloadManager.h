#import <Foundation/Foundation.h>
#import "aiMiddleware.h"

/**
 * NSNotification name, that is posted after integrations are loaded.
 */
extern NSString *_Nonnull aiHogIntegrationDidStart;

@class aiHog;


@interface aiPayloadManager : NSObject

- (instancetype _Nonnull)initWithPostHog:(aiHog *_Nonnull)posthog;

- (NSArray *_Nonnull)getFeatureFlags;
- (NSDictionary *_Nonnull)getFlagVariants;
- (NSDictionary *_Nonnull)getFeatureFlagPayloads;
- (NSDictionary *_Nonnull)getGroups;
- (void)saveGroup:(NSString *_Nonnull)groupType groupKey:(NSString *_Nonnull)groupKey;

// @Deprecated - Exposing for backward API compat reasons only
- (NSString *_Nonnull)getAnonymousId;

@end


@interface aiPayloadManager (aiMiddleware) <aiMiddleware>

@end
