#include "Player.h"

Player::Player() {
}

int Player::getLives() {
    return this->lives;
}

int Player::getMoney() {
    return this->money;
}

void Player::setLives(int lives) {
    this->lives = lives;
}

void Player::setMoney(int money) {
    this->money = money;
}

void Player::addMoney(int money) {
    this->money += money;
}

void Player::removeMoney(int money) {
    this->money -= money;
}

void Player::removeLife(int life) {
    this->lives -= life;
}

void Player::update(sf::RenderWindow& window) const {
    if (lives <= 0) {
        window.close();
    }
}
