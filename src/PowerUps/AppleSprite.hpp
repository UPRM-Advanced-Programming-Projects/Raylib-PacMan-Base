#pragma once

#include "Entity.hpp"

class Apple : public Entity {
    public:
        Apple(float x, float y, float width, float height) : Entity(x, y, width, height) {
            this->textureBounds = Rectangle { 536, 49, 16, 16 };
        }
};