#include "Game.h"
#include <iostream>

#include "map_code/GameMap.h"



void Game::handleEvents()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
        {
            std::cout << "Pressed key 1" << std::endl;
            sf::Vector2i gridLoc = gameMap.pixelToGrid(sf::Mouse::getPosition(window));
            //cout << "gridLoc: " << gridLoc.x << ", " << gridLoc.y << endl;
            //sf::Vector2i pixelLoc = gameMap.gridToPixel(gridLoc);
            towerManager.placeTower(gridLoc, "basic", gameMap, player);
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
            std::cout << "Pressed key 2" << std::endl;
            sf::Vector2i gridLoc = gameMap.pixelToGrid(sf::Mouse::getPosition(window));
            //cout << "gridLoc: " << gridLoc.x << ", " << gridLoc.y << endl;
            //sf::Vector2i pixelLoc = gameMap.gridToPixel(gridLoc);
            towerManager.placeTower(gridLoc, "wizard", gameMap, player);
        }
    }
}

void Game::update()
{
    elapsedTimeSinceLastUpdate += clock.restart();
    //std::cout << "Elapsed time: " << elapsedTimeSinceLastUpdate.asSeconds() << std::endl;

    while (elapsedTimeSinceLastUpdate > timePerFrame)
    {
        elapsedTimeSinceLastUpdate -= timePerFrame;
        //std::cout << "Updated elapsedTimeSinceLastUpdate: " << elapsedTimeSinceLastUpdate.asSeconds() << std::endl;
    }
    waveManager.update(player, window, gameMap);
    gameMap.update();
    uiManager.updateUI(&player);
    towerManager.update(waveManager, projectileManager);
    projectileManager.update(waveManager, window);
}

void Game::render()
{
    this->window.clear();
    /*sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Red);
    this->window.draw(shape);
    for (int i = 0; i < GRID_HEIGHT * GRID_WIDTH; ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile("../src/assets/paths/0000/grass.png"))
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        sf::Sprite sprite;
        sprite.setPosition(i % GRID_WIDTH * GRID_SIZE, i / GRID_WIDTH * GRID_SIZE);
        sprite.setTexture(texture);
        this->window.draw(sprite);
    }*/

    gameMap.render(this->window);
    uiManager.renderUI(this->window, player);
    waveManager.render(this->window);
    towerManager.render(this->window);
    projectileManager.render(this->window);
    this->window.display();
}

Game::Game()
    : timePerFrame(sf::seconds(1.f / 60.f)),
      elapsedTimeSinceLastUpdate(sf::Time::Zero){

    try {
        gameMap.loadMapFromFile("../src/map.json");
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    int width = gameMap.getGridWidth() * GRID_SIZE;
    int height = gameMap.getGridHeight() * GRID_SIZE;

    this->window.create(sf::VideoMode(width, height), "Pixel Defense");

    player.setLives(gameMap.getStartingLives());
    player.setMoney(gameMap.getStartingMoney());
    uiManager.initUI();


    try {
        waveManager.loadWaveData();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    waveManager.startWaveSpawning(gameMap);
}

Game::~Game()
{
    //delete this->balloon;
}

void Game::run()
{
    while (this->window.isOpen())
    {
        //std::cout << "Running loop..." << std::endl;
        handleEvents();
        update();
        render();
    }
}
