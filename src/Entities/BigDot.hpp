#pragma once

#include "Entity.hpp"

class BigDot: public Entity{
    public:
        BigDot(float x, float y, float width, float height) : Entity(x, y, width, height) {
            this->textureBounds = Rectangle { 643, 18, 16, 16 };
        }
};