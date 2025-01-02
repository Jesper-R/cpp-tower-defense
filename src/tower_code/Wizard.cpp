//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "Wizard.h"

Wizard::Wizard(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player *player): Tower(range, damage, attackSpeed, cost, textureFile, player, nullptr) {
    //setProjectileManager(projectileManager);
}

void Wizard::attack(WaveManager* waveManager) {
    //Tower::attack();
}

void Wizard::render(sf::RenderWindow &window) {
    Tower::render(window);
}
