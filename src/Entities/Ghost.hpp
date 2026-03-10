#pragma once

#include "EntityManager.hpp"
#include "Animation.hpp"

class Ghost : public Entity {
    private: 
        int speed = 2;
        int killableCounter = 300;
        bool killable = false;
        bool canMove = true;
        bool justSpawned = true;
        DIRECTION dir = UP;
        EntityManager* manager;
        Animation* killAnimation;
        int delay;

        void checkCollisions();

    public:
        Ghost(float x, float y, float width, float height, EntityManager* manager, std::string color) : Entity(x, y, width, height) {
            this->manager = manager;

            std::vector<Rectangle> killFrames;
            Rectangle subImage;
            subImage = Rectangle { 584, 64, 16, 16 };
            killFrames.push_back(subImage);

            subImage = Rectangle { 600, 64, 16, 16 };
            killFrames.push_back(subImage);

            subImage = Rectangle { 616, 64, 16, 16 };
            killFrames.push_back(subImage);

            subImage = Rectangle { 632, 64, 16, 16 };
            killFrames.push_back(subImage);

            this->killAnimation = new Animation(10, killFrames);

            if (color == "red")     this->textureBounds = Rectangle { 456, 64, 16, 16 };
            if (color == "pink")    this->textureBounds = Rectangle { 456, 79, 16, 16 };
            if (color == "cyan")    this->textureBounds = Rectangle { 456, 96, 16, 16 };
            if (color == "orange")  this->textureBounds = Rectangle { 456, 113, 16, 16 };
        }

        void update() override;
        void draw() override;

        bool getKillable() { return this->killable; }
        void setKillable(bool killable) { 
            this->killable = killable;
            this->killableCounter = 300; 
        }

        void setDelay(int delay) {this->delay = delay; }

        ~Ghost() { delete this->killAnimation; }
};