#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"


class GameObject {
    sf::Vector2f position = sf::Vector2f(0, 0);
    sf::Sprite sprite;
    sf::Texture texture;
public:
    GameObject(std::string textureFile);
    void setTexture(const std::string& textureFile);
    sf::Sprite* getSprite();
    sf::Texture getTexture() const;
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);
};



#endif //GAMEOBJECT_H
