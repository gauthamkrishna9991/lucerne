#include <iostream>

// include game header
#include "Game.hpp"

// maybe we'll use it somewhere. Keep it for now
#define PROJECT_NAME "com.github.gauthamkrishna9991.lucerne"

// game object
Game *game = nullptr;

int main
(
    // int argc,
    // char **argv
) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("GKEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while(game->is_running()) {
        // get the ticks for start frame
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        // frame time to reach the end
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    game->clean();
    return (0);
}