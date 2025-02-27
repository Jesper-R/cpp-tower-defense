#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>

#include "Player.h"

class UIManager {
    sf::Font font;
    sf::Text livesText;
    sf::Text moneyText;
    sf::Texture coinTexture;
    sf::Sprite coinSprite;
    sf::Texture heartTexture;
    sf::Sprite heartSprite;
public:
    UIManager();
    void renderUI(sf::RenderWindow &window, Player &player);
    void updateUI(Player* player);
    void initUI();
};



#endif //UIMANAGER_H
