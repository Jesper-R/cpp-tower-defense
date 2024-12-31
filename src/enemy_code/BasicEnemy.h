//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"


class BasicEnemy : public Enemy {
    int currentTargetIndex = 0;
public:
    BasicEnemy();
    void move() override;
    void update(float deltaTome) override;
    void render(sf::RenderWindow& window) override;
};



#endif //BASICENEMY_H
