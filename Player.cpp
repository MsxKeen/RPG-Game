#include "Player.h"
#include <iostream>
#include "Math.h"


void Player::Initialize() {

}
void Player::Load() {
    if(Texture.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Player/Textures/SpriteSheet.png")) {
        std::cout<<"Player Texture Loaded"<<std::endl;
       Sprite.setTexture(Texture);

        //X, Y, Width, Height
        int XIndex=0;
        int YIndex=00;
        Sprite.setTextureRect(sf::IntRect(XIndex*64,YIndex*64,64,64));
        Sprite.setScale(sf::Vector2f(3,3));
        Sprite.setPosition(sf::Vector2f(1650,800));
    }
    else {std::cout<<"Player Texture Error"<<std::endl;}
}
void Player::Update(Skeleton& skeleton) {
    sf::Vector2f position=Sprite.getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        Sprite.setPosition(position+ sf::Vector2f(1 ,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        Sprite.setPosition(position - sf::Vector2f(1,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        Sprite.setPosition(position + sf::Vector2f(0,1));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        Sprite.setPosition(position - sf::Vector2f(0,1));//or (position + sf::Vector2f(0,-10))
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));

        int i=bullets.size()-1;
        bullets[i].setPosition(Sprite.getPosition());
    }
    for(size_t i =0; i<bullets.size();i++) {
        sf::Vector2f bulletDirection = skeleton.Sprite.getPosition()-bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition()+ bulletDirection * bulletSpeed);

    }

}
void Player::Draw(sf::RenderWindow& window) {
    window.draw(Sprite);
    for(size_t i =0; i<bullets.size();i++) {
        window.draw(bullets[i]);
    }
}
