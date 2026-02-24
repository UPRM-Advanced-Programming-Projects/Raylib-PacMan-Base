#include "ScoreParticle.hpp"

void ScoreParticle::draw() {
    DrawText(score, this->x, this->y, 12, (Color){255, 255, 255, (unsigned char)(this->transparency)});
}

void ScoreParticle::update() {
    this->lifeTime--;
    this->transparency -= 8;
    this->y -= 0.5f;
}