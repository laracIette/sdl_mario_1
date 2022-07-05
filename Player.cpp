#include "Player.h"
#include "Global.h"


void Player::Jump()
{

    MoveEntityY( -jumpVelocity-- );

    if( jumpVelocity < 0 ) isJump = false;

}

void Player::Crouch()
{
    if( isLeft ) ChangeEntityTexture( crouchTexLeft );
    else         ChangeEntityTexture( crouchTexRight );
}

void Player::UnCrouch()
{
    if( isLeft ) ChangeEntityTexture( playerTexLeft );
    else         ChangeEntityTexture( playerTexRight );
}

void Player::Turn()
{
    if( isCrouch ) Crouch();

    else if( isLeft ) ChangeEntityTexture( playerTexLeft );
    else              ChangeEntityTexture( playerTexRight );
}