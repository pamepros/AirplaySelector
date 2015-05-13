//
//  MPAudioDeviceController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-02.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

@class NSArray, NSDictionary, NSMutableArray, NSString;

@interface MPAudioDeviceController : NSObject {
    NSString *_category;
    id _delegate;
    BOOL _determiningPickableRoutes;
    BOOL _fakeRouteAvailable;
    NSArray *_pickableRoutes;
    NSMutableArray *_pickableRoutesCompletionHandlers;
    NSDictionary *_pickedRoute;
    BOOL _pickedRouteHasVolumeControl;
    BOOL _pickedRouteHasVolumeControlIsValid;
    BOOL _scheduledSendAudioRoutesDidChange;
}

@property id delegate;
@property BOOL routeDiscoveryEnabled;

+ (void)_internalPushRouteDiscoveryMode:(int)arg1;
+ (void)_internalSetSystemRouteDiscoveryMode:(int)arg1;
+ (id)_routeDiscoveryModeStack;
+ (void)pushRouteDiscoveryMode:(int)arg1;
+ (void)restoreRouteDiscoveryMode;
+ (BOOL)routeDiscoveryEnabled;
+ (int)routeDiscoveryMode;
+ (void)setRouteDiscoveryEnabled:(BOOL)arg1;
+ (void)setRouteDiscoveryMode:(int)arg1;

//- (void).cxx_destruct;
- (void)_activeAudioRouteDidChange:(id)arg1;
- (void)_mediaServerDiedNotification:(id)arg1;
- (id)_pickableRoutes;
- (void)_pickableRoutesChangedNotification:(id)arg1;
- (id)_pickedRoute;
- (void)_portStatusDidChangeNotification:(id)arg1;
- (void)_registerNotifications;
- (void)_routeDiscoveryDidEndNotification:(id)arg1;
- (BOOL)_routeIsDisplayPort:(id)arg1;
- (BOOL)_routeIsHandset:(id)arg1;
- (BOOL)_routeIsHeadphones:(id)arg1;
- (BOOL)_routeIsReceiver:(id)arg1;
- (BOOL)_routeIsSpeaker:(id)arg1;
- (BOOL)_routeIsWireless:(id)arg1;
- (void)_scheduleSendDelegateAudioRoutesChanged;
- (void)_sendFakeRouteChange;
- (void)_unregisterNotifications;
- (BOOL)airtunesRouteIsPicked;
- (void)alertView:(id)arg1 didDismissWithButtonIndex:(int)arg2;
- (void)clearCachedRoutes;
- (void)dealloc;
- (id)delegate;
- (void)determinePickableRoutesWithCompletionHandler:(id)arg1;
- (BOOL)handsetRouteIsPicked;
- (int)indexOfPickedRoute;
- (int)indexOfRouteWithName:(id)arg1;
- (id)init;
- (BOOL)isPickedRouteDistinctFromRoute:(id)arg1;
- (void)logCurrentRoutes;
- (id)nameOfPickedRoute;
- (unsigned int)numberOfAudioRoutes;
- (BOOL)pickBestDeviceRoute;
- (BOOL)pickHandsetRoute;
- (BOOL)pickRoute:(id)arg1 withPassword:(id)arg2;
- (BOOL)pickRoute:(id)arg1;
- (BOOL)pickRouteAtIndex:(unsigned int)arg1 withPassword:(id)arg2;
- (BOOL)pickRouteAtIndex:(unsigned int)arg1;
- (BOOL)pickSpeakerRoute;
- (id)pickedRouteDescription;
- (BOOL)receiverRouteIsPicked;
- (void)restorePickedRoute;
- (id)routeDescriptionAtIndex:(unsigned int)arg1;
- (BOOL)routeDiscoveryEnabled;
- (id)routeNameAtIndex:(unsigned int)arg1 isPicked:(BOOL*)arg2;
- (BOOL)routeOtherThanHandsetAndSpeakerIsAvailable;
- (BOOL)routeOtherThanHandsetIsAvailable;
- (BOOL)routeRequiresPasswordAtIndex:(unsigned int)arg1;
- (id)routeTypeAtIndex:(unsigned int)arg1;
- (void)setCategory:(id)arg1;
- (void)setDelegate:(id)arg1;
- (void)setRouteDiscoveryEnabled:(BOOL)arg1;
- (BOOL)speakerRouteIsPicked;
- (BOOL)volumeControlIsAvailable;
- (BOOL)wirelessRouteIsPicked;

@end