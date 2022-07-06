#include "Entity.h"
#include "TextureManager.h"
#include "Global.h"


Entity::Entity( const char *path, SDL_Rect src, SDL_Rect dest )
{
    tex = TextureManager::LoadTexture( path );
    if( !tex )
    {
        std::cout << "Error creating '" << path << "'.\n" << SDL_GetError() << std::endl;
    }


    this->src = src;
    this->dest = dest;

    moveX = this->dest.x;
    moveY = this->dest.y;

}


void Entity::DrawEntity()
{
    dest.x = moveX;
    dest.y = moveY;
    TextureManager::DrawTexture( tex, src, dest );
}

void Entity::MoveEntityX( float X )
{
    moveX += (X * 60/FPS);
}

void Entity::MoveEntityY( float Y )
{
    moveY += (Y * FPS/60);
}

void Entity::ChangeEntityTexture(SDL_Texture *tex)
{
    this->tex = tex;
}
