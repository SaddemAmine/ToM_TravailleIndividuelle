#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void minimap(int* x,int y,SDL_Surface** scr){
    SDL_Surface* mm = IMG_Load("mm.png"); SDL_Surface* hl = IMG_Load("hl.png");
    SDL_Rect pos1,pos2; pos1.x = (*x); pos1.y = 200; pos2.x = 25; pos2.y = 200; 
    if(y % 100 == 0){
        pos1.x += 35;
    }
    (*x) = pos1.x;
    SDL_BlitSurface(mm,NULL,(*scr),&pos2);
    SDL_BlitSurface(hl,NULL,(*scr),&pos1);
}

void main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface* scr = SDL_SetVideoMode(400,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_Surface* bg = IMG_Load("bg.png"); SDL_Event event; SDL_Rect pos; pos.x = 0; pos.y = 0; pos.w = 400; pos.w = 400;
    SDL_EnableKeyRepeat(10,10); int z=-1; int x = 25;
    while(1){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return;
                break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        z--;
                    }
            }
        }
        pos.x = z;
        SDL_BlitSurface(bg,NULL,scr,&pos);
        printf("%d %d\n",x,z);
        minimap(&x,z,&scr);
        SDL_Flip(scr);
    }
}