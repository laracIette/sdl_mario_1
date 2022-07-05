#pragma once

#include "Entity.h"
#include "EntityLife.h"
#include "TextureManager.h"

class Player : public Entity, public EntityLife
{
    int jumpVelocity{ 40 };

    SDL_Texture *crouchTexLeft{
        TextureManager::LoadTexture( "assets\\playerCrouchLeft.png" )
    };
    SDL_Texture *crouchTexRight{
        TextureManager::LoadTexture( "assets\\playerCrouchRight.png" )
    };

    SDL_Texture *playerTexLeft{
        TextureManager::LoadTexture( "assets\\playerLeft.png" )
    };
    SDL_Texture *playerTexRight{
        TextureManager::LoadTexture( "assets\\playerRight.png" )
    };

public:
    using Entity::Entity;

    void Jump();

    void Crouch();
    void UnCrouch();

    void Turn();

    void SetMaxVelocity() { jumpVelocity = 40; }
    int GetVelocity() { return jumpVelocity; }

    bool isJump = false;
    bool isCrouch = false;
    bool isLeft = false;
};