#include "Program.hpp"

bool isKeyCurrentlyPressed = false;

Program::Program(){
	this->menuState = new MenuState();
	this->gameState = new GameState();
	this->gameOverState = new GameOverState();

	// Initial State
	this->currentState = menuState;
}

void Program::Update(){
    if (this->currentState != nullptr) {
        this->currentState->update();
        if (this->currentState->hasFinished()) {
            if (this->currentState->getNextState() == "Menu") {
                this->currentState = this->menuState;

            } else if (this->currentState->getNextState() == "Game") {
                this->currentState = this->gameState;

            } else if (this->currentState->getNextState() == "over") {
                this->gameOverState->setScore(this->gameState->getFinalScore());
                this->currentState = this->gameOverState;
            }

            this->currentState->reset();

        } else {
            if(this->currentState->getNextState() == "Game") {
                this->currentState = this->gameState;
            }
        }
    }

}

void Program::Draw(){
	if (this->currentState != nullptr) this->currentState->draw();
}

void Program::KeyPressed(int key) {
	if (this->currentState != nullptr) {
		this->currentState->keyPressed(key);
	}

	//Turn Volume Down (Mute)	
	if ( key == KEY_MINUS ) {
		SetMasterVolume(0);
	}
	
	//Turn Volume Back Up
	if ( key == KEY_EQUAL) {
		SetMasterVolume(1);
	}
}

void Program::KeyReleased(int key) {
	if (key == 'p') {
		isKeyCurrentlyPressed = false;
	}
}

void Program::MousePressed(int x, int y, int button) {
	if (this->currentState != nullptr) this->currentState->mousePressed(x, y, button);
}

void Program::Unload(){
	SoundManager::unloadSounds();
	ImageManager::unloadImages();
}