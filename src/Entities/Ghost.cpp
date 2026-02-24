#include "Ghost.hpp"
#include "BoundBlock.hpp"

void Ghost::update() {

    if (this->killable) {
        this->killableCounter--;
        this->speed = 1;
        if (this->killableCounter <= 0) {
            this->killable = false;
            this->killableCounter = 300;
            this->speed = 2;
        }
    }

    this->killAnimation->update();
    this->canMove = true;
    checkCollisions();

    if (this->canMove) {

        switch (this->dir) {
            case UP:
                this->y -= this->speed;
                break;

            case DOWN:
                this->y += this->speed;
                break;

            case LEFT:
                this->x -= this->speed;
                break;

            case RIGHT:
                this->x += this->speed;
                break;

            default:
                break;
        }

    } else {
        int randInt;
        if (this->justSpawned) {
            this->dir = UP;
        } else {
            randInt = GetRandomValue(0, 4);
        }

        switch (randInt) {
            case 0:
                this->dir = LEFT;
                break;

            case 1:
                this->dir = RIGHT;
                break;

            case 2:
                this->dir = DOWN;
                break;

            case 3:
                this->dir = UP;
                break;
                
            default:
                break;
        }

        this->justSpawned = false;
    }
}

void Ghost::draw() {
    if (this->killable) {
        DrawTexturePro(ImageManager::spriteSheet, this->killAnimation->getCurrentFrame(), Rectangle { this->x, this->y, this->width, this->height },
                       Vector2 {0, 0}, 0, WHITE);
    } else {
        Entity::draw();
    }
}

void Ghost::checkCollisions() {
    for (BoundBlock* block : this->manager->boundBlocks) {
       switch (this->dir) {
            case UP:
                if (CheckCollisionRecs(this->getBounds(this->x, this->y - this->speed), block->getBounds())) {
                    this->canMove = false;
                }

                break;

            case DOWN:
                if (CheckCollisionRecs(this->getBounds(this->x, this->y + this->speed), block->getBounds())) {
                    this->canMove = false;
                }

                break;

            case LEFT:
                if (CheckCollisionRecs(this->getBounds(this->x - this->speed, this->y), block->getBounds())) {
                    this->canMove = false;
                }

                break;

            case RIGHT:
                if (CheckCollisionRecs(this->getBounds(this->x + this->speed, this->y), block->getBounds())) {
                    this->canMove = false;
                }

                break;

            default:
                break;
        }
    }
}