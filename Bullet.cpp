#include "Bullet.h"
#include "Math.h"

Bullet::Bullet():speed(0) {

}
Bullet::~Bullet() {

}


void Bullet::Initialize(const sf::Vector2f& target,const sf::Vector2f& position,float speed) {
    this->speed=speed;//same as rename the private speed to m_speed so in this case code ->    m_speed =speed
    // this(class)->(pointing)speed(variable inside of the class) =  speed(speed inside of initialize function)
     rectangleShape.setSize(sf::Vector2f(50,25));
    rectangleShape.setPosition(position);
    direction = Math::NormalizeVector(target-position);
}
void Bullet::Load() {

}
void Bullet::Update(float deltaTime) {
    rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}
void Bullet::Draw(sf::RenderWindow& window) {
    window.draw(rectangleShape);
}


