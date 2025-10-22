#pragma once

#include "Entity.hpp"

class BoundBlock: public Entity {
    public:
        BoundBlock(float x, float y, float width, float height, Image sprite) : Entity(x, y, width, height) {
            this->sprite = sprite;
            this->entityTexture = LoadTextureFromImage(this->sprite);
        }

        ~BoundBlock() {}
};