//
//  AudirvanaDiscordRPC.m
//  AudirvanaDiscordRPC
//
//  Created by Trung Nguyễn on 7/12/20.
//  Copyright © 2020 Trung Nguyễn. All rights reserved.
//

#import "AudirvanaDiscordRPC.h"
#import "Audirvana.h"
NSString* parseTime(double t){
    int ts = (int)t;
    return [[NSString alloc] initWithFormat:@"%02d:%02d",ts/60,ts%60];
}

@implementation AudirvanaDiscordRPC
-(id)init{
    self = [super init];
    discord_app = new DiscordRPC::Application();
    discord_app->Initialize();
    return self;
}
-(void)run {
    AudirvanaApplication *app = (AudirvanaApplication*)NSApp;
    if(app==nil) return;
    NSString* s;
    switch ([[app playerState] intValue]) {
        case AudirvanaPlayerStatusPaused:
            s = @"Paused";
            break;
        case AudirvanaPlayerStatusPlaying:
            s = @"Playing";
            break;
        case AudirvanaPlayerStatusStopped:
            s = @"Stopped";
            break;
        default:
            return;
    }
    //    NSLog(@"playingTrackTitle: %@", [app playingTrackTitle]);
    //    NSLog(@"playerPosition: %@", [app playerPosition]);
    NSString *details = @"";
    if(![s isEqualToString:@"Stopped"]){
        s = [[NSString alloc] initWithFormat:@"%@ (%@/%@)",s,parseTime([[app playerPosition] doubleValue]),parseTime([[app playingTrackDuration] doubleValue])];
        details = [[NSString alloc] initWithFormat:@"%@ - %@ (%@)",[app playingTrackTitle],[app playingTrackArtist],[app playingTrackAlbum]];
    }
    discord_app->SetStatus([s cStringUsingEncoding:NSUTF8StringEncoding], [details cStringUsingEncoding:NSUTF8StringEncoding]);
    if(discord_app->RunCallbacks()!=discord::Result::Ok){
        discord_app->Initialize();
        last_s = nil;
        last_details = nil;
    }
}

@end

@interface HOOKAppDelegate : NSObject <AutoHook>
@end
@implementation HOOKAppDelegate

+ (NSArray *)targetClasses {
    return @[@"AppDelegate"];
}

- (void)hook_applicationDidFinishLaunching:(id)arg1{
    [self original_applicationDidFinishLaunching:arg1];
    NSLog(@"%@", NSApp);
    if(NSApp!=nil){
        AudirvanaDiscordRPC* rpc = [[AudirvanaDiscordRPC alloc] init];
        NSTimer* timer = [NSTimer timerWithTimeInterval:0.8 target:rpc selector:@selector(run) userInfo:NULL repeats:true];
        [[NSRunLoop mainRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    }
}
- (void)original_applicationDidFinishLaunching:(id)arg1 { }
@end
