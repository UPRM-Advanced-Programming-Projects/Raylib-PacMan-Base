#pragma once

#include <iostream>
#include "raylib.h"

class Animation {
    private:
        int speed, index, timer;
        std::vector<Rectangle> frames;
        bool end;

    public:
        Animation(int speed, std::vector<Rectangle> frames) {
            this->speed = speed;
            this->frames = frames;
            this->index = 0;
            this->timer = 0;
        }

        void update();
        void reset();
        std::vector<Rectangle> getFrames();
        Rectangle getCurrentFrame();
};