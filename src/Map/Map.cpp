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
    return this->player;
}

EntityManager* Map::getEntityManager() { return this->entityManager; }
void Map::setPlayer(Player* player) { this->player = player; }
void Map::setGhostSpawner(GhostSpawner* spawner) { this->ghostSpawner = spawner; }

void Map::update() {
    this->entityManager->update();
	this->getPlayer()->update();
	this->ghostSpawner->update();
}

void Map::draw() {
    this->entityManager->draw();
	this->getPlayer()->draw();
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