/**
* @file main.c
* @brief Testing Program.
* @author aziz salem	
* @version alea sans fichier 
* @date Apr 27, 2021
*
* Testing program
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <time.h>

int main()
{ 

	SDL_Surface *screen;
	enigme  e;
	int r=10,run =1,running=1,alea,cond=0;
	int x;
	char image[30]="";
	SDL_Event event;
    srand(time(NULL));
 FILE *f ;  
f=fopen("valeur","a") ;	 
	 SDL_Init ( SDL_INIT_VIDEO ) ;


   SDL_EnableUNICODE( SDL_ENABLE );
	 screen=SDL_SetVideoMode(500,625,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
	srand(time(NULL));
	 while (run)
	 {
	    running=1 ;
	     SDL_PollEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
              
                run = 0;
								 }
								 
			  
            
generate_afficher ( screen  , image ,&e,&alea) ;
solution_e1 (image,&x) ;

if(cond!=1)
{
cond=1 ;	
do {
r=resolution1 (&running,&run ) ;
}while(r<0 || r>4) ;
} 


 fprintf(f,"1= %d \n r=%d\n alea: %d",x,r,alea) ;	 
			
			afficher_resultat (screen,r,&e,x) ;			
      while(running){

	
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					               case SDL_QUIT :
                              running =0 ;
						                  run=0 ;
					                break ;
                         case SDL_KEYDOWN :
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
																generate_afficher ( screen  , image ,&e,&alea) ; 
			cond=0 ;
			
			                        break ;
			                      }
						              break ;
                       }
                    }
   } 
	 fclose(f) ;
      SDL_FreeSurface(e.img);
      SDL_FreeSurface(screen);
      
      SDL_Quit();
	return 0;
}
