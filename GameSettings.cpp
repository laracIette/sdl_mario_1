#include "GameSettings.h"
#include "Global.h"
#include "Entity.h"

SDL_Renderer *GameSettings::renderer = nullptr;

GameSettings::GameSettings( const char *title, int moveX, int moveY, bool fullscreen )
{
    int flags{0};
    if( fullscreen )
    {
        flags = SDL_WINDOW_FULLSCREEN;
        WIDTH = 1920;
        HEIGHT = 1080;
    }

    if( !SDL_Init( SDL_INIT_EVERYTHING ) );
    {
        window = SDL_CreateWindow( title, moveX, moveY, WIDTH, HEIGHT, flags );
        renderer = SDL_CreateRenderer( window, -1, 0 );
        if( renderer )
        {
            SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
        }

        isRunning = true;
    }
}

void GameSettings::HandleEvents()
{

    SDL_Event event;
    while( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                for( int i{ 0 }; i < KEYS; ++i )
                {
                    if( event.key.keysym.sym != keyCode[i] ) continue;

                    keyPressed[i] = true;
                }
                break;

            case SDL_KEYUP:
                for( int i{ 0 }; i < KEYS; ++i )
                {
                    if( event.key.keysym.sym != keyCode[i] ) continue;

                    keyPressed[i] = false;
                }
                break;

            default:
                break;
        }
    }

}

void GameSettings::Render()
{
    SDL_RenderClear( renderer );


    map1->DrawEntity();
    map2->DrawEntity();
    player->DrawEntity();
    //monster->DrawEntity();

    for( Entity *object : objects )
    {
        object->DrawEntity();
    }

    SDL_RenderPresent( renderer );
}

void GameSettings::Clean()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
}
