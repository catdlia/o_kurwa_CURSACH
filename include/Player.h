// include/Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Constants.h"

class Player {
public:
    Player(SDL_Renderer* renderer);
    ~Player();

    void HandleInput(const SDL_Event& event);
    void Update();
    void Render();

private:
    SDL_Renderer* renderer;
    SDL_Rect position;
    int speed;
    int level;
    int GDL; // Global Difficulty Level
    // Other attributes like strength, speed, endurance, mana.
};

#endif // PLAYER_H
