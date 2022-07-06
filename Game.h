#pragma once

#include "GameSettings.h"

class Game : public GameSettings
{
    bool isMoveLeftPossible{ true };
    bool isMoveRightPossible{ true };
    bool isMoveUpPossible{ true };
    bool isMoveDownPossible{ true };

public:
    using GameSettings::GameSettings;
    Game();
    ~Game();

    void Init();
    void Update();

    void MoveLeft();
    void MoveRight();
    void CheckMapPosX();

    void CheckCollisions();
    void CheckObjectsCollisions();
    void CheckGroundCollisions();

};
