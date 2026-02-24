#pragma once

#include "raylib.h"
#include "ImageManager.hpp"
#include "SoundManager.hpp"

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
        Rectangle textureBounds;

    public:
        bool remove = false;

        explicit Entity(float x, float y, float width, float height) {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }

        virtual void update();
        virtual void draw();

        void damage(Entity* damageSource);
        bool collision(Entity* entity);
        
        float getXDot() { return this->x; }
        float getYDot() { return this->y; }
        Rectangle getBounds();
        Rectangle getBounds(float x, float y);

        virtual ~Entity();
};