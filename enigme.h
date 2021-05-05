 /**
* @file enigme.h
*/	
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
 SDL_Surface * img; /*!< Surface. */ 
 SDL_Rect 	p; /*!< rectangle. */ 
}enigme;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
int resolution1 (int * running,int *run );
void solution_e1 (char image [],int *x);
void afficher_resultat(SDL_Surface * screen,int r,enigme *en,int x);
