#pragma once

#include "PowerUp.hpp"
#include "Entity.hpp"

class StrawberryPowerUp : public PowerUp {
    private:
        bool active;
        bool invincible = false;
        int transparency = 255;
    
    public:
        StrawberryPowerUp() {
            this->active = false;
        }

        virtual void activate() override {
            this->transparency = 50;
            this->active = true;
        }

        void reset() {
            this->transparency = 255;
            this->active = false;
        }

        int getTransparency() { return this->transparency; }
        bool getActive() { return this->active; }

};