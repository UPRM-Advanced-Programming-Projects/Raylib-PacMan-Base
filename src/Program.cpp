#include "Program.hpp"

bool isKeyCurrentlyPressed = false;

Program::Program(){
	//States
	this->characterSelectionState = new CharacterSelectionState();
	this->menuState = new MenuState();
	this->gameState = new GameState();
	this->winState = new WinState();
	this->pauseState = new PauseState();
	this->gameOverState = new GameOverState();

	// Initial State
	this->currentState = characterSelectionState;
}

void Program::Update(){
    if (this->currentState != nullptr) {
        this->currentState->tick();
        if (this->currentState->hasFinished()) {
            
            if(this->characterSelectionState->getSelectedCharacter() == "bad"){
                this->gameState->changePlayer();	
            }

            if (this->currentState->getNextState() == "CharSelection") {
                this->currentState = this->characterSelectionState;

            } else if (this->currentState->getNextState() == "Menu") {
                this->currentState = this->menuState;

            } else if (this->currentState->getNextState() == "Game") {
                this->currentState = this->gameState;

            } else if (this->currentState->getNextState() == "Win") {
                this->winState->setScore(this->gameState->getFinalScore());
                this->currentState = this->winState;
                this->gameState = new GameState();

            } else if (this->currentState->getNextState() == "over") {
                this->gameOverState->setScore(this->gameState->getFinalScore());
                this->currentState = this->gameOverState;
                this->gameState = new GameState();
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
	if ( key == '-' ) {
		SetMasterVolume(0);
	}
	
	//Turn Volume Back Up
	if ( key == '=' ) {
		SetMasterVolume(1);
	}

	// Pause State trigger
	if ( key == 'p' && !isKeyCurrentlyPressed) {
		if (this->currentState == this->gameState) {
            this->currentState = this->pauseState;
            this->currentState->reset();

		} else if (this->currentState == this->pauseState) {
            this->currentState = this->gameState;
            this->currentState->reset();	
		}

		isKeyCurrentlyPressed = true;
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