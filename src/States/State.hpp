#pragma once

#include <iostream>
#include "raylib.h"
#include "ImageManager.hpp"
#include "SoundManager.hpp"

class State {
    private:
        std::string nextState;
        bool finished = false;

	public:
		State() {}

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void reset() = 0;

		virtual void keyPressed(int key) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;

		bool hasFinished() { return this->finished; }
		std::string getNextState() { return nextState; }
		void setFinished(bool finished) { this->finished = finished; }
		void setNextState(std::string nextState) { this->nextState = nextState; }
		
		void drawOverLay() {
			DrawRectangleLinesEx(Rectangle { 10.0f, 10.0f, GetScreenWidth() - 20.0f, GetScreenHeight() - 20.0f }, 4, Color { 0, 0, 255, 255 });
		}


};