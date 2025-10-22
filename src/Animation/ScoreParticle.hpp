#pragma once

#include "raylib.h"

class ScoreParticle {
    private:
        char* score;
        float x, y;
        int transparency = 255;
        
    public:
        int lifeTime = 30;
        ScoreParticle(float x, float y, char* score) {
            this->x = x;
            this->y = y;
            this->score = score;
        }

        void render();
        void tick();

        ~ScoreParticle() {}
};