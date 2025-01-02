//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef WIZARD_H
#define WIZARD_H
#include "Tower.h"


class Wizard : public Tower {
public:
    Wizard(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player);
    void attack(WaveManager* waveManager) override;
    void render(sf::RenderWindow& window) override;

};



#endif //WIZARD_H
