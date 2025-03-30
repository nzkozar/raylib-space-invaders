#pragma once
#include <raylib.h>

class Alien{
    public:
        Alien(int type, Vector2 position);
        void Update(int direction);
        void Draw();
        int GetType();
        Texture2D GetImage();
        Rectangle GetRect();
        static void UnloadImages();
        static Texture2D images[3];
        int type;
        Vector2 position;
    private:

};