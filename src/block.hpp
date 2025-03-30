#pragma once
#include <raylib.h>

class Block{
    public:
        Block(Vector2 position);
        void Draw();
        Rectangle GetRect();
        static const int SIDE_LENGTH = 3;
    private:
        Vector2 position;
};