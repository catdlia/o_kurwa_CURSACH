// include/Game.h
#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

class Game {
public:
    Game();
    ~Game();

    bool Init(const std::string& title, int width, int height);
    void Run();
    void CleanUp();

private:
    void HandleEvents();
    void Update();
    void Render();

    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Player* player;
    std::vector<Enemy*> enemies;
    Map* map;
};

#endif // GAME_H
