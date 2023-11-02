#import <Foundation/Foundation.h>
#import "aiIdentifyPayload.h"
#import "aiCapturePayload.h"
#import "aiScreenPayload.h"
#import "aiAliasPayload.h"
#import "aiGroupPayload.h"

#import "aiIdentifyPayload.h"
#import "aiContext.h"

NS_ASSUME_NONNULL_BEGIN

@protocol aiIntegration <NSObject>

@optional
// Identify will be called when the user calls either of the following:
// 1. [[aiHog sharedInstance] identify:someDistinctId];
// 2. [[aiHog sharedInstance] identify:someDistinctId properties:someProperties];
// 3. [[aiHog sharedInstance] identify:someDistinctId properties:someProperties options:someOptions];
- (void)identify:(aiIdentifyPayload *)payload;

// Capture will be called when the user calls either of the following:
// 1. [[aiHog sharedInstance] capture:someEvent];
// 2. [[aiHog sharedInstance] capture:someEvent properties:someProperties];
// 3. [[aiHog sharedInstance] capture:someEvent properties:someProperties options:someOptions];
- (void)capture:(aiCapturePayload *)payload;

// Screen will be called when the user calls either of the following:
// 1. [[aiHog sharedInstance] screen:someEvent];
// 2. [[aiHog sharedInstance] screen:someEvent properties:someProperties];
// 3. [[aiHog sharedInstance] screen:someEvent properties:someProperties options:someOptions];
- (void)screen:(aiScreenPayload *)payload;

// Alias will be called when the user calls either of the following:
// 1. [[aiHog sharedInstance] alias:someNewAlias];
// 2. [[aiHog sharedInstance] alias:someNewAlias options:someOptions];
- (void)alias:(aiAliasPayload *)payload;

- (void)group:(aiGroupPayload *)payload;

// Reset is invoked when the user logs out, and any data saved about the user should be cleared.
- (void)reset;

// Flush is invoked when any queued events should be uploaded.
- (void)flush;

// App Delegate Callbacks

// Callbacks for notifications changes.
// ------------------------------------
- (void)receivedRemoteNotification:(NSDictionary *)userInfo;
- (void)failedToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)registeredForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo;

// Callbacks for app state changes
// -------------------------------

- (void)applicationDidFinishLaunching:(NSNotification *)notification;
- (void)applicationDidEnterBackground;
- (void)applicationWillEnterForeground;
- (void)applicationWillTerminate;
- (void)applicationWillResignActive;
- (void)applicationDidBecomeActive;

- (void)continueUserActivity:(NSUserActivity *)activity;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options;

@end

NS_ASSUME_NONNULL_END
