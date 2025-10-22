#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "Animation.hpp" 

class CharacterSelectionState : public State {
    private:
        Button* char1Button;
        Button* char2Button;
        Image img1;
        Image img2;
        
        const std::string CHAR1SPRITE = "images/pacman.png";
        const std::string CHAR2SPRITE = "images/evil-pacman.png";
        Animation* char1Anim;
        Animation* char2Anim;

        
    public:
        std::string selectedCharacter;

        CharacterSelectionState();

        std::string getSelectedCharacter();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();

        ~CharacterSelectionState();
};
