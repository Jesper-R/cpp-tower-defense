#include "Projectile.h"

#include <iostream>

#include "ProjectileManager.h"

void Projectile::applyDamage() {
}

Projectile::Projectile(float velocity, float damage, const std::string &textureFile, sf::Vector2f startPos, sf::Vector2f targetPos, WaveManager* waveManager, ProjectileManager* projectileManager): GameObject(textureFile), velocity(velocity), damage(damage), targetPos(targetPos), startPos(startPos), waveManager(waveManager), projectileManager(projectileManager) {
    this->currentPos = startPos;
    std::cout << "Projectile constructor" << std::endl;
    this->direction = sf::Vector2f(targetPos) - sf::Vector2f(currentPos);
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
}

void Projectile::checkCollision(WaveManager* waveManager) {
    vector<Enemy*> enemies = waveManager->getEnemies();
    for (auto enemy : enemies) {
        if(enemy->getSprite()->getGlobalBounds().intersects(this->getSprite()->getGlobalBounds())) {
            enemy->takeDamage(damage);
            hit = true;
            std::cout << "Collision" << std::endl;
            //return true;
        }
    }
    //return false;
}

void Projectile::update() {
    move();
    checkCollision(waveManager);

}

void Projectile::move() {
    currentPos += sf::Vector2f(direction * velocity);
    setPosition(currentPos);
}

void Projectile::render(sf::RenderWindow &window) {
    sf::Sprite* sprite = getSprite();
    sprite->setPosition(sf::Vector2f(this->currentPos + sf::Vector2f(24, 24))); // offset because sprite is 16x16 and we want it centered on the grid cell
    window.draw(*sprite);
}
