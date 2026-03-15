#pragma once

#include <iostream>
#include "BoundBlock.hpp"
#include <vector>

class EntityManager {
    private:
        bool killable = false;
        int killableCounter;

    public:
        std::vector<Entity*> entities;
        std::vector<BoundBlock*> boundBlocks;
        std::vector<Entity*> ghosts;

        void update();
        void draw();
        void setKillable(bool);

        ~EntityManager();
};