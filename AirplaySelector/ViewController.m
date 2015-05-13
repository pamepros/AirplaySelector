//
//  ViewController.m
//  AirplaySelector
//
//  Copyright (c) 2015 Sauce Labs. All rights reserved.
//

#import "ViewController.h"
#import "MPAudioVideoRoutingViewController.h"
#import "MPAVRoutingController.h"
#import "MPAVSystemRoutingController.h"
#import "MPAudioVideoRoutingTableViewController.h"
#import "MPAudioDeviceController.h"
#import "MPAVRoute.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize mirrorFound, times2try, connected, mirroredScreen, i, spinner, statusLabel;

- (void)viewDidLoad {
    [super viewDidLoad];
    mirrorFound = false;
    times2try = 3;
    connected = false;
    [spinner startAnimating];
    [self changeLabelText:@"Sauce Labs"];
    
    [NSThread sleepForTimeInterval:3.0];
    i = 0;
    [self searchAirplayDevices];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)closeApp{
    UIApplication* app = [UIApplication sharedApplication];
    if (connected) {
        [app performSelector:@selector(suspend)];
    }else{
        NSLog(@"Exit now");
        exit(0);
    }
}

- (void)changeLabelText:(NSString* ) text{
    statusLabel.text = text;
}

- (void)searchAirplayDevices {
    [self changeLabelText:@"Searching Airplay Devices"];
    MPAudioVideoRoutingTableViewController *tableViewController = [[MPAudioVideoRoutingTableViewController alloc] initWithType:0 displayMirroringRoutes:YES];
    i++;
    
    if (i>times2try) {
        NSLog(@"I'm tired of trying to connect, this is not working");
        [self changeLabelText:@"I'm tired of trying to connect, this is not working"];
        [NSThread sleepForTimeInterval:2.0];
        [self closeApp];
        return;
    }
    
    MPAVRoutingController *tableRouteController = [tableViewController routingController];
    [tableRouteController fetchAvailableRoutesWithCompletionHandler:^(NSArray *routes) {
        NSLog(@"* Tried %d times", i);
        for (MPAVRoute *route in routes) {
            MPAVRoute *displayRoute = [route wirelessDisplayRoute];
            NSLog(@"* display route %@", displayRoute);
            if (displayRoute) {
                
                if ([[displayRoute routeName] isEqualToString:@"SauceAirplay"]) {
                    mirrorFound = true;
                    NSString *text =[[NSString stringWithFormat:@"Found!! "] stringByAppendingString:[displayRoute routeName]];
                    [self changeLabelText:text];
                    NSLog(@"found!! %@", [displayRoute routeName]);
                    [tableRouteController pickRoute:displayRoute];
                    
                }else{
                   [self changeLabelText:@"Mirror Not Found"];
                    NSLog(@"* SauceAirplay not found!!");
                    
                }
            }
            
        }
        if (mirrorFound) {
            connected = [self checkConnected];
            if (connected) {
                NSLog(@"CONNECTED TO SauceAirplay");
                [spinner stopAnimating];
                [self changeLabelText:@"Connected to mirror"];
                [self closeApp];
            }else{
                [self changeLabelText:@"FOUND BUT NOT CONNECTED, retrying"];
                [self searchAirplayDevices];
            }
            
        }else{
            [self changeLabelText:@"NOT CONNECTED, retrying"];
            [self searchAirplayDevices];            
        }
    }];
    // wait 3 seconds before retrying to find the mirror
    [NSThread sleepForTimeInterval:3.0];
}

- (bool)checkConnected {
    
    // we need to use the secondary screen since the mainScreen does not mirror itself
    if ([[UIScreen screens] count] > 1) {
        UIScreen *secondaryScreen = [[UIScreen screens] objectAtIndex:1];
        NSLog(@"%@", secondaryScreen.mirroredScreen); // is actually the mainScreen
        if(secondaryScreen.mirroredScreen != nil){
            //screen is being mirrored
            NSLog(@" *** MIRRORED");
            return true;
        }
    }
    NSLog(@" *** SCREEN IS NOT MIRRORED");
    return false;
}

@end
