//
//  ViewController.h
//  AirplaySelector
//
//  Copyright (c) 2015 Sauce Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (nonatomic, readonly, retain) UIScreen *mirroredScreen;
@property (nonatomic) bool mirrorFound;
@property (nonatomic) bool connected;
@property (nonatomic) int times2try, i;
@property (retain, nonatomic) IBOutlet UILabel* statusLabel;
@property IBOutlet UIActivityIndicatorView* spinner;

- (void) changeLabelText:(NSString* ) text;

@end

