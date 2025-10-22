#pragma once

#include <iostream>
#include "BoundBlock.hpp"

class EntityManager {
    private:
        bool killable = false;
        int killableCounter;

    public:
        std::vector<Entity*> entities;
        std::vector<BoundBlock*> boundBlocks;
        std::vector<Entity*> ghosts;

        void tick();
        void render();
        void setKillable(bool);

        ~EntityManager();
};