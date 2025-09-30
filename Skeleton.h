#pragma once
#include <SFML/Graphics.hpp>


class Skeleton {
    sf::Texture Texture;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
public:
    sf::Sprite sprite;

public:
    void Load();
    void Draw(sf::RenderWindow& window);
    void Initialize();
    void Update(float deltaTime);
};




