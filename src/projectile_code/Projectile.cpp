#include "Projectile.h"

#include <cmath>
#include <iostream>
#include "ProjectileManager.h"
#include "../enemy_code/BigEnemy.h"

Projectile::Projectile(float velocity, float damage, const std::string &textureFile, sf::Vector2f startPos, sf::Vector2f targetPos): GameObject(textureFile), velocity(velocity), damage(damage), targetPos(targetPos), startPos(startPos){
    this->currentPos = startPos;
    this->direction = sf::Vector2f(targetPos) - sf::Vector2f(currentPos);
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
}

void Projectile::checkCollision(WaveManager& waveManager) {
    vector<Enemy*> enemies = waveManager.getEnemies();
    for (auto enemy : enemies) {
        if(enemy->getSprite()->getGlobalBounds().intersects(this->getSprite()->getGlobalBounds())) {
            BigEnemy* bigEnemy = dynamic_cast<BigEnemy*>(enemy);
            if(bigEnemy) {
                int armor = bigEnemy->getArmor();
                bigEnemy->takeDamage(damage, armor);
            } else {
                enemy->takeDamage(damage);
            }

            hit = true;
        }
    }
}

void Projectile::update(WaveManager& waveManager) {
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

bool Projectile::hasHit() const {
    return this->hit;
}
