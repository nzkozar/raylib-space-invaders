#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship{

    const int LASER_SPEED = -7;

    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();
        void TakeDamage();
        Rectangle GetRect() const;
        void Reset();
        std::vector<Laser> lasers;
    private:
        void InitPosition();
        Texture2D image{};
        Texture2D imageDamaged{};
        Vector2 position{};
        double lastFiredTime;
        Sound laserSound{};

        bool justDamaged;
        double lastDamagedTime;
        bool displayingAsDamaged;
};