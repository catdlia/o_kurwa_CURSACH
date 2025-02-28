// src/Player.cpp
#include "Player.h"

Player::Player(SDL_Renderer* renderer)
    : renderer(renderer), speed(5), level(1), GDL(1) {
    position = { 100, 100, 50, 50 }; // Starting position and size.
}

Player::~Player() {}

void Player::HandleInput(const SDL_Event& event) {
    // Handle keyboard events.
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_w:
            position.y -= speed;
            break;
        case SDLK_s:
            position.y += speed;
            break;
        case SDLK_a:
            position.x -= speed;
            break;
        case SDLK_d:
            position.x += speed;
            break;
        default:
            break;
        }
    }
}

void Player::Update() {
    // Update player state.
}

void Player::Render() {
    SDL_SetRenderDrawColor(renderer, 255, 105, 180, 255); // Pink color.
    SDL_RenderFillRect(renderer, &position);
}
