//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "Enemy.h"

Enemy::Enemy(float health, float speed, int value, const std::string& textureFile)
    : GameObject(textureFile), health(health), speed(speed), value(value) {
}
