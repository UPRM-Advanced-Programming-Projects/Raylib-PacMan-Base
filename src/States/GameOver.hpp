#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class GameOverState : public State {
	private:
		Button* startButton;
		Animation* animation;
		int score = 0;

	public:
		GameOverState();

		void setScore(int score);

		void update() override;
		void draw() override;
		void reset() override;
		void keyPressed(int key) override;
		void mousePressed(int x, int y, int button) override;

		~GameOverState();
};
