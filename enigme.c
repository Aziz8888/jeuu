/**
* @file enigme.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <math.h>
#include <time.h> 

void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	
 *alea =  rand()%3 +1;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p));
  SDL_Flip(screen) ;
}

 void solution_e1 (char image [],int *x)
 {      
 	
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
       *x=2;
     
  }
 	if(strcmp(image,"2.jpg")==0)
 	{
       *x=1;
     
  }	

	if(strcmp(image,"3.jpg")==0)
 	{
       *x=2;
     
  }
 	

 }


int resolution1 (int * running,int *run )
{
	SDL_Event event ;
 int r=-1;
               SDL_WaitEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
                * running= 0 ;
                *run = 0;
								 }
							    if( event.type == SDL_KEYDOWN )
                 {

            if( ( event.key.keysym.unicode >= ((Uint16)48) ) && ( event.key.keysym.unicode <= ((Uint16)57)	 ) )
            { 
							r=event.key.keysym.unicode-48  ;
							
						} 
								 }	
return r;

                 
	} 



 void 	afficher_resultat (SDL_Surface * screen,int r,enigme *en,int x)
 {
  FILE *f ;  
f=fopen("enigme_file","a") ;	 
 	if (r==x)
 	{
 		en->img=IMG_Load("10.png");
 fprintf(f,"/*correct answer*/  \n la response est %d \n",r) ;				 
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
fprintf(f,"wrong essai : \n votre reponse est %d\n",r) ; 
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
	 fclose(f) ;
 }
