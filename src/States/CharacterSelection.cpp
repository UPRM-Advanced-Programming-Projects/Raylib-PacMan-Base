#include "CharacterSelection.hpp"

CharacterSelectionState::CharacterSelectionState() {
	this->selectedCharacter = "good";
	
	Image temp;
	this->img1 = LoadImage(CHAR1SPRITE.c_str());
	this->img2 = LoadImage(CHAR2SPRITE.c_str());
	
	std::vector<Texture2D> char1AnimationFrames;
	std::vector<Texture2D> char2AnimationFrames;
	
	for (int i = 0; i < 3; i++) {
		temp = ImageFromImage(img1, (Rectangle){(float)(i * 16), 0, 16, 16});
        ImageResize(&temp, 16 * 6, 16 * 6);
        char1AnimationFrames.push_back(LoadTextureFromImage(temp));
		
		temp = ImageFromImage(img2, (Rectangle){(float)(i * 16), 0, 16, 16});
        ImageResize(&temp, 16 * 6, 16 * 6);
        char2AnimationFrames.push_back(LoadTextureFromImage(temp));
    }
	
	this->char1Anim = new Animation(5, char1AnimationFrames);
	this->char2Anim = new Animation(5, char2AnimationFrames);

	Texture2D t = char1Anim->getCurrentFrame();
	this->char1Button = new Button(GetScreenWidth() / 2 - 2.1 * t.width, GetScreenHeight() / 2 + 50, 64, 50, "Pacman");
	this->char2Button = new Button(GetScreenWidth() / 2 + 0.6 * t.width, GetScreenHeight() / 2 + 50, 64, 50, "Evil Pacman");
}

std::string CharacterSelectionState::getSelectedCharacter() {
    return this->selectedCharacter;
}

void CharacterSelectionState::tick() {
	this->char1Button->tick();
	this->char2Button->tick();

	this->char1Anim->tick();
	this->char2Anim->tick();

	if (this->char1Button->wasPressed()) {
		this->selectedCharacter = "good";
		setNextState("Menu");
		setFinished(true);
	}

	if (this->char2Button->wasPressed()) {
		this->selectedCharacter = "bad";
		setNextState("Menu");
		setFinished(true);	
	}
}

void CharacterSelectionState::render() {
    std::string choose = "Choose your Character!";
	this->drawOverLay();
	DrawText(choose.c_str(), GetScreenWidth() / 2 - 14 * choose.size(),
			 GetScreenHeight() / 2 - 300, 50, (Color){255, 255, 255, 255});

	Texture2D temp = this->char1Anim->getCurrentFrame();
	DrawTexture(temp, GetScreenWidth() / 2 - 2.1 * temp.width,
			    GetScreenHeight() / 2 - temp.height, (Color){255, 255, 255, 255});

	temp = this->char2Anim->getCurrentFrame();
	DrawTexture(temp, GetScreenWidth() / 2 + 0.6 * temp.width,
			    GetScreenHeight() / 2 - temp.height, (Color){255, 255, 255, 255});
				
	this->char1Button->render();
	this->char2Button->render();
}

void CharacterSelectionState::keyPressed(int key) {

}

void CharacterSelectionState::mousePressed(int x, int y, int button) {
    this->char1Button->mousePressed(x, y, button);
	this->char2Button->mousePressed(x, y, button);
}

void CharacterSelectionState::reset() {
    this->setFinished(false);
	this->setNextState("");
	this->char1Button->reset();
	this->char2Button->reset();
}

CharacterSelectionState::~CharacterSelectionState() {
    delete this->char1Anim;
	delete this->char2Anim;
	delete this->char1Button;
	delete this->char2Button;
}