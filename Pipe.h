#pragma once

#include "Entity.h"

class Pipe : public Entity
{

public:
    Pipe( const char *path, SDL_Rect src, SDL_Rect dest )
     : Entity( path, src, dest )
    {
    }
};