#pragma once

#include "Entity.hpp"
#include "PowerUp.hpp"

class ApplePowerUp : public PowerUp {
    private:
        int speed;
        bool active;
    
    public:
        ApplePowerUp() {
            this->active = false;
        }

        virtual void activate() override { this->active = true; }
        void reset() { this->active = false; }

        bool getActive() { return this->active; }
        int getSpeed() { return (active) ? 8 : 4; }

        ~ApplePowerUp() {}
};