#include "Skeleton.h"
#include <iostream>
Skeleton::Skeleton() {

}
Skeleton::~Skeleton() {

}


void Skeleton::Initialize() {

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size=sf::Vector2i(64,64);
}
void Skeleton::Load() {
    if(Texture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Skeleton/Textures/SpriteSheet.png")){
        std::cout<<"Player Texture Loaded"<<std::endl;
        sprite.setTexture(Texture);
        sprite.setPosition(sf::Vector2f(400,100));


        //X, Y, Width, Height
        int XIndex=0;
        int YIndex=2;
        sprite.setTextureRect(sf::IntRect(XIndex*size.x,YIndex*size.y,size.x,size.y));
        sprite.setScale(sf::Vector2f(3,3));

        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x,size.y * sprite.getScale().y));


    } else {std::cout<<"Player Texture Error"<<std::endl;}
}
void Skeleton::Update(float deltaTime) {
    boundingRectangle.setPosition(sprite.getPosition());
}
void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}



