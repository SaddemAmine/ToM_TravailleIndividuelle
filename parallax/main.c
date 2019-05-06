#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void parallax(){
    SDL_Event event;

    SDL_Rect p1,p2,p3;
    p1.x = 0; p2.x = 0; p3.x = 0;
    p1.y = 0; p2.y = 0; p3.y = 0;
    p1.h = 100; p2.h = 100; p3.h = 100;
    p1.w = 200; p2.w = 200; p3.w = 200;

    SDL_Surface* img1 = IMG_Load("1.png");
    SDL_Surface* img2 = IMG_Load("2.png");
    SDL_Surface* img3 = IMG_Load("3.png");

    SDL_Surface* scr = SDL_SetVideoMode(200,100,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_EnableKeyRepeat(10,10);

    while(1){
        SDL_Delay(30);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return;
                break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        p1.x ++;
                        p2.x += 2;
                    /*    if(p3.x == 400)
                        p3.x = 0;
                        else*/
                        p3.x += 4;
                    }
                    if(event.key.keysym.sym == SDLK_LEFT){
                        p1.x --;
                        p2.x -= 2;
                        p3.x -= 4;
                    }
            }
        }

        SDL_BlitSurface(img1,&p1,scr,NULL);
        SDL_BlitSurface(img2,&p2,scr,NULL);
        SDL_BlitSurface(img3,&p3,scr,NULL);
        SDL_Flip(scr);
    }
}

void main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    parallax();
}
