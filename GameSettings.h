#pragma once

#include <SDL.h>
#include <vector>

#include "Map.h"
#include "Pipe.h"
#include "Brick.h"
#include "Player.h"
#include "Entity.h"

class GameSettings
{
    bool isRunning{ false };
    SDL_Window *window;

    static const int KEYS{ 4 };

    SDL_KeyCode keyCode[KEYS]{
        SDLK_LEFT,
        SDLK_RIGHT,
        SDLK_SPACE,
        SDLK_LCTRL
    };


public:
    GameSettings( const char *title, int moveX, int moveY, bool fullscreen );
    GameSettings() {}
    ~GameSettings() {}

    static SDL_Renderer *renderer;

    Map *map1;
    Map *map2;
    Player *player;
    //Monster *monster;
    std::vector<Entity *> objects;

    void HandleEvents();

    void Render();
    void Clean();

    bool keyPressed[KEYS];

    bool Running() { return isRunning; }
};