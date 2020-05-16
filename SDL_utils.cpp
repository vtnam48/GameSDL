#include "SDL_utils.h"
//#include "Common.h"
using namespace std;



void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(10);
    }
}
//void getImage(string const path)
//{
//    SDL_Texture* newTexture = nullptr;
//    SDL_Surface* loadedImgSurface = IMG_Load(path.c_str());
//    if (loadedImgSurface == nullptr) cout << "Error loading Surface\n";
//    else{
//        newTexture = SDL_CreateTextureFromSurface(renderer, loadedImgSurface);
//
//        SDL_FreeSurface(loadedImgSurface);
//        SDL_RenderClear(renderer);
//        SDL_RenderCopy(renderer, newTexture, nullptr, nullptr);
//        SDL_RenderPresent(renderer);
//    }
//}
