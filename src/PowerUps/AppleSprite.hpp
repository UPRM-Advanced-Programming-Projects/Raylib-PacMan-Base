#pragma once

#include "Entity.hpp"

class Apple : public Entity {
    public:
        Apple(float x, float y, float width, float height, Image spriteSheet) : Entity(x, y, width, height) {
            this->sprite = ImageFromImage(spriteSheet, (Rectangle){536, 49, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }
};