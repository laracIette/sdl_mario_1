#include "TextureManager.h"
#include "Game.h"
#include "Global.h"

SDL_Texture *TextureManager::LoadTexture( const char *path )
{
    SDL_Surface *tempSurface{ IMG_Load( path ) };
    SDL_Texture *tex{ SDL_CreateTextureFromSurface( Game::renderer, tempSurface ) };
    SDL_FreeSurface( tempSurface );

    return tex;
}

void TextureManager::DrawTexture( SDL_Texture *tex, SDL_Rect src, SDL_Rect dest )
{
    if( ((dest.x + dest.w) < 0) || (dest.x > WIDTH)
     || ((dest.y + dest.h) < 0) || (dest.y > HEIGHT) ) return;

    SDL_RenderCopy( Game::renderer, tex, &src, &dest );
}
