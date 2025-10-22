#include "GameOver.hpp"

GameOverState::GameOverState() {
	this->startButton = new Button(GetScreenWidth() / 2 - 80, GetScreenHeight() / 2, 64, 50, "Start");

	img1 = LoadImage("images/pacman.png");
	std::vector<Texture2D> rightAnimframes;
    Image temp;

	for (int i = 0; i < 3; i++){
        temp = ImageFromImage(img1, (Rectangle){(float)(i * 16), 0, 16, 16});
        rightAnimframes.push_back(LoadTextureFromImage(temp));
    }

	this->animation = new Animation(10,rightAnimframes);
}

void GameOverState::setScore(int score) {
    this->score = score;
}

void GameOverState::tick() {
	this->startButton->tick();
	this->animation->tick();

	if (this->startButton->wasPressed()) {
		this->setNextState("Game");
		this->setFinished(true);
	}
}

void GameOverState::render() {
	this->drawOverLay();
	std::string text = "Score: " + std::to_string(this->score);
	DrawText(text.c_str(), GetScreenWidth() / 2.0f - 18 * text.size(),
					    GetScreenHeight() / 2.0f - 300, 50, (Color){255, 255, 255, 255});

	Texture2D temp = this->animation->getCurrentFrame();
    DrawTexturePro(temp, (Rectangle){0, 0, (float)temp.width, (float)temp.height}, 
                   (Rectangle){GetScreenWidth() / 2.0f - 5.5f * temp.width, GetScreenHeight() / 2.0f - 100, 100, 100}, 
                   (Vector2){0, 0}, 0, (Color){255, 255, 255, 255});
				   
	this->startButton->render();
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