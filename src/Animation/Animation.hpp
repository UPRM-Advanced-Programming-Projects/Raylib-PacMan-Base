#pragma once

#include <iostream>
#include "raylib.h"

class Animation {
    private:
        int speed, index, timer;
        bool end;
        std::vector<Texture2D> frames;
        Texture2D currentTexture;

    public:
        Animation(int speed, std::vector<Texture2D> frames) {
            this->speed = speed;
            this->frames = frames;
            this->index = 0;
            this->timer = 0;
        }

        void tick();
        void reset();
        std::vector<Texture2D> getFrames();
        Texture2D getCurrentFrame();
};