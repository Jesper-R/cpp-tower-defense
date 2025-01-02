//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "Enemy.h"

#include <iostream>

#include "../map_code/GameMap.h"

Enemy::Enemy(float health, float speed, int value, const std::string& textureFile, int damage)
    : GameObject(textureFile), health(health), speed(speed), value(value), damage(damage) {
}

void Enemy::takeDamage(float damage) {
    this->health -= damage;
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

}

void Enemy::render(sf::RenderWindow &window) {
}

void Enemy::move() {
}

void Enemy::setPath(GameMap *map) {
    pathFindingData.push_back(map->gridToPixel(map->getStartGridLoc()));
    for (auto loc : map->getTurnGridLocs()) {
        pathFindingData.push_back(map->gridToPixel(loc));
    }
    pathFindingData.push_back(map->gridToPixel(map->getEndGridLoc()));

    /*this->startPos = map->gridToPixel(map->getStartGridLoc());
    this->endPos = map->gridToPixel(map->getEndGridLoc());

    for (auto loc : map->getTurnGridLocs()) {
        this->turnLocs.push_back(map->gridToPixel(loc));
    }

    this->turnLocs.push_back(endPos);*/
}

/*void Enemy::setPath(const sf::Vector2i &start, const sf::Vector2i &end) { // add turn locs here later for pathfinding
    sf::Vector2i convertedStart = start;
    sf::Vector2i convertedEnd = end;
    // convert from grid to pixel, 704 window height, 64 item height, 64*y grid height
    this->startPos = sf::Vector2i(start.x * 64, 704 - 64 - (64 * start.y));
    this->currentPos = startPos;
    this->endPos = sf::Vector2i(end.x * 64, 704 - 64 - (64 * end.y));
}*/

