// src/Menu.cpp
#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Renderer* renderer)
    : renderer(renderer), font(nullptr), selectedItemIndex(0) {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "TTF Initialization Failed: " << TTF_GetError() << std::endl;
    }

    // Load font
    font = TTF_OpenFont("assets/fonts/arial.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    normalColor = { 255, 255, 255, 255 };   // White
    selectedColor = { 255, 105, 180, 255 }; // Pink

    // Define menu items
    menuItems = {
        { "Start Game", { 0, 0, 0, 0 }, false },
        { "Options", { 0, 0, 0, 0 }, false },
        { "Exit", { 0, 0, 0, 0 }, false }
    };
}

Menu::~Menu() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    TTF_Quit();
}

void Menu::HandleInput(const SDL_Event& event, GameState& gameState) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            selectedItemIndex = (selectedItemIndex - 1 + menuItems.size()) % menuItems.size();
            break;
        case SDLK_DOWN:
            selectedItemIndex = (selectedItemIndex + 1) % menuItems.size();
            break;
        case SDLK_RETURN:
        case SDLK_KP_ENTER:
            if (menuItems[selectedItemIndex].text == "Start Game") {
                gameState = GameState::PLAYING;
            }
            else if (menuItems[selectedItemIndex].text == "Options") {
                // Handle options
            }
            else if (menuItems[selectedItemIndex].text == "Exit") {
                gameState = GameState::EXIT;
            }
            break;
        default:
            break;
        }
    }
}

void Menu::Update() {
    // Update menu items if necessary
}

void Menu::Render() {
    int screenWidth = SCREEN_WIDTH;
    int screenHeight = SCREEN_HEIGHT;

    int menuItemHeight = 50;
    int startY = (screenHeight - menuItems.size() * menuItemHeight) / 2;

    for (size_t i = 0; i < menuItems.size(); ++i) {
        MenuItem& item = menuItems[i];
        item.isSelected = (i == selectedItemIndex);
        SDL_Color color = item.isSelected ? selectedColor : normalColor;

        RenderText(item.text, screenWidth / 2, startY + i * menuItemHeight, color);
    }
}

void Menu::RenderText(const std::string& message, int x, int y, SDL_Color color) {
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Blended(font, message.c_str(), color);
    if (!surface) {
        std::cerr << "Text Render Failed: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Create Texture Failed: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect dstRect;
    dstRect.x = x - surface->w / 2;
    dstRect.y = y;
    dstRect.w = surface->w;
    dstRect.h = surface->h;

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
