//
//  main.cpp
//  SDL_REAL
//
//  Created by ShiLin on 12/31/16.
//  Copyright © 2016 lin. All rights reserved.
//

#include <iostream>
#include "Core.hpp"
#include "Config.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Config *config = new Config(1280, 720);
    
    SCore *Core = new SCore(config -> GetMainWindowWidth(), config -> GetMainWindowHeight());
    
    Core->StartMainLoop();
    
    
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
