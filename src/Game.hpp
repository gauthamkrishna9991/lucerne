# pragma once

#ifndef Game_HPP
#define Game_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
// import logger from the logger library
#include <logger/Logger.hpp>

class Game {
private:
    logger::Logger logger;
public:
    // constructor for game class
    Game();
    // destructor for game class
    ~Game();

    // method to initialize screen
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    // handle events
    void handleEvents();
    // update functionl
    void update();
    // render function
    void render();
    // clean
    void clean();
    // is running
    bool is_running() {
        return isRunning;
    }
private:
    // count
    int cnt = 0;
    // semaphore for running
    bool isRunning;
    // window object
    SDL_Window *window;
    // renderer object
    SDL_Renderer *renderer;

};
#endif
