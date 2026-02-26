#include "Button.hpp"

void Button::mousePressed(float x, float y, int button) {
    if (this->xPos + width >= x && x >= this->xPos && 
       this->yPos + height >= y && y >= this->yPos && IsMouseButtonPressed(button)) {
        pressed = true;
        pressedCounter = 10;
    }
}

void Button::update() {
    this->pressedCounter--;
    if (this->pressedCounter == 0) {
        this->pressed = false;
        this->pressedCounter = -1;
    }
}

void Button::draw() {
    DrawText(this->buttonText.c_str(), this->xPos + this->width / 2 - (11 * buttonText.size()) / 2, 
             this->yPos + this->height / 2 - 7, 20, (Color){0, 255, 255, 255});

    DrawRectangleLines(this->xPos, this->yPos, this->width, this->height, (Color){0, 0, 255, 255});
}

void Button::reset() {
    this->pressedCounter = -1;
    this->pressed = false;
}
