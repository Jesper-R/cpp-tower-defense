#include "BasicEnemy.h"
#include <iostream>

BasicEnemy::~BasicEnemy() {
    std::cout << "BasicEnemy destroyed" << std::endl;
}

BasicEnemy::BasicEnemy() : Enemy(100.0f, 2.0f, 10, "../src/assets/enemies/BasicEnemy.png", 10) {
}