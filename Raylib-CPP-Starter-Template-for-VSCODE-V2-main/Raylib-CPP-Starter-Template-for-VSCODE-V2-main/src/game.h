#pragma once
#include "grid.h"
#include "blocks.cpp"
using namespace std;

class Game {
    public:
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        void MoveBlockUp();
        bool gameOver;
        int score;

    private:
        void MoveBlockLeft();
        void MoveBlockRight();
        Block GetRandomBlock();
        vector<Block> GetAllBlocks();
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();                       // If the block tries to move down too far it locks in place
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        Grid grid;
        vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};