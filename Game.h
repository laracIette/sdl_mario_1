#pragma once

#include <SDL.h>

class Game
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

    bool keyPressed[KEYS];

    bool isMoveLeftPossible{ true };
    bool isMoveRightPossible{ true };
    bool isMoveUpPossible{ true };
    bool isMoveDownPossible{ true };


public:
    Game();
    ~Game();

    void Init( const char *title, int moveX, int moveY, bool fullscreen );

    void HandleEvents();

    void Update();
    void Render();
    void Clean();

    void MoveLeft();
    void MoveRight();
    void CheckMapPosX();

    bool Running() { return isRunning; }

	static SDL_Renderer *renderer;

    void CheckCollisions();
    void CheckObjectsCollisions();
    void CheckGroundCollisions();

};
