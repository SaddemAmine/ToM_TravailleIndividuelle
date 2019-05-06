#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y){
  SDL_Color color;
  Uint32 col = 0 ;

  //determine position
  char* pPosition = ( char* ) pSurface->pixels ;

  //offset by y
  pPosition += ( pSurface->pitch * y ) ;

  //offset by x
  pPosition += ( pSurface->format->BytesPerPixel * x ) ;

  //copy pixel data
  memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

  //convert color
  SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
  return ( color ) ;
}

void main(){
    SDL_Surface *scr,*img,*p; SDL_Event event; Uint32 tempsPrecedent = 0, tempsActuel = 0, tempsPrecedentA = 0, tempsActuelA = 0; 
int frames = 0,jframes = 0;
    SDL_Rect pos; pos.x = 10; pos.y = 305; SDL_Color c; int x,y;

    scr = SDL_SetVideoMode(400,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    img = IMG_Load("level.png");
    p = IMG_Load("p.png");
    SDL_EnableKeyRepeat(10,10);

    SDL_BlitSurface(img,NULL,scr,NULL);
    SDL_BlitSurface(p,NULL,scr,&pos);
    SDL_Flip(scr);

    while(1){
        
        
        while(SDL_PollEvent(&event)){
            switch(event.type){
		case SDL_QUIT:
			return;
		break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_RETURN)
                        return;
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        tempsActuel = SDL_GetTicks();
                        if ((tempsActuel - tempsPrecedent > 50)&&(frames < 50)){
                            frames ++;
                            tempsPrecedent = tempsActuel;
                        }
                        if(frames < 5){
                            pos.x++;
                            SDL_BlitSurface(img,NULL,scr,NULL);
                            SDL_BlitSurface(p,NULL,scr,&pos);
                        }
                        else{
                            pos.x += 2;
                            SDL_BlitSurface(img,NULL,scr,NULL);
                            SDL_BlitSurface(p,NULL,scr,&pos);
                        }
                    }

                    if(event.key.keysym.sym == SDLK_LEFT){
                        tempsActuel = SDL_GetTicks();
                        if ((tempsActuel - tempsPrecedent > 50)&&(frames < 50)){
                            frames ++;
                            tempsPrecedent = tempsActuel;
                        }
                        if(frames < 5){
                            pos.x--;
                            SDL_BlitSurface(img,NULL,scr,NULL);
                            SDL_BlitSurface(p,NULL,scr,&pos);
                        }
                        else{
                            pos.x -= 2;
                            SDL_BlitSurface(img,NULL,scr,NULL);
                            SDL_BlitSurface(p,NULL,scr,&pos);
                        }
                    }
                    
                    if(event.key.keysym.sym == SDLK_UP){
                        jframes = 50;
                    }


                break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_RIGHT)
                        frames = 0;
                    if(event.key.keysym.sym == SDLK_LEFT)
                        frames = 0;
                break;
            }
        }
	//SDL_GetMouseState(&x,&y);
	//c = GetPixel(img,x,y);
	//printf("%d %d %d\n",c.r,c.g,c.b);
	tempsActuelA = SDL_GetTicks();
        if(tempsActuelA - tempsPrecedentA > 20){
            tempsPrecedentA = tempsActuelA;
	c = GetPixel(img,pos.x+10,pos.y+21);	
	if(c.r && c.g && c.b && !jframes){
        pos.y++; 
        SDL_BlitSurface(img,NULL,scr,NULL);
        SDL_BlitSurface(p,NULL,scr,&pos);
    }
	}
	printf("%d %d __\n",pos.x,pos.y);	
	
        tempsActuel = SDL_GetTicks();
        if((jframes > 0) && (tempsActuel - tempsPrecedent > 20)){
            tempsPrecedent = tempsActuel;
            if(jframes > 27){
                pos.y -= 2;
                SDL_BlitSurface(img,NULL,scr,NULL);
                SDL_BlitSurface(p,NULL,scr,&pos);
                jframes --;
            }
            else{
                c = GetPixel(img,pos.x+10,pos.y+21);
                if(!c.r && !c.g && !c.b){
                    jframes = 0; 
                    SDL_BlitSurface(img,NULL,scr,NULL);
                    SDL_BlitSurface(p,NULL,scr,&pos);
                }
                else{
                    pos.y += 2;
                    SDL_BlitSurface(img,NULL,scr,NULL);
                    SDL_BlitSurface(p,NULL,scr,&pos);
                    jframes --;
                }
            }
        }
        SDL_Flip(scr);
    }
}
