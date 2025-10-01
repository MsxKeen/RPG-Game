#include "FrameRates.h"
#include <iostream>

FrameRates::FrameRates() :timer(0) {
    // timer=0; same as  :timer(0)
 std::cout<<"I have been created"<<std::endl;
}
FrameRates::~FrameRates() {
    std::cout<<"I have been destroyed"<<std::endl;

}


void FrameRates::Initialize() {

}
void FrameRates::Load() {
    if(font.loadFromFile("C:/Users/mertc/CLionProjects/RPG-Game/Assets/Fonts/WonderFont.ttf")) {
        std::cout<<"Font loaded"<<std::endl;
        frameRateText.setFont(font);
    }else {
        std::cout<<"Font Error"<<std::endl;
    }
}
void FrameRates::Update(double deltaTime) {
    timer += deltaTime; //16.666667 ms 60 fps
    if(timer>100.0) { //updating the frame every x millisecond

        double fps=1000.0/deltaTime;
        frameRateText.setString("FPS: "+ std::to_string((int)fps)+ " frameTime: "+std::to_string((int)deltaTime));
        timer =0;
    }
}
void FrameRates::Draw(sf::RenderWindow& window) {
    window.draw(frameRateText);
}

