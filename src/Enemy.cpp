// src/Enemy.cpp
#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, int x, int y)
    : renderer(renderer), speed(3), strength(1) {
    position = { x, y, 40, 40 }; // Starting position and size.
}

Enemy::~Enemy() {}

void Enemy::Update() {
    // Implement simple AI logic for moving towards the player.
}

void Enemy::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // Green color.
    SDL_RenderFillRect(renderer, &position);
}
