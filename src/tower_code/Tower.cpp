//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "Tower.h"

#include <iostream>

Tower::Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player, WaveManager* waveManager): GameObject(textureFile), range(range), damage(damage), cost(cost), attackSpeed(attackSpeed), waveManager(waveManager) {
    player->removeMoney(cost);
}

void Tower::attack(WaveManager* waveManager) {
    std::cout << "Tower attack" << std::endl;
}

void Tower::setTarget(Enemy *enemy) {
}

void Tower::setTowerPos(sf::Vector2i pos) {
    this->towerPos = pos;
    setPosition(sf::Vector2f(pos));
}

void Tower::update(float deltaTime) {
    attackTimer += deltaTime;
    if (attackTimer >= attackSpeed) {
        attack(this->waveManager); // attack is a virtual function, so it will call the correct attack function for the tower type
        attackTimer = 0.0f;
    }
}

void Tower::render(sf::RenderWindow &window) { // implement dynamic bindning, some towers will have their own rendering? some will use this one
    sf::Sprite* sprite = getSprite();
    sprite->setPosition(sf::Vector2f(this->towerPos));
    window.draw(*sprite);
}
