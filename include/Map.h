// include/Map.h
#ifndef MAP_H
#define MAP_H

#include <SDL3/SDL.h>

class Map {
public:
    Map(SDL_Renderer* renderer);
    ~Map();

    void Update();
    void Render();

private:
    SDL_Renderer* renderer;
    // Data structures for map representation (e.g., polygons).
};

#endif // MAP_H
