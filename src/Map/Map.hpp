#pragma once

#include "Player.hpp"
#include "GhostSpawner.hpp"

class Map {
    private:
        EntityManager* entityManager;
        Player* player;
        Player* player2;
        GhostSpawner* ghostSpawner;

    public:
        std::string playerType = "good";

        Map(EntityManager* manager);

        void addBoundBlock(BoundBlock* block);
        void addEntity(Entity* entity);

        Player* getPlayer();
        EntityManager* getEntityManager();

        void setPlayer(Player* player);
        void setAltPlayer(Player* player2);
        void setGhostSpawner(GhostSpawner* spawner);

        void tick();
        void render();
        
        void keyPressed(int key);
        void keyReleased(int key);
        
        ~Map();
};
