#include "SDL_utils.h"
#include "Equation.h"
#include "Common.h"


SDL_Window* window;
SDL_Renderer* renderer;
Mix_Chunk* chunk = nullptr;

bool playAgain = true;


void getImage(string const path)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedImgSurface = IMG_Load(path.c_str());
    if (loadedImgSurface == nullptr) cout << "Error loading Surface\n";
    else{
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedImgSurface);

        SDL_FreeSurface(loadedImgSurface);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, newTexture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
}

void initWindow()
{
    SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT
                                , SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


//struct Equation{
//
//    int x, y, z;
//    typeEqua tp;
//
//    void randomEquation(){
//        x = rand()%MAX_A;
//        y = rand()%MAX_B;
//
//        int n = rand()%3;
//
//        if(n == 0) tp = cong;
//        if(n == 1) tp = tru;
//        if(n == 2) tp = nhan;
//
//        if(tp == cong)z = (x+y) + rand()%flex;
//        if(tp == tru) z = (x-y) + rand()%flex;
//        if(tp == nhan) z = (x*y) + rand()%flex;
//
//    }
//
//    string getString(){
//        string strReturn;
//        stringstream s;
//        s << x;
//        strReturn = s.str();
//
//        stringstream s2;
//        s2 << y;
//        if(tp == cong) strReturn = strReturn + " + " + s2.str();
//        if(tp == tru) strReturn = strReturn + " - " + s2.str();
//        if(tp == nhan) strReturn = strReturn + " x " + s2.str();
//
//        stringstream s3;
//        s3 << z;
//        strReturn = strReturn + " = " + s3.str();
//
//        return strReturn;
//    }
//
//    int key(){
//        if(tp == cong){
//            if(x+y == z) return 1;
//            return 2;
//        }
//
//        if(tp == tru){
//            if(x-y == z) return 1;
//            return 2;
//        }
//        if(tp == nhan){
//            if(x*y == z) return 1;
//            return 2;
//        }
//    }
//} e;
Equation e;
void drawText(string str, int point){
        string strReturn;
        stringstream s;
        s << point;
        strReturn = s.str();


        SDL_RenderClear(renderer);
        getImage("bg.png");
        TTF_Font* fo = TTF_OpenFont("UVNBaiSau_R.ttf", ptsize);
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fo, str.c_str(), White);

        SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect Message_rect;
        Message_rect.x = 150;
        Message_rect.y = 230;
        Message_rect.w = 500;
        Message_rect.h = 200;

        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);

        /////////
        SDL_Surface* surfacePoint = TTF_RenderText_Solid(fo, strReturn.c_str(), White);

        SDL_Texture* sPoint = SDL_CreateTextureFromSurface(renderer, surfacePoint);
        SDL_Rect Point_rect;
        Point_rect.x = 400;
        Point_rect.y = 20;
        Point_rect.w = 100;
        Point_rect.h = 100;

        SDL_RenderCopy(renderer, sPoint, NULL, &Point_rect);

        SDL_FreeSurface(surfacePoint);
        SDL_DestroyTexture(sPoint);


        SDL_RenderPresent(renderer);
}

bool xuly(Equation equa){

    SDL_Event e;
    playerAns ans = none;

    Uint32 startTime = SDL_GetTicks();
    unsigned int timeLimit = 5000;
    drawText(equa.getString(), point);

    while(SDL_GetTicks() - startTime <= timeLimit){

        if (SDL_PollEvent(&e) != 0 && e.type == SDL_KEYDOWN){
            if (e.key.keysym.sym == SDLK_LEFT){
                ans = falseAns;//2
                break;
            }
            if (e.key.keysym.sym == SDLK_RIGHT){
                ans = trueAns;//1
                break;
            }
        }
    }
        if (ans == equa.key()) return true;
        return false;
}

bool endGame(){
    SDL_Event eFromKey;
    while(true){
        if (SDL_WaitEvent(&eFromKey) == 0) continue;

        if (eFromKey.type == SDL_KEYDOWN){
            if (eFromKey.key.keysym.sym == SDLK_LEFT){
                return false;
            }
            if (eFromKey.key.keysym.sym == SDLK_RIGHT){
                return true;
            }
        }
    }
}

void printScore(int point){
    string strReturn;
    stringstream s;
    s << point;
    strReturn = s.str();

    TTF_Font* fo = TTF_OpenFont("UVNBaiSau_R.ttf", ptsize-5);
    SDL_RenderClear(renderer);
    getImage("endgame.png");

    SDL_Surface* surfacePoint = TTF_RenderText_Solid(fo, strReturn.c_str(), White);

    SDL_Texture* sPoint = SDL_CreateTextureFromSurface(renderer, surfacePoint);
    SDL_Rect Point_rect;
    Point_rect.x = 450;
    Point_rect.y = 50;
    Point_rect.w = 100;
    Point_rect.h = 100;

    SDL_RenderCopy(renderer, sPoint, NULL, &Point_rect);

    SDL_FreeSurface(surfacePoint);
    SDL_DestroyTexture(sPoint);


    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    initWindow();
    chunk = Mix_LoadWAV("ting.wav");
    //in menu

    getImage("zz.png");
    waitUntilKeyPressed();

    // choi lai
    while(playAgain){
        point = 0;

        SDL_RenderClear(renderer);

        bool quit = false;
        srand(time(nullptr));

        while(!quit){
                e.randomEquation();
                if(xuly(e)){
                    point += 10;
                    Mix_PlayChannel(-1, chunk, 0);
                }
                else{
                    quit = true;
                }
            }

        //end game
        printScore(point);

        if(endGame()){
            playAgain = true;
        }
        else{
            playAgain = false;
        }
}

    Mix_CloseAudio();
    quitSDL(window, renderer);
    return 0;
}
