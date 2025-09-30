#pragma once
#include <SFML/Graphics.hpp>

class Math {
public:
    static sf::Vector2f NormalizeVector(sf::Vector2f vector);//without need to create object,if u have 3 player with static hp and 3 of them will have the same hp
    static bool DidRectCollide(sf::FloatRect rect1,sf::FloatRect rect2);
};


