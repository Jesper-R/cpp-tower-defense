#include "ProjectileManager.h"

void ProjectileManager::addProjectile(sf::Vector2i towerPos, sf::Vector2i targetPos, float velocity, float damage,
    const string &textureFile) {
    projectiles.push_back(new Projectile(velocity, damage, textureFile, sf::Vector2f(towerPos), sf::Vector2f(targetPos)));
}

void ProjectileManager::update() {
    for (auto& projectile : projectiles) {
        projectile->update();
    }
}

void ProjectileManager::render(sf::RenderWindow &window) {
    for (auto& projectile : projectiles) {
        projectile->render(window);
    }
}
