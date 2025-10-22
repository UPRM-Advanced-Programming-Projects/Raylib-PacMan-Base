#include "Animation.hpp"

void Animation::tick() {
    this->timer++;
    if (this->timer >= this->speed) {
        this->index++;
        this->timer = 0;
        if (this->index >= this->frames.size()) {
            this->index = 0;
        }
    }
}

std::vector<Texture2D> Animation::getFrames() {
    return this->frames;
}

Texture2D Animation::getCurrentFrame() {
    return this->frames[this->index];
}