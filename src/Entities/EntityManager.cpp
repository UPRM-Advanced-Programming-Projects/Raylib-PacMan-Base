#include "EntityManager.hpp"
#include "Ghost.hpp"

void EntityManager::update() {
    if (this->killable) {
        this->killableCounter--;

        if (killableCounter <= 0) {
            this->killable = false;

            for (Entity* entity : ghosts) {
                Ghost* ghost= dynamic_cast<Ghost*>(entity);
                ghost->setKillable(false);
            }

        }
    }

    for (unsigned int i = 0; i < entities.size(); i++) {
        if (!entities[i]->remove) {
            entities[i]->update();
        } else {
            Entity* entityPointer = entities[i];
            entities.erase(entities.begin() + i--);
            delete entityPointer;
        }
    }

    for (BoundBlock* block : boundBlocks) { block->update(); }

    for (unsigned int i = 0; i < ghosts.size(); i++) {
        if (!ghosts[i]->remove) {
            ghosts[i]->update();
        } else {
            Ghost* ghostPointer = dynamic_cast<Ghost*>(ghosts[i]);
            ghosts.erase(ghosts.begin() + i--);
            delete ghostPointer;
        }
    }
}

void EntityManager::draw() {
    for (Entity* entity: this->entities) entity->draw();
    for (BoundBlock* block: this->boundBlocks) block->BoundBlock::draw();
    for (Entity* ghost: this->ghosts) ghost->draw();
}

void EntityManager::setKillable(bool) {
    this->killable = true;
    this->killableCounter = 10 * GetFPS();

    for (Entity* entity : ghosts) {
        Ghost* ghost = dynamic_cast<Ghost*>(entity); 
        ghost->setKillable(true);
    }
}

EntityManager::~EntityManager() {
    for(Entity* entity: boundBlocks) delete dynamic_cast<BoundBlock*>(entity);

    for(Entity* entity: ghosts) delete dynamic_cast<Ghost*>(entity);

    for(Entity* entity: entities) delete entity;
    
    boundBlocks.clear();
    ghosts.clear();
    entities.clear();
}