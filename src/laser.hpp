#pragma once
#include <raylib.h>

class Laser{
    public:
        Laser(Vector2 position,int speed);
        void Update();
        void Draw();
        bool isActive;
        Rectangle GetRect();
        static const int WIDTH = 4;
        static const int HEIGHT = 15;
    private:
        Vector2 position;
        int speed;
};
