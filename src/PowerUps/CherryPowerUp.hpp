#pragma once

#include "EntityManager.hpp"
#include "PowerUp.hpp"

class CherryPowerUp : public PowerUp {
    private:
        bool active;
        int xAxis;
        int yAxis;
        EntityManager* manager;
    
    public:
        CherryPowerUp() {
            this->active = false;
        }

        virtual void activate() override {
            this->active = true;

            int dot = GetRandomValue(0, this->manager->entities.size());
            this->xAxis = this->manager->entities[dot]->getXDot();
            this->yAxis = this->manager->entities[dot]->getYDot();
        }

        void reset() { this->active = false; }
        int getXPos() { return this->xAxis; }
        int getYPos() { return this->yAxis; }
        void setManager(EntityManager* manager) { this->manager = manager; }
};
