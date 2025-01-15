#ifndef WIZARD_H
#define WIZARD_H
#include "Tower.h"

class Wizard : public Tower {
    vector<sf::Vector2i> getTargetPositions(WaveManager& waveManager);
public:
    ~Wizard();
    Wizard(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player& player);
    void attack(WaveManager& waveManager, ProjectileManager& projectileManager) override;
};

#endif //WIZARD_H
