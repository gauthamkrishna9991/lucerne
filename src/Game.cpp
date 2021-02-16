
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

SDL_Texture *playerTex;

SDL_Rect srcR, destR;

GameObject *player, *enemy;

Game::Game() {
    this->logger = logger::Logger("Game");
}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    // default if fullscreen flag is not set
    int FLAGS = SDL_WINDOW_SHOWN;
    // if fullscreen flag is set
    if (fullscreen) {
        this->logger.Debug("Check if window is full-screen");
        // change flag to enable fullscreen
        FLAGS = SDL_WINDOW_FULLSCREEN;
    }
    // Try to initialize and see if it works
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        this->logger.Debug("Subsystems Initialized");
        window = SDL_CreateWindow(title, xpos, ypos, width, height, FLAGS);
        // if window exists
        if (window) {
            // window does not return null
            this->logger.Info("Window Created");
        } else {
            // if window returns null game can't be started. Exit gracefully.
            this->logger.Error("Error showing window: " + std::string(SDL_GetError()));
            SDL_Quit();
            // if unable to create a window, exit with 1
            exit(1);
        }
        // renderer to render characters, objects etc.
        // we'll push it to the window when render is over.
        renderer = SDL_CreateRenderer(window, -1, 0);
        // if renderer exists
        if (renderer) {
            // set render color as white for now
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
            this->logger.Info("Renderer Created.");
        } else {
            // if not created, send error
            this->logger.Error("Error creating renderer: " + std::string(SDL_GetError()));
            // clean up all data
            SDL_Quit();
            // exit with 2
            exit(2);
        }
        // this will make it running
        isRunning = true;
    } else {
        // this will stop making it run
        isRunning = false;
    }
    // Get player and enemy game object
    player = new GameObject("assets/player.png", renderer, 0, 0);
    enemy = new GameObject("assets/enemy.png", renderer, 60, 60);
}

// handling events: incomplete
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
    this->logger.Info("Game Cleaned");
}