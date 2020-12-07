//
//  AudirvanaDiscordRPC.h
//  AudirvanaDiscordRPC
//
//  Created by Trung Nguyễn on 7/12/20.
//  Copyright © 2020 Trung Nguyễn. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "DiscordRPC.hpp"
#import "AutoHook/AutoHook.h"

@interface AudirvanaDiscordRPC : NSObject
{
    NSString* last_s;
    NSString* last_details;
    DiscordRPC::Application* discord_app;
}
-(void)run;
@end
