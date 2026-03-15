#include "GhostSpawner.hpp"
#include "Ghost.hpp"

std::vector<std::string> colors = {"red", "pink", "cyan", "orange"};

void GhostSpawner::spawnGhost(std::string color) {
    Ghost* ghost = new Ghost(this->x, this->y, this->width, this->height, manager, color);
    this->manager->ghosts.push_back(ghost);
}

void GhostSpawner::keyPressed(int key) {
    if (key == 'G') {
        spawnGhost(colors[0]);
    }
}

void GhostSpawner::update() {
    if (this->manager->ghosts.size() < 4) {
        if (this->spawnCounter == 0) {
            spawnGhost(colors[0]);
            spawnCounter = 150;

        } else {
            spawnCounter--;
        }
    }
}