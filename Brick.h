#pragma once

#include "Entity.h"

class Brick : public Entity
{
    int motionX{ 0 };
    bool isLeft{ false };

public:
    using Entity::Entity;

    void Motion();
};