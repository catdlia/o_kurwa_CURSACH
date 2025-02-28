// src/main.cpp
#include "Game.h"

int main(int argc, char* argv[]) {
    Game game;

    if (!game.Init("Geometric Arena", 800, 600)) {
        return -1;
    }

    game.Run();

    game.CleanUp();

    return 0;
}
