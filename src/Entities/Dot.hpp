#pragma once

#include "Entity.hpp"

class Dot: public Entity{
    public:
        Dot(float x, float y, float width, float height) : Entity(x, y, width, height) {
            this->textureBounds = Rectangle { 623, 18, 16, 16 };
        }
};