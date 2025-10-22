#include "Menu.hpp"

MenuState::MenuState() {
	this->startButton = new Button(GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 64, 50, "Start");
	this->img1 = LoadImage("images/pacman.png");

	std::vector<Texture2D> rightAnimframes;
    Image temp;
	for (int i = 0; i < 3; i++) {
        temp = ImageFromImage(img1, (Rectangle){(float)(i * 16), 0, 16, 16});
        rightAnimframes.push_back(LoadTextureFromImage(temp));
    }

	this->animation = new Animation(10, rightAnimframes);
}

void MenuState::tick() {
	this->startButton->tick();
	this->animation->tick();

	if (this->startButton->wasPressed()) {
		this->setNextState("Game");
		this->setFinished(true);

	}
}

void MenuState::render() {
	this->drawOverLay();
	std::string title = "Pacman Project";
	DrawText(title.c_str(), GetScreenWidth() / 2 - 14 * title.size(),
			 GetScreenHeight() / 2 - 300, 50, (Color){255, 255, 255, 255});
			 
    Texture2D temp = this->animation->getCurrentFrame();
	DrawTexturePro(temp, (Rectangle){0, 0, (float)temp.width, (float)temp.height}, 
                   (Rectangle){GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f - 100, 100, 100},
                   (Vector2){0, 0}, 0, (Color){255, 255, 255, 255});
	
	startButton->render();
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