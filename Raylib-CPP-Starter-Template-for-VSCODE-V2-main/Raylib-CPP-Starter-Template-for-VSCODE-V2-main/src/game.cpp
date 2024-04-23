#include "game.h"
#include <random>
using namespace std;

Game::Game() {
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock() {
    if(blocks.empty()) {
            blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock(), CornerBlock(), PBlock(), BBlock(), StairBlock(), BigTBlock(), UBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw(11, 11);
    
    switch(nextBlock.id) {
        case 3:
            nextBlock.Draw(255, 290);               // Some blocks need custom spacing to be centered in the next block
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        case 9:
            nextBlock.Draw(280, 250);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0) {
        gameOver = false;
        Reset();
    }
    switch(keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_A:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_D:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        case KEY_S:
            MoveBlockDown();
            UpdateScore(0,1);
            break;
        case KEY_UP:
            MoveBlockUp();
            UpdateScore(0,-5);
            break;
        case KEY_W:
            MoveBlockUp();
            UpdateScore(0,-5);
            break;
        case KEY_ENTER:
            RotateBlock();
            break;
        case KEY_SPACE:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft() {
    if(!gameOver) {
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false) {
        currentBlock.Move(0, 1);
    }
    }
}

void Game::MoveBlockRight() {
    if(!gameOver) {
    currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false) {
        currentBlock.Move(0, -1);
    }
    }
}

void Game::MoveBlockDown() {
    if(!gameOver) {
    currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false) {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
    }
}

void Game::MoveBlockUp() {
    if(!gameOver) {
    currentBlock.Move(-1, 0);
    if(IsBlockOutside() || BlockFits() == false) {
        currentBlock.Move(1, 0);
    }
    }
}

bool Game::IsBlockOutside()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles) {
        if(grid.IsCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if(!gameOver) {
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false) {
        currentBlock.UndoRotation();        // if the rotation would put it in an invalid position then undo it
    } 
    }
}

void Game::LockBlock()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;          //sets the value of those spaces to the value of the block color when it sets
    }
    currentBlock = nextBlock;                   // When a block gets locked into place the next one starts and a new next one is chosen
    if(BlockFits() == false) {
        gameOver = true;                        // When the block spawns on a placed block it is game over
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles) {
        if(grid.IsCellEmpty(item.row, item.column) == false) {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    score = 0;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared) {                          // Awards points based on the number of lines cleared at once
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score +=500;
            break;
        case 4:
            score +=1000;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}
