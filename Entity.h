#pragma once

#include <SDL.h>

class Entity
{
    SDL_Texture *tex;
    SDL_Rect src, dest;

    float moveX;
    float moveY;

public:
    Entity( const char *path, SDL_Rect src, SDL_Rect dest );
    Entity();
    ~Entity();

    void DrawEntity();
    void MoveEntityX( float X );
    void MoveEntityY( float Y );

    void SetPosX( float X ) { moveX = X; }
    void SetPosY( float Y ) { moveY = Y; }

    void ChangeEntityTexture( SDL_Texture *tex );

    int X() { return moveX; }
    int Y() { return moveY; }
    int W() { return dest.w; }
    int H() { return dest.h; }
};