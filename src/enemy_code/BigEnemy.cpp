//
// Created by Jesper Rudegran on 2024-12-28.
//

#include "BigEnemy.h"

BigEnemy::BigEnemy() : Enemy(200.0f, 1.0f, 50, "../src/assets/enemies/BigEnemy.png") {
    this->armor = 10;
}

void BigEnemy::move() {
}
