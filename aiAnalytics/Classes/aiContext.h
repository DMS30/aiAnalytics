#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHGEventType) {
    // Should not happen, but default state
    PHGEventTypeUndefined,
    // Core Capturing Methods
    PHGEventTypeIdentify,
    PHGEventTypeCapture,
    PHGEventTypeScreen,
    PHGEventTypeAlias,
    PHGEventTypeGroup,

    // General utility
    PHGEventTypeReset,
    PHGEventTypeFlush,
    
    // FeatureFlags Methods
    PHGEventTypeReloadFeatureFlags,

    // Remote Notification
    PHGEventTypeReceivedRemoteNotification,
    PHGEventTypeFailedToRegisterForRemoteNotifications,
    PHGEventTypeRegisteredForRemoteNotifications,
    PHGEventTypeHandleActionWithForRemoteNotification,

    // Application Lifecycle
    PHGEventTypeApplicationLifecycle,
    //    DidFinishLaunching,
    //    PHGEventTypeApplicationDidEnterBackground,
    //    PHGEventTypeApplicationWillEnterForeground,
    //    PHGEventTypeApplicationWillTerminate,
    //    PHGEventTypeApplicationWillResignActive,
    //    PHGEventTypeApplicationDidBecomeActive,

    // Misc.
    PHGEventTypeContinueUserActivity,
    PHGEventTypeOpenURL,

};

@class aiHog;
@protocol PHGMutableContext;
@class aiPayload;


@interface aiContext : NSObject <NSCopying>

// Loopback reference to the top level aiHog object.
// Not sure if it's a good idea to keep this around in the context.
// since we don't really want people to use it due to the circular
// reference and logic (Thus prefixing with underscore). But
// Right now it is required for integrations to work so I guess we'll leave it in.
@property (nonatomic, readonly, nonnull) aiHog *_posthog;
@property (nonatomic, readonly) PHGEventType eventType;

@property (nonatomic, readonly, nullable) NSString *distinctId;
@property (nonatomic, readonly, nullable) NSString *anonymousId;
@property (nonatomic, readonly, nullable) NSError *error;
@property (nonatomic, readonly, nullable) aiPayload *payload;
@property (nonatomic, readonly) BOOL debug;

- (instancetype _Nonnull)initWithPostHog:(aiHog *_Nonnull)posthog;

- (aiContext *_Nonnull)modify:(void (^_Nonnull)(id<PHGMutableContext> _Nonnull ctx))modify;

@end

@protocol PHGMutableContext <NSObject>

@property (nonatomic) PHGEventType eventType;
@property (nonatomic, nullable) NSString *distinctId;
@property (nonatomic, nullable) NSString *anonymousId;
@property (nonatomic, nullable) aiPayload *payload;
@property (nonatomic, nullable) NSError *error;
@property (nonatomic) BOOL debug;

@end
