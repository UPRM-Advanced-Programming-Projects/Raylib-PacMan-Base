#pragma once

#include <iostream>
#include "raylib.h"

class Button {
    private:
        float xPos, yPos, width, height;
        int pressedCounter = -1;
        bool pressed = false;
        std::string buttonText;
        Image buttonImage, clickedButton;
        Texture2D buttonTexture, clickedTexture;

    public:
        Button() {
            this->xPos = GetScreenWidth() / 2;
            this->yPos = GetScreenHeight() / 2;
            this->width = 64;
            this->height = 20; 
        }

        Button(float xPos, float yPos, float width, float height, std::string buttonText) {
            this->xPos = xPos;
            this->yPos = yPos;
            this->buttonText = buttonText;
            this->width = width;
            this->height = height;
        }

        void mousePressed(float x, float y, int button);
        void tick();
        void render();
        void reset();

        bool wasPressed() { return this->pressed; }

        ~Button() {}
};