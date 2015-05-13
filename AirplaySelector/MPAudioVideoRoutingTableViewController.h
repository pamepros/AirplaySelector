//
//  MPAudioVideoRoutingTableViewController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-02.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

@class MPAVRoutingController, NSArray, NSString;

@interface MPAudioVideoRoutingTableViewController : UITableViewController <MPAVRoutingControllerDelegate> {
    int _airPlayPasswordAlertDidAppearToken;
    BOOL _airPlayPasswordAlertDidAppearTokenIsValid;
    int _airPlayPasswordAlertDidCancelToken;
    unsigned int _avItemType;
    BOOL _displayMirroringRoutes;
    NSArray *_displayedRoutes;
    MPAVRoutingController *_routingController;
    BOOL _wirelessDisplayCapableRouteIsPicked;
    BOOL _wirelessDisplayRouteIsPendingAsPicked;
}

@property(copy,readonly) NSString * debugDescription;
@property(copy,readonly) NSString * description;
@property(readonly) unsigned int hash;
@property(readonly) MPAVRoutingController * routingController;
@property(readonly) Class superclass;

+ (id)routesPreferringMirroring;

//- (void).cxx_destruct;
- (id)_availableRoutes;
- (void)_debugButtonAction:(id)arg1;
- (id)_displayedRoutes;
- (id)_effectivePickedRouteReturningActualPickedRouteType:(int*)arg1;
- (void)_mirroringSwitchValueDidChange:(id)arg1;
- (id)_pickedRoute;
- (BOOL)_wirelessDisplayCapableRouteIsPicked;
- (void)dealloc;
- (id)initWithType:(unsigned int)arg1 displayMirroringRoutes:(BOOL)arg2;
- (id)routingController;
- (void)routingControllerAvailableRoutesDidChange:(id)arg1;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (id)tableView:(id)arg1 willSelectRowAtIndexPath:(id)arg2;
- (void)viewDidAppear:(BOOL)arg1;

@end
