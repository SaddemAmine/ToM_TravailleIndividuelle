#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
    SDL_Surface* img;
    int spd; // The speed of the rock
    int dmg; // The amount of dmg the rock does when hitting the player
}rock;

void init_ennemie(rock* r){
    r->img = IMG_Load("img.png");
    r->spd = 1;
    r->dmg = 25;
}

void main(){
    SDL_Surface* scr; SDL_Event event; SDL_Rect pos;

    
    scr = SDL_SetVideoMode(300,300,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    pos.x = 0; pos.y = 0;

    rock r;
    init_ennemie(&r);

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        printf("Error: %s\n",SDL_GetError());
        return;
    }

    while(1){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_SPACE)
                        return;
                break;
            }
        }
        printf("%x\n",r.img);
        SDL_BlitSurface(r.img,NULL,scr,&pos);
        SDL_Flip(scr);
    }
    
} 