#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class MenuState : public State {
private:
	Image img1;
	Button* startButton;
	Animation* animation;

public:
	MenuState();
    
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

	~MenuState();
};
