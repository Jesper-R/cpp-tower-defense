#include "Wizard.h"
#include <iostream>

Wizard::Wizard(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player *player, ProjectileManager* projectileManager, WaveManager* waveManager): Tower(range, damage, attackSpeed, cost, textureFile, player, waveManager) {
    setProjectileManager(projectileManager);
}

vector<sf::Vector2i> Wizard::getTargetPositions(WaveManager *waveManager) {
    vector<Enemy*> enemies = waveManager->getEnemies();
    vector<sf::Vector2i> targetPositions;

    for (auto enemy : enemies) {
        sf::Vector2f enemyPos = enemy->getPosition();
        int range = getRange();
        if (enemyPos.x >= getPosition().x - range && enemyPos.x <= getPosition().x + range && enemyPos.y >= getPosition().y - range && enemyPos.y <= getPosition().y + range) {
            cout << "Enemy in range" << endl;
            targetPositions.push_back(sf::Vector2i(enemyPos) + sf::Vector2i(16, -16));
        }
    }
    return targetPositions;
}

void Wizard::attack(WaveManager* waveManager) {
    std::cout << "Wizard attack" << std::endl;
    vector<sf::Vector2i> targetPositions = getTargetPositions(waveManager);
    if (targetPositions.empty()) return;
    for (auto pos : targetPositions) {
        getProjectileManager()->addProjectile(sf::Vector2i(this->getPosition()), pos, 10, 10, "../src/assets/projectiles/fireball.png", waveManager);
    }
}
