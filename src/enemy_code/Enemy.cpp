//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "Enemy.h"

#include <cmath>
#include <iostream>

#include "../map_code/GameMap.h"

Enemy::Enemy(float health, float speed, int value, const std::string& textureFile, int damage)
    : GameObject(textureFile), health(health), speed(speed), value(value), damage(damage) {
}

void Enemy::takeDamage(float damage, int armor) {
    damage -= armor;
    if (damage > 0) {
        this->health -= damage;
    }
    std::cout << "Enemy took damage, health: " << this->health << std::endl;
    if (this->health <= 0) {
        dead = true;
        die();
    }
}

void Enemy::die() {
    std::cout << "Enemy died" << std::endl;
}

void Enemy::update(float deltaTime) {
    move();
}

void Enemy::render(sf::RenderWindow &window) {
    sf::Sprite* sprite = getSprite();
    sprite->setPosition(sf::Vector2f(this->getCurrentPos()));
    window.draw(*sprite);
}

void Enemy::move() {
    vector<sf::Vector2i> path = getPathFindingData();
    //path[0] = sf::Vector2i(path[0].x + 64, path[0].y);
    if (currentTargetIndex >= path.size()) {
        setReachedEnd(true);
        return;
    }
    if (currentTargetIndex == 0) {
        setCurrentPos(path[0]);
        currentTargetIndex++;
        return;
    }
    sf::Vector2i targetPos = path[currentTargetIndex];
    sf::Vector2i currentPos = getCurrentPos();
    sf::Vector2f direction = sf::Vector2f(targetPos - currentPos);
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
    currentPos += sf::Vector2i(direction * getSpeed());
    setCurrentPos(currentPos);
    if (length <= getSpeed()) {
        currentPos = targetPos;
        currentTargetIndex++;
    }
}

void Enemy::setPath(GameMap& map) {
    pathFindingData.push_back(map.gridToPixel(map.getStartGridLoc()));
    for (auto loc : map.getTurnGridLocs()) {
        pathFindingData.push_back(map.gridToPixel(loc));
    }
    pathFindingData.push_back(map.gridToPixel(map.getEndGridLoc()));
}
