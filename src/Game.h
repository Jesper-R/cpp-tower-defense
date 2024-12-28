#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
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
    GameMap gameMap;
    WaveManager waveManager;
    UIManager uiManager;
    Player player;
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time timePerFrame;
    sf::Time elapsedTimeSinceLastUpdate;


    void handleEvents();
    void update();
    void render();
    void renderUI();
public:
    Game();
    ~Game();
    void run();
};
