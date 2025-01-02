//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "../GameObject.h";
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class GameMap;

class Enemy : public GameObject {
    float health;
    float speed;
    int value;
    sf::Vector2i startPos;
    sf::Vector2i currentPos;
    vector<sf::Vector2i> turnLocs;
    vector<sf::Vector2i> pathFindingData;
    sf::Vector2i endPos;
public:
    Enemy(float health, float speed, int value, const std::string& textureFile);
    void takeDamage(float damage);
    void die();
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow& window);
    virtual void move();
    //void setPath(const sf::Vector2i& start, const sf::Vector2i& end);
    void setPath(GameMap* map);
    vector<sf::Vector2i> getPathFindingData() const { return pathFindingData; }
    void setPos(sf::Vector2f pos) { currentPos = sf::Vector2i(pos); }
    sf::Vector2i getStartPos() const { return startPos; }
    sf::Vector2i getCurrentPos() const { return currentPos; }
    sf::Vector2i getEndPos() const { return endPos; }
    void setCurrentPos(sf::Vector2i pos) { currentPos = pos; setPosition(sf::Vector2f(pos)); }
    float getSpeed() const { return speed; }
};



#endif //ENEMY_H
