#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

void gestion_temps(int x,SDL_Surface* T[],SDL_Surface** scr){
    int t[3];
    SDL_Surface* bg = IMG_Load("scr.png");
    
    (*scr) = SDL_SetVideoMode(300,100,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    SDL_Rect p1,p2,p3; p1.y = 0; p2.y = 0; p3.y = 0; p1.x = 0; p2.x = 100; p3.x = 200; 
    t[0] = x/100; t[1] = (x/10)%10; t[2] = (x%100)%10;
    
    SDL_BlitSurface(bg,NULL,(*scr),NULL);
    SDL_BlitSurface(T[t[0]],NULL,(*scr),&p1);
    SDL_BlitSurface(T[t[1]],NULL,(*scr),&p2);
    SDL_BlitSurface(T[t[2]],NULL,(*scr),&p3);
       
}


void main(){
    SDL_Surface* scr; int x = 999; SDL_Event event; 
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface* T[10];
    T[0] = IMG_Load("0.png");
    T[1] = IMG_Load("1.png");
    T[2] = IMG_Load("2.png");
    T[3] = IMG_Load("3.png");
    T[4] = IMG_Load("4.png");
    T[5] = IMG_Load("5.png");
    T[6] = IMG_Load("6.png");
    T[7] = IMG_Load("7.png");
    T[8] = IMG_Load("8.png");
    T[9] = IMG_Load("9.png");

    while(1){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return;
                break;
            }
        }
        gestion_temps(x,T,&scr);
        x--;
        SDL_Delay(1000);
        SDL_Flip(scr);
    }
}