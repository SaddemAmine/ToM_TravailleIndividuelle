#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void main(){
    int x = 0;
    SDL_Surface* img = NULL; SDL_Surface* scr = NULL; SDL_Event event;
    scr = SDL_SetVideoMode(300,140,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    img = IMG_Load("img2.jpg");

    SDL_Rect pos;
    pos.x = 0; pos.y = 0;

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        printf("Error: %s\n",SDL_GetError());
        return;
    }

    while(1){
        SDL_Delay(10);
        SDL_BlitSurface(img,NULL,scr,&pos);
        SDL_Flip(scr);
        if(x>-350)
            x--;
        else
            x = 0; 
        pos.x = x;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_SPACE)
                        return;
                break;
            }
        }
        printf("%d --\n",pos.x);
    }
    
}
