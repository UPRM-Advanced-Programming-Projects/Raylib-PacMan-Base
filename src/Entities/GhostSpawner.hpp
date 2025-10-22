#pragma once

#include "EntityManager.hpp"

class GhostSpawner : public Entity {
    private:
        EntityManager* manager;
        int spawnCounter = 150;
        const unsigned int maxGhostAmount = 8;
    
    public: 
        GhostSpawner(float x, float y, float width, float height, EntityManager* manager, Image sprite) : Entity(x, y, width, height) {
            this->manager = manager;
            this->sprite = sprite;
            this->entityTexture = LoadTextureFromImage(sprite);
            spawnGhost("red");
            spawnGhost("cyan");
            spawnGhost("pink");
            spawnGhost("orange");
        }

        void spawnGhost(std::string color);
        void keyPressed(int key);
        void tick();
};