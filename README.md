#  AudirvanaDiscordRPC

Audirvana music player Discord Rich Presence support, for macOS.

## Build instruction

- Put `discord_game_sdk.dylib` in `AudirvanaDiscordRPC/`

- Copy C++ headers into `AudirvanaDiscordRPC/discord`

- Build with Xcode

## Installation

- Copy `discord_game_sdk.dylib` into `Audirvana.app/Contents/Frameworks`

- Copy built `libAudirvanaDiscordRPC.dylib` into `Audirvana.app/Contents/MacOS`

- Insert `libAudirvanaDiscordRPC.dylib` into `Audirvana.app/Contents/MacOS/Audirvana` binary.
    
    - This could be done using [Tyilo's insert_dylib](https://github.com/Tyilo/insert_dylib)
    
    - This process will cause Media Keys stopped working by removing code signature. To resolve this, go to System Preferences/Privacy/Accessibility remove and add Audirvana back.
    
    - Because this process added an library reference (`LC_ADD_DYLIB`) to the executable, please do not remove the dylibs from the original place, or it will cause Audirvana to crash

