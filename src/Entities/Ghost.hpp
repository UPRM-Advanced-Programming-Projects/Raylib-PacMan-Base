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

        void checkCollisions();

    public:
        Ghost(float x, float y, float width, float height, Image spriteSheet, EntityManager* manager, std::string color) : Entity(x, y, width, height) {
            this->manager = manager;

            std::vector<Texture2D> killFrames;
            Image temp;
            temp = ImageFromImage(spriteSheet, (Rectangle){584, 64, 16, 16});
            killFrames.push_back(LoadTextureFromImage(temp));
            temp = ImageFromImage(spriteSheet, (Rectangle){600, 64, 16, 16});
            killFrames.push_back(LoadTextureFromImage(temp));
            temp = ImageFromImage(spriteSheet, (Rectangle){616, 64, 16, 16});
            killFrames.push_back(LoadTextureFromImage(temp));
            temp = ImageFromImage(spriteSheet, (Rectangle){632, 64, 16, 16});
            killFrames.push_back(LoadTextureFromImage(temp));

            this->killAnimation = new Animation(10, killFrames);

            if (color == "red")     this->sprite = ImageFromImage(spriteSheet, (Rectangle){456, 64, 16, 16});
            if (color == "pink")    this->sprite = ImageFromImage(spriteSheet, (Rectangle){456, 79, 16, 16});
            if (color == "cyan")    this->sprite = ImageFromImage(spriteSheet, (Rectangle){456, 96, 16, 16});
            if (color == "orange")  this->sprite = ImageFromImage(spriteSheet, (Rectangle){456, 113, 16, 16});
            this->entityTexture = LoadTextureFromImage(this->sprite);
            
        }

        void tick();
        void render();

        bool getKillable() { return this->killable; }
        void setKillable(bool killable) { 
            this->killable = killable;
            this->killableCounter = 300; 
        }

        ~Ghost() { delete this->killAnimation; }
};