#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"

#include "Menu.hpp"
#include "Game.hpp"
#include "GameOver.hpp"
#include "Pause.hpp"
#include "Win.hpp"
#include "CharacterSelection.hpp"

class Program {
    private:
        State* currentState;
        PauseState* pauseState;
        MenuState* menuState;
        GameState* gameState;
        GameOverState* gameOverState;
        CharacterSelectionState* characterSelectionState;
        
    public:
        WinState* winState;
        Program();
        
        void Update();
        void Draw();
        void Unload();  
        
        
        void KeyPressed(int key);
        void KeyReleased(int key);
        void MouseMoved(int x, int y );
        void MouseDragged(int x, int y, int button);
        void MousePressed(int x, int y, int button);
        void MouseReleased(int x, int y, int button);
        void MouseEntered(int x, int y);
        void MouseExited(int x, int y);
        void WindowResized(int w, int h);
        // void dragEvent(ofDragInfo dragInfo);
        // void gotMessage(ofMessage msg);	

        ~Program();
};