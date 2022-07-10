#pragma once

#include "Entity.h"
#include "EntityLife.h"
#include "TextureManager.h"

class Player : public Entity, public EntityLife
{
    int jumpVelocity;

    SDL_Texture *crouchTexLeft, *crouchTexRight, *playerTexLeft, *playerTexRight;

public:
    Player( const char *path, SDL_Rect src, SDL_Rect dest )
     : Entity( path, src, dest )
    {
        jumpVelocity = 40;

        crouchTexLeft  = TextureManager::LoadTexture( "assets\\playerCrouchLeft.png" );
        crouchTexRight = TextureManager::LoadTexture( "assets\\playerCrouchRight.png" );
        playerTexLeft  = TextureManager::LoadTexture( "assets\\playerLeft.png" );
        playerTexRight = TextureManager::LoadTexture( "assets\\playerRight.png" );
    }

    void Jump();

    void Crouch();
    void UnCrouch();

    void Turn();

    void SetMaxVelocity() { jumpVelocity = 40; }
    int GetVelocity() { return jumpVelocity; }

    bool isJump{ false };
    bool isCrouch{ false };
    bool isLeft{ false };
};