#include "Menu.hpp"

MenuState::MenuState() {
	this->startButton = new Button(GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 25, 120, 50, "Start");
	std::vector<Rectangle> rightAnimframes;

	for (int i = 0; i < 3; i++) {
        Rectangle subImage = Rectangle { (float)(i * 16), 0, 16, 16 };
        rightAnimframes.push_back(subImage);
    }

	this->animation = new Animation(10, rightAnimframes);
}

void MenuState::update() {
	this->startButton->update();
	this->animation->update();

	if (this->startButton->wasPressed()) {
		this->setNextState("Game");
		this->setFinished(true);

	}
}

void MenuState::draw() {
	this->drawOverLay();
	std::string title = "Pacman Project";
	DrawText(title.c_str(), GetScreenWidth() / 2 - 197.5,
			 GetScreenHeight() / 2 - 300, 50, WHITE);
			 
	DrawTexturePro(ImageManager::pacman, this->animation->getCurrentFrame(), 
                	Rectangle { GetScreenWidth() / 2.0f - 44, GetScreenHeight() / 2.0f - 100, 100, 100 },
                   Vector2 {0, 0}, 0, WHITE);
	
	startButton->draw();
}

void MenuState::keyPressed(int key) {

}

void MenuState::mousePressed(int x, int y, int button) {
    this->startButton->mousePressed(x, y, button);
}

void MenuState::reset() {
	this->setFinished(false);
	this->setNextState("");
	this->startButton->reset();
}

MenuState::~MenuState() {
	delete this->startButton;
	delete this->animation;
}