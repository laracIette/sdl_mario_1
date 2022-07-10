#pragma once

#include "Entity.h"

class Map : public Entity
{

public:
    Map( const char *path, SDL_Rect src, SDL_Rect dest )
     : Entity( path, src, dest )
    {
    }
};