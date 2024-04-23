#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

extern const Color gray;                //creating colors {red, green, blue, alpha(opacity)}
extern const Color red;
extern const Color blue;
extern const Color green;
extern const Color yellow;
extern const Color purple;
extern const Color white;
extern const Color darkBlue;
extern const Color lightBlue;

vector<Color> GetCellColors();