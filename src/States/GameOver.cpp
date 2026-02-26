#include "GameOver.hpp"

GameOverState::GameOverState() {
	this->startButton = new Button(GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 25, 120, 50, "Start");
	std::vector<Rectangle> rightAnimframes;

	for (int i = 0; i < 3; i++){
        Rectangle subImage = (Rectangle){(float)(i * 16), 0, 16, 16};
        rightAnimframes.push_back(subImage);
    }

	this->animation = new Animation(10, rightAnimframes);
}

void GameOverState::setScore(int score) {
    this->score = score;
}

void GameOverState::update() {
	this->startButton->update();
	this->animation->update();

	if (this->startButton->wasPressed()) {
		this->setNextState("Game");
		this->setFinished(true);
	}
}

void GameOverState::draw() {
	this->drawOverLay();
	std::string text = "Score: " + std::to_string(this->score);
	DrawText(text.c_str(), GetScreenWidth() / 2.0f - 150,
			 GetScreenHeight() / 2.0f - 300, 50, WHITE);

    DrawTexturePro(ImageManager::pacman, this->animation->getCurrentFrame(), 
                   Rectangle { GetScreenWidth() / 2.0f - 44, GetScreenHeight() / 2.0f - 100, 100, 100 }, 
                   Vector2 {0, 0}, 0, WHITE);
				   
	this->startButton->draw();
}

void GameOverState::keyPressed(int key) {

}

void GameOverState::mousePressed(int x, int y, int button) {
	startButton->mousePressed(x, y, button);
}

void GameOverState::reset() {
	this->setFinished(false);
	this->setNextState("");
	this->startButton->reset();
}

GameOverState::~GameOverState() {
	delete this->startButton;
	delete this->animation;
}