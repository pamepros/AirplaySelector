//
//  MPAVRoutingController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-01.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

@protocol MPAVRoutingControllerDelegate;
@class MPAVRoute, NSArray, NSMutableArray, NSString;

@interface MPAVRoutingController : NSObject {
    NSMutableArray *_asyncFetchingCompletionHandlers;
    BOOL _asyncFetchingRoutes;
    MPAVRoute *_cachedPickedRoute;
    NSArray *_cachedRoutes;
    NSString *_category;
    id<MPAVRoutingControllerDelegate> _delegate;
    int _deviceAvailabilityNotifyToken;
    BOOL _deviceAvailabilityOverrideState;
    int _discoveryMode;
    int _externalScreenType;
    BOOL _hasExternalScreenType;
    BOOL _hasVolumeControlInfoForPickedRoute;
    NSString *_name;
    BOOL _pickedRouteHasVolumeControl;
    BOOL _scheduledSendDelegateRoutesChanged;
}

@property(copy,readonly) NSArray * availableRoutes;
@property(copy) NSString * category;
@property id<MPAVRoutingControllerDelegate> delegate;
@property int discoveryMode;
@property(readonly) int externalScreenType;
@property(copy) NSString * name;
@property(readonly) MPAVRoute * pickedRoute;
@property(readonly) BOOL volumeControlIsAvailable;

//- (void).cxx_destruct;
- (void)_activeAudioRouteDidChangeNotification:(id)arg1;
- (void)_externalScreenTypeDidChangeNotification:(id)arg1;
- (void)_mediaServerDiedNotification:(id)arg1;
- (id)_parseAVRouteDescriptions:(id)arg1;
- (void)_pickableRoutesDidChangeNotification:(id)arg1;
- (void)_registerNotifications;
- (void)_routeStatusDidChangeNotification:(id)arg1;
- (void)_scheduleSendDelegateRoutesChanged;
- (void)_setExternalScreenType:(int)arg1;
- (void)_unregisterNotifications;
- (void)_updateCachedRoutes;
- (BOOL)airtunesRouteIsPicked;
- (id)availableRoutes;
- (id)category;
- (void)clearCachedRoutes;
- (void)dealloc;
- (id)delegate;
- (id)description;
- (int)discoveryMode;
- (int)externalScreenType;
- (void)fetchAvailableRoutesWithCompletionHandler:(id)arg1;
- (BOOL)handsetRouteIsPicked;
- (id)init;
- (id)initWithName:(id)arg1;
- (void)logCurrentRoutes;
- (id)name;
- (BOOL)pickBestDeviceRoute;
- (BOOL)pickHandsetRoute;
- (BOOL)pickRoute:(id)arg1 withPassword:(id)arg2;
- (BOOL)pickRoute:(id)arg1;
- (BOOL)pickSpeakerRoute;
- (id)pickedRoute;
- (BOOL)receiverRouteIsPicked;
- (BOOL)routeOtherThanHandsetAndSpeakerAvailable;
- (BOOL)routeOtherThanHandsetAvailable;
- (void)setCategory:(id)arg1;
- (void)setDelegate:(id)arg1;
- (void)setDiscoveryMode:(int)arg1;
- (void)setName:(id)arg1;
- (BOOL)speakerRouteIsPicked;
- (id)videoRouteForRoute:(id)arg1;
- (BOOL)volumeControlIsAvailable;
- (BOOL)wirelessDisplayRouteIsPicked;
- (BOOL)wirelessDisplayRoutesAvailable;

@end