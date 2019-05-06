#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_timer.h>

void main(){
    Uint32 tempsPrecedent = 0, tempsActuel = 0;
    while(1){
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 1000){
            printf("%d - %d = %d\n",tempsActuel,tempsPrecedent,tempsActuel-tempsPrecedent);
            tempsPrecedent = tempsActuel;
        }
    }
}