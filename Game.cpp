#include "Game.h"
#include "Map.h"
#include "Global.h"
#include "Player.h"
#include "Monster.h"
#include "Entity.h"
#include "Pipe.h"
#include "Brick.h"

#include <vector>

void Game::Init()
{
    map1 = new Map( "assets\\map1.png", {0, 0, 1920, 1080}, {0, 0, WIDTH, HEIGHT} );
    map2 = new Map( "assets\\map2.png", {0, 0, 1920, 1080}, {WIDTH, 0, WIDTH, HEIGHT} );
    player = new Player( "assets\\playerRight.png", {0, 0, 185, 185}, {600, 522, 100, 100} );
    //monster = new Monster( "assets\\monster.png", {0, 0, 20, 20}, {400, 200, 20, 20} );
    objects.push_back( new Pipe( "assets\\pipe.png", {0, 0, 322, 322}, {1047, 462, 161, 161} ) );
    objects.push_back( new Brick( "assets\\brick.png", {0, 0, 400, 400}, {300, 200, 100, 100} ) );


}

void Game::Update()
{
    for( Entity *object : objects ) object->Motion();

    CheckCollisions();

    if( isMoveDownPossible ) player->MoveEntityY( 20 );
    else                     player->isJump = false;

    if( keyPressed[0] && isMoveLeftPossible )
    {
        MoveLeft();
    }
    if( keyPressed[1] && isMoveRightPossible )
    {
        MoveRight();
    }
    if( keyPressed[2] && !player->isJump )
    {
        player->isJump = true;
        player->SetMaxVelocity();
    }
    if( keyPressed[3] && !player->isCrouch )
    {
        player->isCrouch = true;
        player->Crouch();
    }

    CheckMapPosX();


    if( !keyPressed[2] && !player->isJump )
    {
        isMoveUpPossible = true;
    }
    if( !keyPressed[3] && player->isCrouch )
    {
        player->isCrouch = false;
        player->UnCrouch();
    }


    if( player->isJump && isMoveUpPossible )
    {
        player->Jump();
        if( !player->GetVelocity() ) isMoveUpPossible = false;
    }
}

void Game::MoveLeft()
{

    if( player->X() > WIDTH/3 )
    {
        player->MoveEntityX( -4 );
    }
    else
    {
        map1->MoveEntityX( 4 );
        map2->MoveEntityX( 4 );

        for( Entity *object : objects )
        {
            object->MoveEntityX( 4 );
        }
    }

    if( !player->isLeft )
    {    player->isLeft = true;

        player->Turn();
    }
}

void Game::MoveRight()
{
    if( player->X() < WIDTH/2 )
    {
        player->MoveEntityX( 4 );
    }
    else
    {
        map1->MoveEntityX( -4 );
        map2->MoveEntityX( -4 );

        for( Entity *object : objects )
        {
            object->MoveEntityX( -4 );
        }
    }

    if( player->isLeft )
    {   player->isLeft = false;

        player->Turn();
    }
}

void Game::CheckMapPosX()
{
    if( map1->X() >= WIDTH )
    {
        map1->SetPosX( -WIDTH );
    }
    else if( map2->X() >= WIDTH )
    {
        map2->SetPosX( -WIDTH );
    }
    else if( map1->X() <= -WIDTH )
    {
        map1->SetPosX( WIDTH );
    }
    else if( map2->X() <= -WIDTH )
    {
        map2->SetPosX( WIDTH );
    }
}

void Game::CheckCollisions()
{
    isMoveLeftPossible = true;
    isMoveRightPossible = true;
    isMoveDownPossible = true;

    CheckObjectsCollisions();
    CheckGroundCollisions();
}

void Game::CheckObjectsCollisions()
{
    for( Entity *object : objects )
    {

        if( (abs(player->X() - (object->X() + object->W())) <= 2)
         && ((player->Y() + player->H() + 20) > object->Y())
         && (player->Y() < (object->Y() + object->H())) )
        {
            isMoveLeftPossible = false;
        }

        else if( (abs(player->X() + player->W() - object->X()) <= 2)
         && ((player->Y() + player->H() + 20) > object->Y())
         && (player->Y() < (object->Y() + object->H())) )
        {
            isMoveRightPossible = false;
        }

        else if( (abs(player->X() - object->X()) <= object->W())
         && (abs((player->X() + player->W()) - (object->X() + object->W())) <= object->W())
         && (player->Y() < (object->Y() + object->H()))
         && (player->Y() > object->Y()) )
        {
            player->SetPosY( object->Y() + object->H() );
            isMoveUpPossible = false;
        }

        else if( (abs(player->X() - object->X()) <= object->W())
         && (abs((player->X() + player->W()) - (object->X() + object->W())) <= object->W())
         && ((player->Y() + player->H() + 20) > object->Y())
         && ((player->Y() + player->H()) < (object->Y() + object->H())) )
        {
            player->SetPosY( object->Y() - player->H() );
            isMoveDownPossible = false;
        }
    }
}

void Game::CheckGroundCollisions()
{
    if( (player->Y() + 20) > 522 )
    {
        player->SetPosY( 522 );
        isMoveDownPossible = false;
    }
}
