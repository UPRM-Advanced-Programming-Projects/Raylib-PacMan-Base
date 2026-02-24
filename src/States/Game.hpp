#pragma once

#include "State.hpp"
#include "Player.hpp"
#include "MapBuilder.hpp"

class GameState: public State{
    private:
        Map* map;
		
		// If you wish to remove the five second delay at the beginning set the startupTimer variable to zero;
		int startupTimer = 150;
		bool isStarting = true;
        int finalScore = 0;

    public: 
        GameState();

		int getFinalScore();
		void soundManager();

		void update() override;
		void draw() override;
		void reset() override;
		void keyPressed(int key) override;
		void mousePressed(int x, int y, int button) override;
		void keyReleased(int key);

		~GameState();

};