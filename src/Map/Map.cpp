#pragma once

#include "Map.hpp"

Map::Map(EntityManager* manager) {
    this->entityManager = manager;
}

void Map::addBoundBlock(BoundBlock* block) {
    this->entityManager->boundBlocks.push_back(block);
}

void Map::addEntity(Entity* entity) {
    this->entityManager->entities.push_back(entity);
}

Player* Map::getPlayer() {
    if (this->playerType == "good") {
        return this->player;
    } else {
        return this->player2;
    }
}

EntityManager* Map::getEntityManager() { return this->entityManager; }
void Map::setPlayer(Player* player) { this->player = player; }
void Map::setAltPlayer(Player* player2) { this->player2 = player2; }
void Map::setGhostSpawner(GhostSpawner* spawner) { this->ghostSpawner = spawner; }

void Map::tick() {
    this->entityManager->tick();
	this->getPlayer()->tick();
	this->ghostSpawner->tick();
}

void Map::render() {
    this->entityManager->render();
	this->getPlayer()->render();
}

void Map::keyPressed(int key) {
    this->getPlayer()->keyPressed(key);
	this->ghostSpawner->keyPressed(key);
}

void Map::keyReleased(int key) {
	this->getPlayer()->keyReleased(key);
}

Map::~Map() {
	delete this->getPlayer();
	delete this->entityManager;
	delete this->ghostSpawner;
}