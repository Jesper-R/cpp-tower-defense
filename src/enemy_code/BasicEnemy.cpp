//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "BasicEnemy.h"

BasicEnemy::BasicEnemy() : Enemy(100.0f, 2.0f, 10, "../src/assets/enemies/BasicEnemy.png") {

}

void BasicEnemy::move() {
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

void BasicEnemy::update(float deltaTime) {
    /*sf::Vector2i currentPos = getCurrentPos();
    currentPos.x += 1 * getSpeed();
    this->setPos(sf::Vector2f(currentPos));*/
    move();

}

void BasicEnemy::render(sf::RenderWindow& window) {
    sf::Sprite sprite = getSprite();
    sprite.setPosition(sf::Vector2f(this->getCurrentPos()));
    window.draw(sprite);
}