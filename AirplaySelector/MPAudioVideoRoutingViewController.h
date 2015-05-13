//
//  MPAudioVideoRoutingViewController.h
//  AirplayMirrorApp
//
//  Created by michaelhan on 2014-12-01.
//  Copyright (c) 2014 Michael Han. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol MPAudioVideoRoutingViewControllerDelegate;
@class MPAudioVideoRoutingTableViewController, UINavigationController;

@interface MPAudioVideoRoutingViewController : UIViewController {
    id<MPAudioVideoRoutingViewControllerDelegate> _delegate;
    UINavigationController *_navigationController;
    MPAudioVideoRoutingTableViewController *_tableViewController;
}

@property id<MPAudioVideoRoutingViewControllerDelegate> delegate;

+ (BOOL)hasWirelessDisplayRoutes;

//- (void).cxx_destruct;
- (void)_doneAction:(id)arg1;
//- (id)delegate;
- (id)init;
//- (void)setDelegate:(id)arg1;
- (void)viewDidLoad;

@end