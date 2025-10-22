#include "Entity.hpp"

void Entity::tick() {
    this->ticks++;
}

void Entity::render() {
    DrawTextureEx(entityTexture, (Vector2){x, y}, 0, 1, (Color){255, 255, 255, 255});
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