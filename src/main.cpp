/**
 *  Lucerne - A Tutorial of SDL2, done by Goutham Krishna K V
 *  THIS PROJECT IS LICENSED USING MIT License,
 *  AND NO WARRANTIES OF SORT HOLDS OTHER THAN THE ONES
 *  THE LICENSE DESCRIBES.
 *  If not recieved, assume this project to include the MIT License
*/
#include <iostream>
#include <logger/Logger.hpp>

// Include the Game Header
#include "Game.hpp"

// maybe we'll use it somewhere. Keep it for now
#define PROJECT_NAME "com.github.gauthamkrishna9991.lucerne"

// Game Object
Game *game = nullptr;

int main
(
    // int argc,
    // char **argv
) {
    logger::Logger mainlogger = logger::Logger("main");
    mainlogger.Debug("Initializing Application");
    // this is for limiting framerate
    const int FPS = 60;
    // framedelay does almost the same thing
    const int frameDelay = 1000 / FPS;
    // frame start ticks
    Uint32 frameStart;
    // how much time a frame takes
    int frameTime;
    
    // create a game
    mainlogger.Debug("Initializing Game");
    game = new Game();
    // window with name, positions and full screen status
    game->init("GKEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    // while the game is running, limit it's framerates
    while(game->is_running()) {
        // get the ticks for start frame
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        // frame time to reach the end
        frameTime = SDL_GetTicks() - frameStart;
        //  to make sure the game runs at 60fps
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    // clean everything after exiting the game
    game->clean();
    // return a zero value
    mainlogger.Debug("App Closing");
    return (0);
}