//
//  MPAVSystemRoutingController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-02.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

//@protocol OS_dispatch_queue;
@class NSPointerArray;

@interface MPAVSystemRoutingController : NSObject {
    int _clientDiscoveryMode;
    NSPointerArray *_clientRoutingControllers;
    int _debugNotifyToken;
    id<OS_dispatch_queue> _serialQueue;
}

+ (id)sharedRoutingController;

//- (void).cxx_destruct;
- (void)_clientRoutingControllerDidUpdateDiscoveryModeNotification:(id)arg1;
- (void)_debugLogSystemControllerState;
- (id)_init;
- (void)_onQueueUpdateClientRouteDiscoveryMode;
- (void)_updateClientRouteDiscoveryMode;
- (void)dealloc;
- (id)init;
- (void)registerClientRoutingController:(id)arg1;
- (void)unregisterClientRoutingController:(id)arg1;

@end