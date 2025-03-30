#include "block.hpp"

Block::Block(Vector2 position){
    this -> position = position;
}

void Block::Draw(){
    DrawRectangle(position.x, position.y,SIDE_LENGTH,SIDE_LENGTH,YELLOW);
}

Rectangle Block::GetRect()
{
    return {position.x,position.y,SIDE_LENGTH,SIDE_LENGTH};
}
