#pragma once

#include "Player.hpp"
#include "GhostSpawner.hpp"

class Map {
    private:
        EntityManager* entityManager;
        Player* player;
        GhostSpawner* ghostSpawner;

    public:

        Map(EntityManager* manager);

        void addBoundBlock(BoundBlock* block);
        void addEntity(Entity* entity);

        Player* getPlayer();
        EntityManager* getEntityManager();

        void setPlayer(Player* player);
        void setGhostSpawner(GhostSpawner* spawner);

        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
        
        ~Map();
};
