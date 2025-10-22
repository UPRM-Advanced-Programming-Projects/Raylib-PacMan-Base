#pragma once

#include "raylib.h"

enum DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Entity {
    protected:
        float x, y, width, height;
        int ticks = 0;
    
    public:
        bool remove = false;
        Image sprite;
        Texture2D entityTexture;

        explicit Entity(float x, float y, float width, float height) {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }

        virtual void tick();
        virtual void render();

        void damage(Entity* damageSource);
        bool collision(Entity* entity);
        
        float getXDot() { return this->x; }
        float getYDot() { return this->y; }
        Rectangle getBounds();
        Rectangle getBounds(float x, float y);

        virtual ~Entity();
};