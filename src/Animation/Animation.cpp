#include "Animation.hpp"

void Animation::update() {
    this->timer++;
    if (this->timer >= this->speed) {
        this->index++;
        this->timer = 0;
        if (this->index >= this->frames.size()) {
            this->index = 0;
        }
    }
}

std::vector<Rectangle> Animation::getFrames() {
    return this->frames;
}

Rectangle Animation::getCurrentFrame() {
    return this->frames[this->index];
}