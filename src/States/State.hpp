#pragma once

#include <iostream>
#include "raylib.h"

class State {
    private:
        std::string nextState;
        bool finished = false;
		Texture2D overlay = LoadTextureFromImage(LoadImage("images/overLay.png"));

	public:
		State() {}

		virtual void reset() = 0;
		virtual void tick() = 0;
		virtual void render() = 0;

		virtual void keyPressed(int key) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;
		virtual void keyReleased(int key){}

		void mouseMoved(int x, int y){}
		void mouseDragged(int x, int y, int button){}
		void mouseReleased(int x, int y, int button){}
		void mouseEntered(int x, int y){}
		void mouseExited(int x, int y){}

		void windowResized(int w, int h){}
		// void gotMessage(ofMessage msg){}
		// void dragEvent(ofDragInfo dragInfo){}

		bool hasFinished() { return this->finished; }
		std::string getNextState() { return nextState; }
		void setFinished(bool finished) { this->finished = finished; }
		void setNextState(std::string nextState) { this->nextState = nextState; }
		void drawOverLay() {
			DrawTexturePro(this->overlay, (Rectangle){0, 0, (float)this->overlay.width, (float)this->overlay.height}, 
						   (Rectangle){0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()}, 
						   (Vector2){0, 0}, 0, (Color){255, 255, 255, 255});
		}


};