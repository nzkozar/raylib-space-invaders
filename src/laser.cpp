#include "laser.hpp"

Laser::Laser(Vector2 position, int speed){
    this -> position = position;
    this -> speed = speed;
    isActive = true;
}

void Laser::Draw(){
    if(isActive){
        DrawRectangle(position.x,position.y,WIDTH,HEIGHT,YELLOW);
    }
}

Rectangle Laser::GetRect(){
    return {position.x,position.y,WIDTH,HEIGHT};
}

void Laser::Update(){
    position.y += speed;
    if(isActive){
        if(position.y > GetScreenHeight() - 100 || position.y < 25){
            isActive = false;
        }
    }
}