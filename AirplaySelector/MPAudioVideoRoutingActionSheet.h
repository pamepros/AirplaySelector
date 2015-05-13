//
//  MPAudioVideoRoutingActionSheet.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-01.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

@class MPAVRoutingController, NSArray, NSString, UIViewController, UIWindow;

@interface MPAudioVideoRoutingActionSheet : UIActionSheet <UIActionSheetDelegate> {
    int _airPlayPasswordAlertDidAppearToken;
    BOOL _airPlayPasswordAlertDidAppearTokenIsValid;
    unsigned int _avItemType;
    id _completionHandler;
    NSArray *_displayedRoutes;
    MPAVRoutingController *_routingController;
    BOOL _shouldPauseAfterDismissing;
    UIViewController *_viewControllerForActionSheet;
    UIWindow *_windowForActionSheet;
}

@property(copy,readonly) NSString * debugDescription;
@property(copy,readonly) NSString * description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

//- (void).cxx_destruct;
- (id)_availableRoutes;
- (void)_debugButtonAction:(id)arg1;
- (BOOL)_isDeviceVideoRoute:(id)arg1;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(int)arg2;
- (void)actionSheet:(id)arg1 didDismissWithButtonIndex:(int)arg2;
- (void)dealloc;
- (id)initWithType:(unsigned int)arg1 routingController:(id)arg2;
- (id)initWithType:(unsigned int)arg1;
- (void)layoutSubviews;
- (void)showFromRect:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 inView:(id)arg2 animated:(BOOL)arg3 withCompletionHandler:(id)arg4;
- (void)showInPopoverFromRect:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 inView:(id)arg2 backgroundStyle:(int)arg3 animated:(BOOL)arg4 completionHandler:(id)arg5;
- (void)showWithValidInterfaceOrientationMaskBlock:(id)arg1 completionHandler:(id)arg2;
- (void)showWithValidInterfaceOrientationMaskBlock:(id)arg1 windowLevel:(float)arg2 completionHandler:(id)arg3;
- (void)showWithValidInterfaceOrientationsBlock:(id)arg1 completionHandler:(id)arg2;

@end