#ifndef WIZARD_H
#define WIZARD_H
#include "Tower.h"

class Wizard : public Tower {
public:
    Wizard(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player, ProjectileManager* projectileManager, WaveManager* waveManager);
    vector<sf::Vector2i> getTargetPositions(WaveManager* waveManager);
    void attack(WaveManager* waveManager) override;
};

#endif //WIZARD_H
