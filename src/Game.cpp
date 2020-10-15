
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

SDL_Texture *playerTex;

SDL_Rect srcR, destR;

GameObject *player, *enemy;

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
            // if unable to create a window, exit with 1
            exit(1);
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created." << std::endl;
        } else {
            std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
            //  if unable to create a renderer, exit with 1
            exit(2);
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    // Get player and enemy game object
    player = new GameObject("assets/player.png", renderer, 0, 0);
    enemy = new GameObject("assets/enemy.png", renderer, 60, 60);
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
    player->Update();
    enemy->Update();
}

void Game::render() {
    // clear stuff from renderer
    SDL_RenderClear(renderer);
    // this is where we add stuff to renderer
    player->Render();
    enemy->Render();
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