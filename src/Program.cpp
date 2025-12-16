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
        this->currentState->tick();
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
	if (this->currentState != nullptr) this->currentState->render();
	
}

void Program::Unload(){

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
	if (this->currentState != nullptr)
			this->currentState->keyReleased(key);
	
	if (key == 'p') {
		isKeyCurrentlyPressed = false;
	}
}

void Program::MouseMoved(int x, int y ) {
	if (this->currentState != nullptr) this->currentState->mouseMoved(x, y);
}

void Program::MouseDragged(int x, int y, int button) {
	if (this->currentState != nullptr) this->currentState->mouseDragged(x, y, button);
}

void Program::MousePressed(int x, int y, int button) {
	if (this->currentState != nullptr) this->currentState->mousePressed(x, y, button);
}

void Program::MouseReleased(int x, int y, int button) {
	if (this->currentState != nullptr) this->currentState->mouseReleased(x, y, button);
}

void Program::MouseEntered(int x, int y) {
	if (this->currentState != nullptr) this->currentState->mouseEntered(x, y);
}

void Program::MouseExited(int x, int y) {
	if (this->currentState != nullptr) this->currentState->mouseExited(x, y);
}

void Program::WindowResized(int w, int h) {
	if (this->currentState != nullptr) this->currentState->windowResized(w, h);
}

Program::~Program() {
    Unload();
}