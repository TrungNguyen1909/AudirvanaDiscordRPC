//
//  main.m
//  AudirvanaDiscordRPC
//
//  Created by Trung Nguyễn on 7/12/20.
//  Copyright © 2020 Trung Nguyễn. All rights reserved.
//

#import <Foundation/Foundation.h>

__attribute__((constructor))
void constructor(){
    NSLog(@"Initalizing Audirvana Discord RPC");
    unsetenv("DYLD_INSERT_LIBRARIES");
}
