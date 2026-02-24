#pragma once

#include "EntityManager.hpp"

class GhostSpawner : public Entity {
    private:
        EntityManager* manager;
        int spawnCounter = 150;
    
    public: 
        GhostSpawner(float x, float y, float width, float height, EntityManager* manager) : Entity(x, y, width, height) {
            this->manager = manager;
            spawnGhost("red");
            spawnGhost("cyan");
            spawnGhost("pink");
            spawnGhost("orange");
        }

        void spawnGhost(std::string color);
        void keyPressed(int key);
        void update();
};