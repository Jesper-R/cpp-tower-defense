#include "StoneThrower.h"
#include <iostream>

StoneThrower::StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player* player, ProjectileManager* projectileManager, WaveManager* waveManager): Tower(range, damage, attackSpeed, cost, textureFile, player, waveManager) {
    setProjectileManager(projectileManager);
}

void StoneThrower::attack(WaveManager* waveManager) {
    sf::Vector2i targetPos = getTargetPos(waveManager);
    if (targetPos == sf::Vector2i(-1, -1)) return;
    std::cout << "StoneThrower attack" << std::endl;
    getProjectileManager()->addProjectile(sf::Vector2i(this->getPosition()), sf::Vector2i(targetPos), 10, 10, "../src/assets/projectiles/stone.png", waveManager);
}

// works but calculates the range a bit off since position is in the bottom left corner of the tower and enemy
// should add some sort of getCenterPos() function to GameObject
sf::Vector2i StoneThrower::getTargetPos(WaveManager* waveManager) {
    vector<Enemy*> enemies = waveManager->getEnemies();
    for (auto enemy : enemies) {
        sf::Vector2f enemyPos = enemy->getPosition();
        int range = getRange();
        if (enemyPos.x >= getPosition().x - range && enemyPos.x <= getPosition().x + range && enemyPos.y >= getPosition().y - range && enemyPos.y <= getPosition().y + range) {
            cout << "Enemy in range" << endl;
            return sf::Vector2i(enemyPos) + sf::Vector2i(16, -16);
        }
    }
    cout << "No enemy in range" << endl;
    return sf::Vector2i(-1, -1);
}
