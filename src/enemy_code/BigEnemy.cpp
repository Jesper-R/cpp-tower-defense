//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "BigEnemy.h"

#include <iostream>

BigEnemy::BigEnemy() : Enemy(200.0f, 1.5f, 50, "../src/assets/enemies/BigEnemy.png") {
    this->armor = 10;
    deltaTime = clock.getElapsedTime().asSeconds();
}

void BigEnemy::move() {

    if (!isMoving) return;

    vector<sf::Vector2i> path = getPathFindingData();
    //path[0] = sf::Vector2i(path[0].x + 64, path[0].y);
    if (currentTargetIndex >= path.size()) return;
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

void BigEnemy::update(float deltaTome) {
    //deltaTime = clock.getElapsedTime().asSeconds();
    deltaTime = deltaTome;
    //Enemy::update(deltaTome); look into eventual virtual here
    std::cout << "BigEnemy update: current deltaTime " + to_string(clock.getElapsedTime().asSeconds()) << std::endl;
    //moveTimer += deltaTome;
    if (isMoving) {
        moveTimer += deltaTime;
        if (moveTimer >= moveInterval) {
            isMoving = false;
            sleepTimer = 0.0f;
            moveTimer = 0.0f;
        }
    } else {
        sleepTimer += deltaTime;
        if (sleepTimer >= sleepTime) {
            isMoving = true;
            sleepTimer = 0.0f;
        }
    }

    if (isMoving) {
        move();
    }
}

void BigEnemy::render(sf::RenderWindow &window) {
    sf::Sprite sprite = getSprite();
    sprite.setPosition(sf::Vector2f(this->getCurrentPos()));
    window.draw(sprite);
}
