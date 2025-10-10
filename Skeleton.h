#pragma once
#include <SFML/Graphics.hpp>


class Skeleton {
    sf::Texture Texture;
    sf::Font font;
    sf::Text healthText;

public:
    int health;
    sf::Sprite sprite;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
public:
    Skeleton();
    ~Skeleton();

    void ReduceHealth(int hp);

    void Load();
    void Draw(sf::RenderWindow& window);
    void Initialize();
    void Update(double deltaTime);
};




