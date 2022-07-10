#pragma once

#include "Entity.h"

class Brick : public Entity
{
    int motionX;
    bool isLeft;

public:
    Brick( const char *path, SDL_Rect src, SDL_Rect dest )
     : Entity( path, src, dest )
    {
        isLeft = false;
        motionX = 0;
    }

    void Motion();
};