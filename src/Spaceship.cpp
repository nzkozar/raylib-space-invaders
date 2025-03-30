#include "Spaceship.hpp"
#define SPACESHIP_SPEED 7

Spaceship::Spaceship(){
    image = LoadTexture("../Graphics/spaceship.png");
    imageDamaged = LoadTexture("../Graphics/spaceship_red.png");
    InitPosition();
    lastFiredTime = 0.0;
    justDamaged = false;
    lastDamagedTime = 0.0;
    displayingAsDamaged = false;

    laserSound = LoadSound("../Sounds/laser.ogg");
}

Spaceship::~Spaceship(){
    UnloadTexture(image);
    UnloadTexture(imageDamaged);
    UnloadSound(laserSound);
}

void Spaceship::Draw(){
    Texture2D texture = image;
    
    if(justDamaged){//TODO time since last change
        if(displayingAsDamaged){
            texture = image;
        }else{
            texture = imageDamaged;
        }
        displayingAsDamaged = !displayingAsDamaged;
        DrawTextureV(texture,position,WHITE);

        if(GetTime() - lastDamagedTime > 2.0){
            justDamaged = false;
        }
    }else{
        DrawTextureV(image,position,WHITE);
    }
}

void Spaceship::MoveLeft(){
    position.x -= SPACESHIP_SPEED;
    if(position.x<25){
        position.x = 25;
    }
}

void Spaceship::MoveRight(){
    position.x += SPACESHIP_SPEED;
    if(position.x>GetScreenWidth()-image.width - 25){
        position.x = GetScreenWidth()-image.width - 25;
    }
}

void Spaceship::FireLaser(){
    if(GetTime()-lastFiredTime >= 0.35){
        lasers.push_back(Laser({position.x + image.width/2 - Laser::WIDTH/2,position.y},LASER_SPEED));
        lastFiredTime = GetTime();
        PlaySound(laserSound);
    }
}

void Spaceship::TakeDamage(){
    justDamaged = true;
    lastDamagedTime = GetTime();
}

Rectangle Spaceship::GetRect() const {
    return {position.x,position.y,static_cast<float>(image.width),static_cast<float>(image.height)};
}

void Spaceship::Reset(){
    InitPosition();
    lasers.clear();
}

void Spaceship::InitPosition(){
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = GetScreenHeight() - image.height - 100;
}
