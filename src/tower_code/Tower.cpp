#include "Tower.h"
#include <iostream>

sf::Vector2i Tower::getTargetPos(WaveManager *waveManager) {
    vector<Enemy*> enemies = waveManager->getEnemies();
    for (auto enemy : enemies) {
        sf::Vector2f enemyPos = enemy->getPosition();
        int range = getRange();
        if (enemyPos.x >= getPosition().x - range && enemyPos.x <= getPosition().x + range && enemyPos.y >= getPosition().y - range && enemyPos.y <= getPosition().y + range) {
            cout << "Enemy in range" << endl;
            return sf::Vector2i(enemyPos) + sf::Vector2i(16, -16);
        }
    }
    cout << "No enemy in range" << endl;
    return sf::Vector2i(-1, -1);
}

Tower::Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player, WaveManager* waveManager): GameObject(textureFile), range(range), damage(damage), cost(cost), attackSpeed(attackSpeed), waveManager(waveManager) {
    player->removeMoney(cost);
}

void Tower::setTowerPos(sf::Vector2i pos) {
    this->towerPos = pos;
    setPosition(sf::Vector2f(pos));
}

void Tower::setProjectileManager(ProjectileManager *projectileManager) {
    this->projectileManager = projectileManager;
}

int Tower::getRange() const {
    return this->range;
}

ProjectileManager * Tower::getProjectileManager() const {
    return this->projectileManager;
}

void Tower::update(float deltaTime) {
    attackTimer += deltaTime;
    if (attackTimer >= attackSpeed) {
        attack(this->waveManager); // attack is a virtual function, so it will call the correct attack function for the tower type
        attackTimer = 0.0f;
    }
}

void Tower::attack(WaveManager *waveManager) {
    sf::Vector2i targetPos = getTargetPos(waveManager);
    if (targetPos == sf::Vector2i(-1, -1)) return;
    std::cout << "StoneThrower attack" << std::endl;
    getProjectileManager()->addProjectile(sf::Vector2i(this->getPosition()), sf::Vector2i(targetPos), 10, 10, "../src/assets/projectiles/stone.png", *waveManager);
}

void Tower::render(sf::RenderWindow &window) { // implement dynamic bindning, some towers will have their own rendering? some will use this one
    sf::Sprite* sprite = getSprite();
    sprite->setPosition(sf::Vector2f(this->towerPos));
    window.draw(*sprite);
}
