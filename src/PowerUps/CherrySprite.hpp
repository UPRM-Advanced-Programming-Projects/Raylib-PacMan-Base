#pragma once

#include "Entity.hpp"

class Cherry : public Entity {
    public: 
        Cherry(float x, float y, float width, float height, Image spriteSheet) : Entity(x, y, width, height) {
            this->sprite = ImageFromImage(spriteSheet, (Rectangle){489, 49, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }
};