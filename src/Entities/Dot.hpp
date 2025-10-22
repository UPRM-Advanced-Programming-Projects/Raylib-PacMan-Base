#pragma once

#include "Entity.hpp"

class Dot: public Entity{
    public:
        Dot(float x, float y, float width, float height, Image spriteSheet) : Entity(x, y, width, height) {
            this->sprite = ImageFromImage(spriteSheet, (Rectangle){623, 18, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }
};