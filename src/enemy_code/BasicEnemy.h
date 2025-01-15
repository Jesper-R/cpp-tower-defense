#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"

class BasicEnemy : public Enemy {
public:
    ~BasicEnemy();
    BasicEnemy();
    void move() override;
};

#endif //BASICENEMY_H