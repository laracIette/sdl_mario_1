#pragma once

#include "GameSettings.h"

class Game : public GameSettings
{
    bool isMoveLeftPossible;
    bool isMoveRightPossible;
    bool isMoveUpPossible;
    bool isMoveDownPossible;

public:
    Game( const char *title, int moveX, int moveY, bool fullscreen )
     : GameSettings( title, moveX, moveY, fullscreen )
    {
        isMoveLeftPossible = true;
        isMoveRightPossible = true;
        isMoveUpPossible = true;
        isMoveDownPossible = true;
    }
    Game() {}
    ~Game() {}

    void Init();
    void Update();

    void MoveLeft();
    void MoveRight();
    void CheckMapPosX();

    void CheckCollisions();
    void CheckObjectsCollisions();
    void CheckGroundCollisions();

};
