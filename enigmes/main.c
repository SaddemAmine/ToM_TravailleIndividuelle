#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

typedef struct{
	SDL_Surface* img;
	SDLKey rep;
}puzzle;

int enigme(SDL_Surface** scr,puzzle p){
    SDL_Event event;
    (*scr) = SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    while(1){
        SDL_BlitSurface(p.img,NULL,(*scr),NULL);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return;
                break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == p.rep){
                        printf("Yes\n");
                        return 1;
                    }
                    else{
                        printf("No\n");
                        return 0;
                    }
                break;
            }
        }
        SDL_Flip((*scr));
    }
}

void main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* scr; puzzle p; 
    p.img = IMG_Load("test.png"); p.rep = SDLK_UP;
    enigme(&scr,p);
}
