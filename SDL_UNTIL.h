#ifndef SDL_UNTIL_H
#define SDL_UNTIL_H

#include <iostream>
#include <SDL.h>
#include <ctime>
#include <vector>
#include <SDL_mixer.h>

using namespace std;


const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "SNAKE";

//init
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
//
void updateScreen(SDL_Renderer* renderer, vector <SDL_Rect> &snake, SDL_Rect &point);
void setFirst(SDL_Rect &firstSnake);

#endif // SDL_UNTIL_H

