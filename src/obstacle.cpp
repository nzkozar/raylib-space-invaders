#include "obstacle.hpp"

std::vector<std::vector<unsigned int>> Obstacle::grid =  {
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}
};

Obstacle::Obstacle(Vector2 position){
    this -> position = position;

    for(unsigned int row = 0; row < grid.size(); ++row){
        for(unsigned int col = 0; col < grid[row].size(); ++col){
            if(grid[row][col] == 1){
                float pos_x = position.x + col * Block::SIDE_LENGTH;
                float pos_y = position.y + row * Block::SIDE_LENGTH;
                blocks.push_back(Block({pos_x,pos_y}));
            }
        }
    }
}

void Obstacle::Draw(){
    for(Block& block: blocks){
        block.Draw();
    }
}
