#pragma once

#include "Entity.hpp"

class BoundBlock: public Entity {
    private:
        Texture2D texture;

    public:
        BoundBlock(float x, float y, float width, float height, Image sprite) : Entity(x, y, width, height) {
            this->texture = LoadTextureFromImage(sprite);
        }

        void draw() override {
            DrawTexturePro(this->texture, Rectangle { 0, 0, (float)this->texture.width, (float)this->texture.height }, 
                           Rectangle { this->x, this->y, this->width, this->height }, Vector2 {0, 0}, 0, WHITE);
        }

        ~BoundBlock() {}
};