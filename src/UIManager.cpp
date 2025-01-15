#include "UIManager.h"

#include <iostream>

UIManager::UIManager() {
}

void UIManager::renderUI(sf::RenderWindow &window, Player &player) {
    livesText.setString(std::to_string(player.getLives()));
    moneyText.setString(std::to_string(player.getMoney()));

    window.draw(livesText);
    window.draw(heartSprite);

    window.draw(coinSprite);
    window.draw(moneyText);
}

void UIManager::updateUI(Player *player) {
    livesText.setString(std::to_string(player->getLives()));
    moneyText.setString(std::to_string(player->getMoney()));
}

void UIManager::initUI() {
    if (!font.loadFromFile("../src/assets/ByteBounce.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
    }

    livesText.setFont(font);
    livesText.setCharacterSize(64);
    livesText.setFillColor(sf::Color::White);
    livesText.setOutlineThickness(1);
    livesText.setOutlineColor(sf::Color::Black);
    livesText.setPosition(68, 70 - 30);

    moneyText.setFont(font);
    moneyText.setCharacterSize(64);

    moneyText.setLineSpacing(0.1f);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setOutlineThickness(1);
    moneyText.setOutlineColor(sf::Color::Black);
    moneyText.setPosition(68, 20 - 30);

    if (!coinTexture.loadFromFile("../src/assets/UI/coin.png")) {
        std::cerr << "Failed to load coin texture" << std::endl;
    }

    if (!heartTexture.loadFromFile("../src/assets/UI/heart.png")) {
        std::cerr << "Failed to load heart texture" << std::endl;
    }

    coinSprite.setTexture(coinTexture);
    coinSprite.setScale(3.f, 3.f);
    coinSprite.setPosition(10, 10);

    heartSprite.setTexture(heartTexture);
    heartSprite.setScale(3.f, 3.f);
    heartSprite.setPosition(10, 60);
}
