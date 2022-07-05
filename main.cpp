#include "Game.h"
#include "Global.h"

Game *game = nullptr;

int WIDTH{ 1280 };
int HEIGHT{ 720 };

int main( int argc, char *argv[] )
{

    const int frameDelay{ 1000 / FPS };

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->Init( "Windoz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false );

    while( game->Running() )
    {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if( frameDelay > frameTime )
        {
            SDL_Delay( frameDelay - frameTime );
        }
    }

    game->Clean();


    return 0;

}