//
//  DiscordRPC.hpp
//  AudirvanaDiscordRPC
//
//  Created by Trung Nguyễn on 7/12/20.
//  Copyright © 2020 Trung Nguyễn. All rights reserved.
//

#ifndef DiscordRPC_hpp
#define DiscordRPC_hpp

#include <stdio.h>
#include <string>
#include "discord/discord.h"
namespace DiscordRPC{
class Application {
    std::unique_ptr<discord::Core> core;
public:
    discord::Result Initialize();
    void SetStatus(const char* state, const char* details);
    discord::Result RunCallbacks();
};
}
#endif /* DiscordRPC_hpp */
