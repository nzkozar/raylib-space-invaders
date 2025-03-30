#pragma once
#include "colors.h"
#include "Spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game{
    public:
        Game(); //Constructor
        ~Game(); //Destructor
        void Draw();
        void DrawUI();
        void Update();
        void HandleInput();
        bool run;
        int score;
        int highscore;
        Music music;
    private:
        void DeleteInactiveLasers();
        void CreateObstacles();
        void CreateAliens();
        void MoveAliens();
        void MoveDownAliens(int distance);
        void AlienShootLaser();
        void CheckForCollisions();
        void GameOver();
        void Reset();
        void InitGame();
        void AddScore(int scoreIncrease);
        void SaveHighscore(int highscore);
        int LoadHighscore();
        void LevelComplete();

        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        std::vector<Laser> alienLasers;
        int aliensDirection;
        constexpr static float alienLaserShootInterval = 0.45;
        float lastAlienLaserFiredTime;
        MysteryShip mysteryShip;
        float mysteryShipSpawnInterval;
        float mysteryShipLastSpawnTime;
        int lives;
        Font font;
        Texture2D spaceshipImage;
        Sound explosionSound;
};
