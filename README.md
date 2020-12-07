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
