#include "Game.hpp"

GameState::GameState() {
	this->startup = LoadSound("audio/pac-man-startup.mp3");
	this->mapImage = LoadImage("images/map.png");
	this->map = MapBuilder().createMap(LoadTextureFromImage(mapImage));
}

int GameState::getFinalScore() {
    return this->finalScore;
}

void GameState::tick() {
	this->soundManager();

	if (this->startupTimer <= 0) {
		this->map->tick();
	
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

void GameState::render() {
    this->map->render();
}

void GameState::soundManager() {
    if (!IsSoundPlaying(this->startup) && this->isStarting && this->startupTimer > 0) {
		PlaySound(this->startup);
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