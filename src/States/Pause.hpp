#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp"

class PauseState : public State {
    private:
        Animation* animation;
        Button* resumeButton;
        Button* quitButton;

    public:
        PauseState();

        void tick();
        void render();
        void reset();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);

        ~PauseState();
};