#include "colors.h"
using namespace std;

const Color gray = {150, 150, 150, 255};
const Color red = {255, 0, 0, 254};
const Color blue = {0, 0, 255, 255};
const Color green = {0, 255, 0, 255};
const Color yellow = {250, 250, 0, 255};
const Color purple = {255, 0, 255, 255};
const Color white = {255, 255, 255, 255};
const Color darkBlue = {44, 44, 127, 255};
const Color lightBlue = {200, 200, 255, 255};

vector<Color> GetCellColors() {
    return {gray, red, blue, green, yellow, purple, white, BLACK, BLUE, RED, YELLOW, PURPLE, GREEN};
}