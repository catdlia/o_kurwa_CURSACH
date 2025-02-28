// src/Game.cpp
#include "Game.h"
#include <iostream>

Game::Game()
    : isRunning(false), window(nullptr), renderer(nullptr),
    player(nullptr), map(nullptr) {
}

Game::~Game() {
    CleanUp();
}

bool Game::Init(const std::string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "SDL Initialization Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window Creation Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Renderer Creation Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize game entities.
    player = new Player(renderer);
    map = new Map(renderer);

    // Create enemies based on map and game design.
    enemies.push_back(new Enemy(renderer, 300, 300));
    enemies.push_back(new Enemy(renderer, 500, 200));

    isRunning = true;
    return true;
}

void Game::Run() {
    while (isRunning) {
        HandleEvents();
        Update();
        Render();
        SDL_Delay(16); // Approx ~60 FPS
    }
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // Handle player input.
        if (player) {
            player->HandleInput(event);
        }
    }
}

void Game::Update() {
    // Update game logic.
    if (player) {
        player->Update();
    }

    for (auto& enemy : enemies) {
        enemy->Update();
    }

    if (map) {
        map->Update();
    }
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Dark gray background
    SDL_RenderClear(renderer);

    if (map) {
        map->Render();
    }

    if (player) {
        player->Render();
    }

    for (auto& enemy : enemies) {
        enemy->Render();
    }

    SDL_RenderPresent(renderer);
}

void Game::CleanUp() {
    for (auto& enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    if (player) {
        delete player;
        player = nullptr;
    }

    if (map) {
        delete map;
        map = nullptr;
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}
