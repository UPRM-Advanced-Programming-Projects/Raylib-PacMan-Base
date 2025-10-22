#include "GhostSpawner.hpp"
#include "Ghost.hpp"

std::vector<std::string> colors = {"red", "pink", "cyan", "orange"};

void GhostSpawner::spawnGhost(std::string color) {
    if (!(this->manager->ghosts.size() > this->maxGhostAmount - 1)) {
        Ghost* ghost = new Ghost(this->x, this->y, this->width, this->height, this->sprite, manager, color);
        this->manager->ghosts.push_back(ghost);
    }
}

void GhostSpawner::keyPressed(int key) {
    if (key == 'g') {
        spawnGhost(colors[(int)GetRandomValue(0, 4)]);
    }
}

void GhostSpawner::tick() {
    if (this->manager->ghosts.size() < 4) {
        if (this->spawnCounter == 0) {
            spawnGhost(colors[(int)GetRandomValue(0, 4)]);
            spawnCounter = 150;
        } else {
            spawnCounter--;
        }
    }
}