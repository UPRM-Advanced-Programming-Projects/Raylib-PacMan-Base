#include "Win.hpp"

WinState::WinState() {
    this->playAgainButton = new Button(GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 30, 64, 50, "Play Again?");
    this->quitButton = new Button(GetScreenWidth() / 2 - 85, GetScreenHeight() / 2 + 30, 64, 50, "Quit");
}

void WinState::setScore(int score) {
    this->score = score;
}

void WinState::tick() {
    this->playAgainButton->tick();

	if(this->playAgainButton->wasPressed()) {
		this->setNextState("Game");
        this->setFinished(true);
	}

}

void WinState::render() {
    this->drawOverLay();
    std::string text = "YOU WIN!!!!";
    DrawText(text.c_str(), GetScreenWidth() / 2 - 16 * text.size(),
             GetScreenHeight() / 2 - 350, 50, (Color){255, 255, 255, 255});

    text = "Score: " + std::to_string(this->score);
    DrawText(text.c_str(), GetScreenWidth() / 2 - 18 * text.size(),
             GetScreenHeight() / 2 - 250, 50, (Color){255, 255, 255, 255});
             
    playAgainButton->render();
    quitButton->render();
}

void WinState::reset() {
	this->setFinished(false);
	this->setNextState("");
    this->playAgainButton->reset();
    this->quitButton->reset();
}

void WinState::keyPressed(int key) {

}

void WinState::mousePressed(int x, int y, int button) {
    this->playAgainButton->mousePressed(x, y, button);
    this->quitButton->mousePressed(x, y, button);
}

WinState::~WinState() {
    delete this->playAgainButton;
    delete this->quitButton;
}