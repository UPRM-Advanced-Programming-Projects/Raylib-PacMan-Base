#include "Button.hpp"

void Button::mousePressed(float x, float y, int button) {
    if (this->xPos + width >= x && x >= this->xPos && 
       this->yPos + height >= y && y >= this->yPos && IsMouseButtonPressed(button)) {
        pressed = true;
        pressedCounter = 10;
    }
}

void Button::tick() {
    this->pressedCounter--;
    if (this->pressedCounter == 0) {
        this->pressed = false;
        this->pressedCounter = -1;
    }
}

void Button::render() {
    DrawText(this->buttonText.c_str(), this->xPos + width / 2 - 4 * buttonText.size(), 
             this->yPos + height / 2, 20, (Color){0, 255, 255, 255});

    DrawRectangleLines(this->xPos - this->buttonText.size() * 3.7, this->yPos + 12,
                       this->width + this->buttonText.size() * 10, this->height, (Color){0, 0, 255, 255});
}

void Button::reset() {
    this->pressedCounter = -1;
    this->pressed = false;
}
