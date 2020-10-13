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
    game = new Game();
    game->init("GKEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while(game->is_running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();
    return (0);
}