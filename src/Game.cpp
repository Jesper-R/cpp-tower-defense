#include "Game.h"
#include <iostream>
using namespace std;

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
            cout << "Pressed key 1" << endl;
            sf::Vector2i gridLoc = gameMap.pixelToGrid(sf::Mouse::getPosition(window));
            towerManager.placeTower(gridLoc, "basic", gameMap, player);
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
            cout << "Pressed key 2" << endl;
            sf::Vector2i gridLoc = gameMap.pixelToGrid(sf::Mouse::getPosition(window));
            towerManager.placeTower(gridLoc, "wizard", gameMap, player);
        }
    }
}

void Game::update()
{
    elapsedTimeSinceLastUpdate += clock.restart();
    while (elapsedTimeSinceLastUpdate > timePerFrame)
    {
        elapsedTimeSinceLastUpdate -= timePerFrame;
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
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    int width = gameMap.getGridWidth() * GRID_SIZE;
    int height = gameMap.getGridHeight() * GRID_SIZE;

    this->window.create(sf::VideoMode(width, height), "Pixel Defense");

    player.setLives(gameMap.getStartingLives());
    player.setMoney(gameMap.getStartingMoney());
    uiManager.initUI();

    try {
        waveManager.loadWaveData();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    waveManager.startWaveSpawning(gameMap);
}

Game::~Game(){}

void Game::run()
{
    while (this->window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}
