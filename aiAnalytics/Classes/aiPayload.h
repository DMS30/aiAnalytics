#import <Foundation/Foundation.h>
#import "aiSerializableValue.h"

NS_ASSUME_NONNULL_BEGIN


@interface aiPayload : NSObject

@end


@interface PHGApplicationLifecyclePayload : aiPayload

@property (nonatomic, strong) NSString *notificationName;

// ApplicationDidFinishLaunching only
@property (nonatomic, strong, nullable) NSDictionary *launchOptions;

@end


@interface PHGContinueUserActivityPayload : aiPayload

@property (nonatomic, strong) NSUserActivity *activity;

@end


@interface PHGOpenURLPayload : aiPayload

@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) NSDictionary *options;

@end

NS_ASSUME_NONNULL_END


@interface PHGRemoteNotificationPayload : aiPayload

// PHGEventTypeHandleActionWithForRemoteNotification
@property (nonatomic, strong, nullable) NSString *actionIdentifier;

// PHGEventTypeHandleActionWithForRemoteNotification
// PHGEventTypeReceivedRemoteNotification
@property (nonatomic, strong, nullable) NSDictionary *userInfo;

// PHGEventTypeFailedToRegisterForRemoteNotifications
@property (nonatomic, strong, nullable) NSError *error;

// PHGEventTypeRegisteredForRemoteNotifications
@property (nonatomic, strong, nullable) NSData *deviceToken;

@end
