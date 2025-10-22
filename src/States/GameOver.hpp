#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class GameOverState : public State {
private:
	Image img1;
	Button* startButton;
	Animation* animation;
	int score = 0;

public:
	GameOverState();

    void setScore(int score);

	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

	~GameOverState();
};
