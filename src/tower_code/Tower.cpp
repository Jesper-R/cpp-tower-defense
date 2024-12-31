//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "Tower.h"

Tower::Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player): GameObject(textureFile), range(range), damage(damage), cost(cost), attackSpeed(attackSpeed) {
    player->removeMoney(cost);
}

void Tower::attack() {
}

void Tower::setTarget(Enemy *enemy) {
}

void Tower::setTowerPos(sf::Vector2i pos) {
    this->towerPos = pos;
}

void Tower::update() {
}

void Tower::render(sf::RenderWindow &window) { // implement dynamic bindning, some towers will have their own rendering? some will use this one
    sf::Sprite sprite = getSprite();
    sprite.setPosition(sf::Vector2f(this->towerPos));
    window.draw(sprite);
}
