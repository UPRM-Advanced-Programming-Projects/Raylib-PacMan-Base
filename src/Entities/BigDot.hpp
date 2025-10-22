#pragma once

#include "Entity.hpp"

class BigDot: public Entity{
    public:
        BigDot(float x, float y, float width, float height, Image spriteSheet) : Entity(x, y, width, height) {
            this->sprite = ImageFromImage(spriteSheet, (Rectangle){643, 18, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }
};