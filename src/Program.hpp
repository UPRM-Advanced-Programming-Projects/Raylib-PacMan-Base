#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"

#include "Menu.hpp"
#include "Game.hpp"
#include "GameOver.hpp"

class Program {
    private:
        State* currentState;
        MenuState* menuState;
        GameState* gameState;
        GameOverState* gameOverState;
        
    public:
        Program();
        
        void Update();
        void Draw();
        void Unload();  
        
        
        void KeyPressed(int key);
        void KeyReleased(int key);
        void MousePressed(int x, int y, int button);

        ~Program() {}
};