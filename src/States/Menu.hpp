#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class MenuState : public State {
	private:
		Button* startButton;
		Animation* animation;

	public:
		MenuState();
		
		void update() override;
		void draw() override;
		void reset() override;
		void keyPressed(int key) override;
		void mousePressed(int x, int y, int button) override;

		~MenuState();
};
