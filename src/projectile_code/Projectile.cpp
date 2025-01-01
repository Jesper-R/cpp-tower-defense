#include "Projectile.h"

#include <iostream>

void Projectile::applyDamage() {
}

Projectile::Projectile(float velocity, float damage, const std::string &textureFile, sf::Vector2f startPos, sf::Vector2f targetPos): GameObject(textureFile), velocity(velocity), damage(damage), targetPos(targetPos), startPos(startPos) {
    this->currentPos = startPos;
    std::cout << "Projectile constructor" << std::endl;
    this->direction = sf::Vector2f(targetPos) - sf::Vector2f(currentPos);
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
}

bool Projectile::checkCollision() {
}

void Projectile::update() {
    move();

}

void Projectile::move() {
    currentPos += sf::Vector2f(direction * velocity);
}

void Projectile::render(sf::RenderWindow &window) {
    sf::Sprite sprite = getSprite();
    sprite.setPosition(sf::Vector2f(this->currentPos + sf::Vector2f(24, 24))); // offset because sprite is 16x16 and we want it centered on the grid cell
    window.draw(sprite);
}
