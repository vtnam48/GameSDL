#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <ctime>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "True Or False";
int point = 0;
SDL_Color White = {255, 255, 255};
const int ptsize = 20;
const int MAX_A = 10, MAX_B = 15, flex = 2;

enum playerAns{
    none = 0,
    trueAns = 1,
    falseAns = 2
};

enum typeEqua{
    cong = 0,
    tru = 1,
    nhan = 2,
};

#endif // COMMON_H
