// include/Menu.h
#ifndef MENU_H
#define MENU_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <vector>
#include "Constants.h"

struct MenuItem {
    std::string text;
    SDL_Rect rect;
    bool isSelected;
};

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    ~Menu();

    void HandleInput(const SDL_Event& event, GameState& gameState);
    void Update();
    void Render();

private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color normalColor;
    SDL_Color selectedColor;

    std::vector<MenuItem> menuItems;
    int selectedItemIndex;

    void RenderText(const std::string& message, int x, int y, SDL_Color color);
};

#endif // MENU_H
