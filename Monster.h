#pragma once

#include "Entity.h"

class Monster : public Entity
{
public:
    Monster( const char *path, SDL_Rect src, SDL_Rect dest )
     : Entity( path, src, dest )
    {
    }
};