#include "BigEnemy.h"
#include <cmath>
#include <iostream>

BigEnemy::~BigEnemy() {
    std::cout << "BigEnemy destroyed" << std::endl;
}

BigEnemy::BigEnemy() : Enemy(200.0f, 1.5f, 50, "../src/assets/enemies/BigEnemy.png", 20) {
    this->armor = 5;
    deltaTime = clock.getElapsedTime().asSeconds();
}

void BigEnemy::move() {
    if (!isMoving) return;
    vector<sf::Vector2i> path = getPathFindingData();
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

void BigEnemy::update(float deltaTime) {
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