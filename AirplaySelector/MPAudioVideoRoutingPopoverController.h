//
//  MPAudioVideoRoutingPopoverController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-01.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

@class NSString;
@protocol MPAVRoutingViewControllerDelegate;

@interface MPAudioVideoRoutingPopoverController : UIPopoverController <MPAVRoutingViewControllerDelegate> {
    int _airPlayPasswordAlertDidAppearToken;
    BOOL _airPlayPasswordAlertDidAppearTokenIsValid;
    BOOL _mirroringIncluded;
}

@property(copy,readonly) NSString * debugDescription;
@property(copy,readonly) NSString * description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

- (id)_tableViewController;
- (void)dealloc;
- (id)initWithContentViewController:(id)arg1;
- (id)initWithType:(unsigned int)arg1 includeMirroring:(BOOL)arg2;
- (id)initWithType:(unsigned int)arg1;
- (id)routingController;
- (void)routingViewController:(id)arg1 didPickRoute:(id)arg2;

@end