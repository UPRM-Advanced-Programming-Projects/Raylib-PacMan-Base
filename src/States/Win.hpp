#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class WinState : public State {
    private:
        Image pacImg;
        Button* playAgainButton;
        int score = 0;
        
    public:
        Button* quitButton;
        WinState();

        void setScore(int score);

        void tick();
        void reset();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);

        ~WinState();
};