#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "TowerManager.h"
#include "wave_code/WaveManager.h"
#include "map_code/GameMap.h"
#include "UIManager.h"

class Game
{
private:
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;
    static const int GRID_SIZE = 64;
    static const int GRID_WIDTH = WIDTH / GRID_SIZE;
    static const int GRID_HEIGHT = HEIGHT / GRID_SIZE;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time timePerFrame;
    sf::Time elapsedTimeSinceLastUpdate;
    GameMap gameMap;
    UIManager uiManager;
    Player player;
    WaveManager waveManager;
    TowerManager towerManager;
    ProjectileManager projectileManager;



    void handleEvents();
    void update();
    void render();
public:
    Game();
    ~Game();
    void run();
};
