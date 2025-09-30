#include <math.h>
#include "Math.h"
sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x+ vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x=vector.x/m;
    normalizedVector.y=vector.y/m;

    return normalizedVector;
}
/*
 *rect1.righ>rect2.left&&
 *rect2.right>rect1.left &&
 *
 *rec2.bottom >rect1.top &&
 *rec1.bottom > rect2.top
 */
bool Math::DidRectCollide(sf::FloatRect rect1,sf::FloatRect rect2) {
    if(rect1.left+rect1.width > rect2.left &&
        rect2.left+rect2.width > rect1.left&&

        rect2.top+rect2.height > rect1.top &&
        rect1.top+rect1.height > rect2.top)
        return true;

    return false;
}