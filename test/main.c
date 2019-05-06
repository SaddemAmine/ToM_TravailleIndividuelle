#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface* imgI[2];
	SDL_Surface* imgD[2];
	SDL_Surface* imgG[2];
	SDL_Surface* imgS[3];
}animation;

typedef struct{
	animation anim;
}personnage;

void init_animation(personnage* p){
	p->anim.imgI[0] = IMG_Load("imgs/p1.png");
	p->anim.imgI[1] = IMG_Load("imgs/p2.png");
	p->anim.imgD[0] = IMG_Load("imgs/p3_D.png");
	p->anim.imgD[1] = IMG_Load("imgs/p4_D.png");
	p->anim.imgG[0] = IMG_Load("imgs/p3_G.png");
	p->anim.imgG[1] = IMG_Load("imgs/p4_G.png");
	p->anim.imgS[0] = IMG_Load("imgs/p5.png");
	p->anim.imgS[1] = IMG_Load("imgs/p6.png");
	p->anim.imgS[2] = IMG_Load("imgs/p7.png");
}

void main(){
	SDL_Surface* scr = NULL; personnage p; SDL_Rect pos; SDL_Event event;
	pos.x = 0; pos.y = 0;
	scr = SDL_SetVideoMode(139,228,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	init_animation(&p);
	int i=0,j=0,k=0,l=0,x=250;
	SDL_EnableKeyRepeat(10,10);
	while(1){
		x = 250;
		SDL_Delay(x);
		SDL_BlitSurface(p.anim.imgI[i%2],NULL,scr,&pos);
		i++;
		printf("%d\n",i);
		while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_SPACE)
                        return;
					if(event.key.keysym.sym == SDLK_RIGHT){
						printf("R");
						SDL_BlitSurface(p.anim.imgD[k%2],NULL,scr,&pos);
						k++; x = 50;
					}
					else{
						if(event.key.keysym.sym == SDLK_LEFT){
							printf("L");
							SDL_BlitSurface(p.anim.imgG[l%2],NULL,scr,&pos);
							l++; x = 50
						}
						else{
							if(event.key.keysym.sym == SDLK_UP){
								printf("U");
								SDL_BlitSurface(p.anim.imgS[j%3],NULL,scr,&pos);
								j++; x = 50;
							}
						}
					}
					
					
				break;
            }
        }
		SDL_Flip(scr);
	}
}
