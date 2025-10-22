#pragma once

#include "Entity.hpp"

class Strawberry : public Entity {
    public: 
        Strawberry(float x, float y, float width, float height, Image spriteSheet) : Entity(x, y, width, height) {
            this->sprite = ImageFromImage(spriteSheet, (Rectangle){504, 49, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }
};