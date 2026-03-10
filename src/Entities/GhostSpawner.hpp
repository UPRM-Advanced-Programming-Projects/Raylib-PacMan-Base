#pragma once

#include "Ghost.hpp"
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

            int count = 0;
            for (Entity* g : this->manager->ghosts) {
                Ghost* g2 = dynamic_cast<Ghost*>(g);
                g2->setDelay(30 * count++);
            }
        }

        void spawnGhost(std::string color);
        void keyPressed(int key);
        void update();
};