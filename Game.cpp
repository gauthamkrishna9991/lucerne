
#include "Game.hpp"

SDL_Texture *playerTex;

SDL_Rect srcR, destR;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int FLAGS = SDL_WINDOW_SHOWN;
    if (fullscreen) {
        FLAGS = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized " << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, FLAGS);

        if (window) {
            std::cout << "Window Created" << std::endl;
        } else {
            std::cout << "Error showing window: " << SDL_GetError() << std::endl;
            exit(1);
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created." << std::endl;
        } else {
            std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
            exit(2);
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    // create a temporary surface for player texture
    SDL_Surface *temp_surface = IMG_Load("assets/player.png");
    // get player texture
    playerTex = SDL_CreateTextureFromSurface(renderer,  temp_surface);

    // clean surface
    SDL_FreeSurface(temp_surface);
}


void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    cnt++;
    destR.h = 64;
    destR.w = 64;
    destR.x = cnt;
    std::cout << cnt << std::endl;
}

void Game::render() {
    // clear stuff from renderer
    SDL_RenderClear(renderer);
    // this is where we add stuff to renderer
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    // present render
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    // destroy the window
    SDL_DestroyWindow(window);
    // destroy thw renderer
    SDL_DestroyRenderer(renderer);
    // quit
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}