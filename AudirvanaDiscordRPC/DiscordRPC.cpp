//
//  DiscordRPC.cpp
//  AudirvanaDiscordRPC
//
//  Created by Trung Nguyễn on 7/12/20.
//  Copyright © 2020 Trung Nguyễn. All rights reserved.
//

#include "discord/discord.h"

#include "DiscordRPC.hpp"

namespace DiscordRPC{
discord::Result Application::Initialize(){
    discord::Core* core{};
    auto result = discord::Core::Create(692960586387947521, DiscordCreateFlags_NoRequireDiscord, &core);
    this->core.reset(core);
    return result;
}
void Application::SetStatus(const char* state, const char* details){
    if(!this->core) return;
    discord::Activity activity{};
    activity.SetDetails(state);
    activity.SetState(details);
    activity.SetType(discord::ActivityType::Listening);
    activity.GetAssets().SetLargeImage("audirvana");
    this->core->ActivityManager().UpdateActivity(activity, [](discord::Result result){});
}
discord::Result Application::RunCallbacks(){
    if(!this->core) return discord::Result::ServiceUnavailable;
    return this->core->RunCallbacks();
}
}
