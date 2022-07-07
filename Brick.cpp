#include "Brick.h"

void Brick::Motion()
{
    if( !isLeft )
    {
        if( motionX++ >= 100 ) isLeft = true;

        MoveEntityX( 1 );
    }
    else
    {
        if( motionX-- <= 0 ) isLeft = false;

        MoveEntityX( -1 );
    }


}
