#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

void parallax_scrolling(SDL_Surface** scr,int x,SDL_Surface* b1,SDL_Surface* b2,SDL_Surface* b3,SDL_Rect* p1,SDL_Rect* p2,SDL_Rect* p3){
    
    printf("%d \n",x);
    p1->x = x+4; p2->x = x+2; p3->x = x;
    SDL_BlitSurface(b3,p3,(*scr),NULL);
    SDL_BlitSurface(b2,p2,(*scr),NULL);
    SDL_BlitSurface(b1,p1,(*scr),NULL);
    SDL_Flip((*scr));
}

void main(){
    SDL_Rect p1,p2,p3;     
    p1.y = 0; p2.y = 0; p3.y = 0;
    p1.w = 1280; p2.w = 1280; p3.w = 1280;
    p1.h = 720; p2.h = 720; p3.h = 720;
    SDL_Surface* b1 = IMG_Load("level1.png");
    SDL_Surface* b2 = IMG_Load("LEVEL1BG1.png");
    SDL_Surface* b3 = IMG_Load("LEVEL1BG2.png");
    SDL_Surface* scr = SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF); SDL_Event event; int sf = 0;
    //SDL_EnableKeyRepeat(10,10); 
    while(1){
	while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return;
                break;
            }
        }
	sf += 4;
	scrollinglvl2(&scr,sf,b1,b2,b3,&p1,&p2,&p3);
    }
}
