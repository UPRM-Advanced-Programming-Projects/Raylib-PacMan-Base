#include "Pause.hpp"

PauseState::PauseState() {
    this->resumeButton = new Button(GetScreenWidth() / 2 - 32, GetScreenHeight() / 2, 64, 50, "Back to Game");
    this->quitButton = new Button(GetScreenWidth() / 2 - 32, GetScreenHeight() / 2 + 100, 64, 50, "Quit");
}

void PauseState::tick() {
    this->resumeButton->tick();
    this->quitButton->tick();

	if(this->resumeButton->wasPressed()) {
		setNextState("Game");
        setFinished(true);
	}

    if (this->quitButton->wasPressed()) {
        setFinished(true);
        CloseWindow();       
    }
}

void PauseState::render() {
    std::string pauseTitle = "Pause Menu";
    DrawText(pauseTitle.c_str(), GetScreenWidth() / 2 - 4 * pauseTitle.size(),
             GetScreenHeight() / 2 - 300, 50, (Color){255, 255, 255, 255});
    this->resumeButton->render();
    this->quitButton->render();
}

void PauseState::reset() {
	this->setFinished(false);
	this->setNextState("");
	this->resumeButton->reset();
    this->quitButton->reset();
}

void PauseState::keyPressed(int key) {

}

void PauseState::mousePressed(int x, int y, int button) {
    this->resumeButton->mousePressed(x, y, button);
    this->quitButton->mousePressed(x, y, button);
}

PauseState::~PauseState() {
    delete resumeButton;
    delete quitButton;
    delete animation;
}