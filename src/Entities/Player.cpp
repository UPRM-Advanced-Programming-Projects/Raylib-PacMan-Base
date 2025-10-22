#pragma once

#include "Player.hpp"
#include "Dot.hpp"
#include "BigDot.hpp"
#include "Ghost.hpp"
#include "CherrySprite.hpp"
#include "StrawberrySprite.hpp"
#include "AppleSprite.hpp"

Player::Player(float x, float y, float width, float height, EntityManager* manager, Image spriteSheet) : Entity(x, y, width, height) {
    this->spawnX = x;
    this->spawnY = y;
    this->manager = manager;
    this->chomp = LoadSound("audio/pac_chomp.mp3");
    this->eatFruit = LoadSound("audio/EatFruit.mp3");
    this->eatGhost = LoadSound("audio/EatGhost.mp3");
    this->up = ImageFromImage(spriteSheet, (Rectangle){0, 48, 16, 16});
    this->down = ImageFromImage(spriteSheet, (Rectangle){0, 32, 16, 16});
    this->left = ImageFromImage(spriteSheet, (Rectangle){0, 16, 16, 16});
    this->right = ImageFromImage(spriteSheet, (Rectangle){0, 0, 16, 16});

    this->texDown = LoadTextureFromImage(this->down);
    this->texUp = LoadTextureFromImage(this->up);
    this->texLeft = LoadTextureFromImage(this->left);
    this->texRight = LoadTextureFromImage(this->right);

    std::vector<Texture2D> downAnimFrames;
    std::vector<Texture2D> upAnimFrames;
    std::vector<Texture2D> leftAnimFrames;
    std::vector<Texture2D> rightAnimFrames;
    Image temp;

    for(int i = 0; i < 3; i++){
        temp = ImageFromImage(spriteSheet, (Rectangle){(float)(i * 16), 48, 16, 16});
        downAnimFrames.push_back(LoadTextureFromImage(temp));
    }

    for(int i = 0; i < 3; i++){
        temp = ImageFromImage(spriteSheet, (Rectangle){(float)(i * 16), 32, 16, 16});
        upAnimFrames.push_back(LoadTextureFromImage(temp));
    }

    for(int i = 0; i < 3; i++){
        temp = ImageFromImage(spriteSheet, (Rectangle){(float)(i * 16), 16, 16, 16});
        leftAnimFrames.push_back(LoadTextureFromImage(temp));
    }

    for(int i = 0; i < 3; i++){
        temp = ImageFromImage(spriteSheet, (Rectangle){(float)(i * 16), 0, 16, 16});
        rightAnimFrames.push_back(LoadTextureFromImage(temp));
    }

    this->walkDown = new Animation(1, downAnimFrames);
    this->walkUp = new Animation(1, upAnimFrames);
    this->walkLeft = new Animation(1, leftAnimFrames);
    this->walkRight = new Animation(1, rightAnimFrames);

    this->powStraw = new StrawberryPowerUp();
    this->powCherry = new CherryPowerUp();
    this->powApple = new ApplePowerUp();
    this->powCherry->setManager(this->manager);

    this->movement = MLEFT;
}

int Player::getHealth() { return this->health; }
int Player::getScore() { return this->score; }
DIRECTION Player::getDirection() { return this->dir; };
void Player::setHealth(int hp) { this->health = hp; }
void Player::setScore(int score) { this->score = score; }
void Player::setFacing(DIRECTION dir) { this->dir = dir; }

void Player::tick() {
    if (this->powStraw->getActive()) {
        this->strawCounter++;

        if (this->strawCounter >= 150) {
            this->strawCounter = 0;
            this->powStraw->reset();
        }
    }

    if (this->powApple->getActive()) {
        this->appleCounter++;
        this->speed = powApple->getSpeed();

        if (this->appleCounter >= 150) {
            this->appleCounter = 0;
            this->powApple->reset();
        }
    }

    this->speed = this->powApple->getSpeed();

    checkCollisions();

    if (movement == MUP && this->canMoveUp) {
        this->dir = UP;
    } else if (movement == MDOWN && this->canMoveDown) {
        this->dir = DOWN;
    } else if (movement == MLEFT && this->canMoveLeft) {
        this->dir = LEFT;
    } else if (movement == MRIGHT && this->canMoveRight) {
        this->dir = RIGHT;
    }

    if (this->dir == UP && this->canMoveUp) {
        this->y -= speed;
        this->walkUp->tick();

    } else if (this->dir == DOWN && this->canMoveDown) {
        this->y += speed;
        this->walkDown->tick();

    } else if (this->dir == LEFT && this->canMoveLeft) {
        this->x -= speed;
        this->walkLeft->tick();

    } else if (this->dir == RIGHT && this->canMoveRight) {
        this->x += speed;
        this->walkRight->tick();
    }

    for (ScoreParticle* p : this->particles) { p->tick(); }

    this->particles.erase(std::remove_if(this->particles.begin(), this->particles.end(),
                          [](ScoreParticle* p) { return p->lifeTime <= 0; }), 
                          this->particles.end());
}

void Player::render() {
    for (ScoreParticle* p : this->particles) { p->render(); }

    Texture2D t;
    if (this->dir == UP) {
        t = this->walkUp->getCurrentFrame();
        DrawTexturePro(t, (Rectangle){0, 0, (float)t.width, (float)t.height}, (Rectangle){this->x, this->y, this->width, this->height},
                       (Vector2){0, 0}, 0, (Color){255, 255, 255, (unsigned char)this->powStraw->getTransparency()});

    } else if (this->dir == DOWN) {
        t = this->walkDown->getCurrentFrame();
        DrawTexturePro(t, (Rectangle){0, 0, (float)t.width, (float)t.height}, (Rectangle){this->x, this->y, this->width, this->height},
                      (Vector2){0, 0}, 0, (Color){255, 255, 255, (unsigned char)this->powStraw->getTransparency()});

    } else if (this->dir == LEFT) {   
        t = this->walkLeft->getCurrentFrame();
        DrawTexturePro(t, (Rectangle){0, 0, (float)t.width, (float)t.height}, (Rectangle){this->x, this->y, this->width, this->height},
                      (Vector2){0, 0}, 0, (Color){255, 255, 255, (unsigned char)this->powStraw->getTransparency()});

    } else if (this->dir == RIGHT) {
        t = this->walkRight->getCurrentFrame();
        DrawTexturePro(t, (Rectangle){0, 0, (float)t.width, (float)t.height}, (Rectangle){this->x, this->y, this->width, this->height},
                      (Vector2){0, 0}, 0, (Color){255, 255, 255, (unsigned char)this->powStraw->getTransparency()});
    }
    
    DrawText("Health: ", (float)(GetScreenWidth()) / 2.0f + 125, 50, 10, (Color){0, 255, 255, 255});

    for (unsigned int i = 0; i < health; i++) {
        Texture2D temp = this->walkRight->getFrames()[0];
        DrawTexturePro(temp, (Rectangle){0, 0, (float)temp.width, (float)temp.height}, 
                       (Rectangle){GetScreenWidth() / 2.0f + 25 * i + 200, 50, 20, 20}, 
                       (Vector2){0, 0}, 0, YELLOW);
    }

    if (powName.size() == 0) {
        DrawText("No Power Ups", (float)(GetScreenWidth()) / 2.0f - 310, 50, 
                 10, (Color){0, 255, 255, 255});

    } else if (powName.size() == 1) {
        std::string pow = "Press SpaceBar to use " + powName[0];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 50,
                 10, (Color){0, 255, 255, 255});

    } else if (powName.size() == 2) {
        std::string pow = "Next: " + powName[1];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 30,
                   10, (Color){0, 255, 255, 255});

        pow = "Press SpaceBar to use " + powName[0];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 50,
                 10, (Color){0, 255, 255, 255});

    } else if (powName.size() >= 3) {
        std::string pow = "Next: " + powName[2];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 13,
                   10, (Color){0, 255, 255, 255});

        pow = "Next: " + powName[1];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 33,
                   10, (Color){0, 255, 255, 255});
                   
        pow = "Press SpaceBar to use: " + powName[0];
        DrawText(pow.c_str(), (float)(GetScreenWidth()) / 2.0f - 310, 53,
                  10, (Color){0, 255, 255, 255});
    }

    std::string pow = "Score: "  + std::to_string(score);
    DrawText(pow.c_str(), (float)(GetScreenWidth()) / 3.0f + 200, 50,
               10, (Color){0, 255, 255, 255});
}

void Player::keyPressed(int key) {
    switch((unsigned char)key){
        case 'W':
            this->movement = MUP;
            break;

        case 'S':
            this->movement = MDOWN;
            break;

        case 'A':
            this->movement = MLEFT;
            break;

        case 'D':
            this->movement = MRIGHT;
            break;

        case 'N':
            this->die();
            break;

        case 'M':
            if (this->health == this->MaxHealth) {
                this->health = this->MaxHealth;
            } else {
                this->health++;
            }

            break;

        case ' ':
            if (powName.empty()){
                break;
            } else if (powName[0] == "Strawberry Power Up") {
                if(!this->powStraw->getActive()) { powStraw->activate(); }
                powName.erase(powName.begin());

            } else if (powName[0] == "Cherry Power Up") {
                this->powCherry->activate();
                this->x = powCherry->getXPos();
                this->y = powCherry->getYPos();
                powName.erase(powName.begin());

            } else if (powName[0] == "Apple Power Up") {
                if(!powApple->getActive()) { powApple->activate(); }
                speed = powApple->getSpeed();
                powName.erase(powName.begin());
            }

            break;
    }

}

void Player::keyReleased(int key) {
    if(key == 'w' || key =='s' || key == 'a' || key == 'd') { this->moving = false; }
}

void Player::checkCollisions() {
    this->canMoveUp = true;
    this->canMoveDown = true;
    this->canMoveLeft = true;
    this->canMoveRight = true;

    for (BoundBlock* boundBlock : this->manager->boundBlocks) {
        if(CheckCollisionRecs(this->getBounds(this->x, this->y - this->speed), (boundBlock->getBounds()))) { 
            this->canMoveUp = false; 
        }

        if(CheckCollisionRecs(this->getBounds(this->x, this->y + this->speed), (boundBlock->getBounds()))) { 
            this->canMoveDown = false; 
        }
            
        if(CheckCollisionRecs(this->getBounds(this->x - this->speed, this->y), (boundBlock->getBounds()))) { 
            this->canMoveLeft = false; 
        }

        if(CheckCollisionRecs(this->getBounds(this->x + this->speed, this->y), (boundBlock->getBounds()))) { 
            this->canMoveRight = false; 
        }        
    }

    for(Entity* entity: this->manager->entities){
        if(this->collision(entity)){
            if (dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)) {
                PlaySound(this->chomp);
                entity->remove = true;
                this->score += 10;
            }
            
            if (dynamic_cast<BigDot*>(entity)) {
                PlaySound(this->chomp);
                this->score +=20;
                this->manager->setKillable(true);
            }

             if (dynamic_cast<Cherry*>(entity)) {
                PlaySound(this->eatFruit);
                entity->remove = true;
                if (powName.size() < 3) {
                     powName.push_back("Cherry Power Up");
                }
                this->score += 30;
            }

            if (dynamic_cast<Strawberry*>(entity)) {
                PlaySound(this->eatFruit);
                entity->remove = true;
                if (powName.size() < 3) {
                    powName.push_back("Strawberry Power Up");
                }
                score += 30;
            }

            if (dynamic_cast<Apple*>(entity)) {
                PlaySound(this->eatFruit);
                entity->remove = true;
                if (powName.size() < 3){
                    powName.push_back("Apple Power Up");
                }
                score += 30;
            }
        }
    }

    for (Entity* entity : this->manager->ghosts) {
        if (this->collision(entity)) {
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if (ghost->getKillable()) {
                PlaySound(this->eatGhost);
                this->score += 2000;
                this->particles.push_back(new ScoreParticle(this->x, this->y - 20, "2000"));
                ghost->remove = true;
            } else if (!powStraw->getActive()) {
                die();
            }
        }
    }
}

void Player::die(){
    this->health--;
    this->x = spawnX;
    this->y = spawnY;
    this->particles.clear();

}

Player::~Player(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}