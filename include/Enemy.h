// include/Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <SDL3/SDL.h>

class Enemy {
public:
    Enemy(SDL_Renderer* renderer, int x, int y);
    ~Enemy();

    void Update();
    void Render();

private:
    SDL_Renderer* renderer;
    SDL_Rect position;
    int speed;
    int strength;
    // Other attributes based on GDL and level.
};

#endif // ENEMY_H
