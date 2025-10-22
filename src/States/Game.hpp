#pragma once

#include "State.hpp"
#include "Player.hpp"
#include "MapBuilder.hpp"

class GameState: public State{
    private:
        Sound startup;
		Sound music;
        Image mapImage;
        Map* map;
		
		// If you wish to remove the five second delay at the beginning set the startupTimer variable to zero;
		int startupTimer = 150;
		bool isStarting = true;
        int finalScore = 0;

    public: 
        GameState();

		int getFinalScore();
		void soundManager();

		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);

		~GameState();

};