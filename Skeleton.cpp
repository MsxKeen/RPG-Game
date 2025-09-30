#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {

}
void Skeleton::Update() {

}
void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(Sprite);
}
void Skeleton::Load() {
    if(Texture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Skeleton/Textures/SpriteSheet.png")){
        std::cout<<"Player Texture Loaded"<<std::endl;
        Sprite.setTexture(Texture);
        Sprite.setPosition(sf::Vector2f(400,100));


        //X, Y, Width, Height
        int XIndex=0;
        int YIndex=2;
        Sprite.setTextureRect(sf::IntRect(XIndex*64,YIndex*64,64,64));
        Sprite.setScale(sf::Vector2f(3,3));


    } else {std::cout<<"Player Texture Error"<<std::endl;}
}


