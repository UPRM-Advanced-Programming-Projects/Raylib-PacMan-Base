#include "Entity.hpp"

void Entity::update() {
    this->ticks++;
}

void Entity::draw() {
    DrawTexturePro(ImageManager::spriteSheet, this->textureBounds, 
                   Rectangle { this->x, this->y, this->width, this->height },
                   Vector2 {0, 0}, 0, WHITE);
}

bool Entity::collision(Entity* entity) {
    return CheckCollisionRecs(this->getBounds(), entity->getBounds());
}

Rectangle Entity::getBounds() {
    return (Rectangle){this->x, this->y, this->width, this->height};
}

Rectangle Entity::getBounds(float x, float y) {
    return (Rectangle){x, y, width, height};
}

Entity::~Entity() {}