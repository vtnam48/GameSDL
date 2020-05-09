#include "SDL_UNTIL.h"
using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Mix_Chunk* chunk = nullptr;
SDL_Rect point, firstSnake;

const int _SIZE = 10;
bool quit = false;

void setFirst(SDL_Rect &firstSnake){
    firstSnake.x = 10;
    firstSnake.y = 10;
    firstSnake.w = _SIZE;
    firstSnake.h = _SIZE;
}

void randomPoint(SDL_Rect &point){
    point.x = (rand()% SCREEN_WIDTH/_SIZE)* _SIZE;
    point.y = (rand()% SCREEN_HEIGHT/_SIZE)* _SIZE;
    point.h = _SIZE;
    point.w = _SIZE;
}


void link(vector <SDL_Rect> &snake, int temp){

    for(int i = snake.size()-1; i > 0; i--){
        snake[i] = snake[i-1];
    }
    if(temp == 0) snake[0].x = (snake[0].x + SCREEN_WIDTH - _SIZE) % SCREEN_WIDTH;
    if(temp == 1) snake[0].x = (snake[0].x + _SIZE) % SCREEN_WIDTH;
    if(temp == 2) snake[0].y = (snake[0].y + _SIZE) % SCREEN_HEIGHT;
    if(temp == 3) snake[0].y = (snake[0].y + SCREEN_HEIGHT - _SIZE) % SCREEN_HEIGHT;

    for(int i = snake.size()-1; i > 0; i--){
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y) quit = true;
    }
}

int main(int argc, char* argv[]){
    //init game
    initSDL(window, renderer);
    int action;
    SDL_Event e;
    chunk = Mix_LoadWAV("ting.wav");
    srand(time(nullptr));

    //init snake
    vector <SDL_Rect> snake;
    randomPoint(point);
    setFirst(firstSnake);
    SDL_RenderFillRect(renderer, &firstSnake);
    snake.push_back(firstSnake);

    updateScreen(renderer, snake, point);

    while (!quit) {

        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: action = 0; link(snake, action);
                                break;
            	case SDLK_RIGHT: action = 1; link(snake, action);
                                break;
            	case SDLK_DOWN: action = 2; link(snake, action);
                                break;
            	case SDLK_UP: action = 3; link(snake, action);
                                break;
        		default: break;
			}

         if(snake[0].x == point.x && snake[0].y == point.y){
            while(snake[0].x == point.x && snake[0].y == point.y) randomPoint(point);

                Mix_PlayChannel(-1, chunk, 0);

                snake.push_back(point);
                link(snake, action);
            }

        updateScreen(renderer, snake, point);
        }
    }
    quitSDL(window, renderer);
    return 0;
}

