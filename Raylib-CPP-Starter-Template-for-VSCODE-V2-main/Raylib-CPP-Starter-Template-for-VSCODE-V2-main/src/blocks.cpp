#include "block.h"
#include "position.h"
// Holds all the different block shapes
class LBlock :public Block{
public:
    LBlock(){
        id = 1;
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};

class JBlock :public Block{
public:
    JBlock(){
        id = 2;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        Move(0, 3);
    }
};

class IBlock :public Block{
public:
    IBlock(){
        id = 3;
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        Move(-1, 3);
    }
};

class OBlock :public Block{
public:
    OBlock(){
        id = 4;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        Move(0, 4);
    }
};

class SBlock :public Block{
public:
    SBlock(){
        id = 5;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};

class TBlock :public Block{
public:
    TBlock(){
        id = 6;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};

class ZBlock :public Block{
public:
    ZBlock(){
        id = 7;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        Move(0, 3);
    }
};

class CornerBlock :public Block{
    public:
    CornerBlock(){
        id = 8;
        cells[0] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 0), Position(2, 0)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(2, 1), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1), Position(2, 2)};
        Move(0, 3);
    }
};

class PBlock :public Block{
    public:
    PBlock(){
        id = 9;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(2, 0), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 1), Position(1, 2)};
        cells[2] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 0), Position(1, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        Move(0, 3);
    }
};

class BBlock :public Block{
    public:
    BBlock(){
        id = 10;
        cells[0] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(1, 1), Position(2, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        cells[3] = {Position(1, 0), Position(0, 1), Position(0, 2), Position(1, 1), Position(1, 2)};
        Move(0, 3);
    }
};

class StairBlock :public Block{
    public:
    StairBlock(){
        id = 10;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(1, 1), Position(2, 1), Position(2, 0)};
        cells[2] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(2, 0), Position(1, 0), Position(1, 1), Position(0, 1), Position(0, 2)};
        Move(0, 3);
    }
};

class BigTBlock :public Block{
    public:
    BigTBlock(){
        id = 11;
        cells[0] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[1] = {Position(1, 2), Position(1, 1), Position(0, 2), Position(1, 0), Position(2, 2)};
        cells[2] = {Position(2, 0), Position(0, 1), Position(2, 2), Position(1, 1), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(1, 1), Position(1, 2)};
        Move(0, 3);
    }
};

class UBlock :public Block{
    public:
    UBlock(){
        id = 12;
        cells[0] = {Position(0, 0), Position(1, 0), Position(0, 2), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(0, 2), Position(2, 2), Position(2, 1)};
        cells[2] = {Position(2, 0), Position(1, 0), Position(2, 2), Position(1, 1), Position(1, 2)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(2, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};