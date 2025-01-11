//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef BIGENEMY_H
#define BIGENEMY_H
#include "Enemy.h"


class BigEnemy : public Enemy {
    int armor;
    int currentTargetIndex = 0;
    bool isMoving = true;
    float moveTimer = 0.0f;
    const float moveInterval = 5.0f;
    float sleepTime = 2.0f;
    float sleepTimer = 0.0f;
    float deltaTime;
    sf::Clock clock;
public:
    BigEnemy();
    void move() override;
    void update(float deltaTime) override;
    int getArmor() const { return armor; }
};



#endif //BIGENEMY_H
