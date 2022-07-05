#pragma once

#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture( const char *path );
    static void DrawTexture( SDL_Texture *tex, SDL_Rect src, SDL_Rect dest );
};