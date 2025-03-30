#include "alien.hpp"
#include <string>

Texture2D Alien::images[3] = {};

Alien::Alien(int type, Vector2 position){
    this -> type = type;
    this -> position = position;

    if(images[type-1].id == 0){
        //Load texture into images static variable
        if(type >= 1 && type <= 3){
            std::string assetPath = "../Graphics/alien_" + std::to_string(type) + ".png";
            images[type-1] = LoadTexture(assetPath.c_str());
        }else{
            images[0] = LoadTexture("../Graphics/alien_1.png");
        }
    }

    
}

void Alien::Update(int direction){
    position.x += direction;
}

void Alien::Draw(){
    DrawTextureV(images[type-1],position,WHITE);
}

int Alien::GetType(){
    return type;
}

Texture2D Alien::GetImage(){
    return images[type-1];
}

Rectangle Alien::GetRect(){
    return {position.x,position.y,float(GetImage().width),float(GetImage().height)};
}

void Alien::UnloadImages(){
    for(int i = 0;i<3;i++){
        UnloadTexture(images[i]);
    }
}
