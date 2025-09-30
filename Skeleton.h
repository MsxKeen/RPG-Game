#pragma once
#include <SFML/Graphics.hpp>


class Skeleton {
    sf::Texture Texture;
public:
    sf::Sprite Sprite;

public:
    void Load();
    void Draw(sf::RenderWindow& window);
    void Initialize();
    void Update();
};




