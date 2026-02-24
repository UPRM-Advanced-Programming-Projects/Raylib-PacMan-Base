#include "Game.hpp"

GameState::GameState() {
	this->map = MapBuilder().createMap(ImageManager::map);
}

int GameState::getFinalScore() {
    return this->finalScore;
}

void GameState::update() {
	this->soundManager();

	if (this->startupTimer <= 0) {
		this->map->update();
	
		if (this->map->getPlayer()->getHealth() == 0) {
			this->setFinished(true);
			this->setNextState("over");
			this->map->getPlayer()->setHealth(3);
			this->finalScore = map->getPlayer()->getScore();
			this->map->getPlayer()->setScore(0);
		}
	
		if (this->map->getEntityManager()->entities.size() == 0) {
			this->finalScore = map->getPlayer()->getScore();
			this->setFinished(true);
			this->setNextState("Win");
		}
	}
}

void GameState::draw() {
    this->map->draw();
}

void GameState::soundManager() {
    if (!IsSoundPlaying(SoundManager::startup) && this->isStarting && this->startupTimer > 0) {
		PlaySound(SoundManager::startup);
		this->isStarting = false;
	}

	this->startupTimer = std::max(0, this->startupTimer - 1);
}

void GameState::keyPressed(int key) {
	if (this->startupTimer <= 0) {
		this->map->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button) {

}

void GameState::keyReleased(int key) {
    this->map->keyReleased(key);
}

void GameState::reset() {
	this->setFinished(false);
	this->setNextState("");
}

GameState::~GameState() {
    delete this->map;
}