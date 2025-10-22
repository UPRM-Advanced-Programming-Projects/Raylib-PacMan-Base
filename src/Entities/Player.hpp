#pragma once 

#include "Animation.hpp"
#include "EntityManager.hpp"
#include "StrawberryPowerUp.hpp"
#include "CherryPowerUp.hpp"
#include "ApplePowerUp.hpp"
#include "ScoreParticle.hpp"

enum MOVEMENT {
    MUP,
    MDOWN,
    MLEFT,
    MRIGHT
};
class Player : public Entity {
    private:
        float spawnX, spawnY;
        unsigned int health = 3;
        const unsigned int MaxHealth = 3;
        int score = 0;
        Sound chomp, eatFruit, eatGhost; 

        int speed = 4;
        bool moving = false;
        bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;
        MOVEMENT movement;
        DIRECTION dir = DOWN;
        Image up, down, left, right;
        Texture2D texUp, texDown, texLeft, texRight;

        Animation* walkUp;
        Animation* walkDown;
        Animation* walkLeft;
        Animation* walkRight;

        EntityManager* manager;

        StrawberryPowerUp* powStraw;
        CherryPowerUp* powCherry;
        ApplePowerUp* powApple;
        bool used = false;

    public:
        std::vector<ScoreParticle*> particles;
        std::vector<std::string> powName;
        int strawCounter = 0;
        int appleCounter = 0;

        Player(float x, float y, float width, float height, EntityManager* manager, Image spriteSheet);

        int getHealth();
        int getScore();
        DIRECTION getDirection();
        void setHealth(int hp);
        void setScore(int score);
        void setFacing(DIRECTION dir);

        void tick();
        void render();

        void keyPressed(int key);
        void keyReleased(int key);

        void checkCollisions();
        void die();

        ~Player();
};