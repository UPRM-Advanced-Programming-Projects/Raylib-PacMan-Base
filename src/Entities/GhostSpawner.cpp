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
            for (std::string color : colors) {
                bool found = false;

                for (Entity* ghost : this->manager->ghosts){
                    Ghost* g2 = dynamic_cast<Ghost*>(ghost);
                    if (g2->getColor() == color) found = true;
                }

                if (!found) {
                    spawnGhost(color);
                    spawnCounter = 150;
                    return;
                }
            }

        } else {
            spawnCounter--;
        }
    }
}