/* Bacon Game Jam 08 - Millions of them
gcc main.c -o bgj08.exe -I./include -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -mwindows
running on gcc 4.8.1, SDL 2.0.1

- player walks up/down/left/right
- when on a grid the player can shoot a lightning bolt which travels vertically or horizontally

*/

//----------------------------------------------------------------------
#define SCREEN_W 320 // 40 -> 20
#define SCREEN_H 240 // 30 -> 15
#define SCREEN_NAME "BGJ08: \"Millions of them\" - by Stephen Meier @undeadfavorite"
#define SCREEN_SCALE 2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "engine.h"
#include "bgj08.h"
#include "cbs.h"

//----------------------------------------------------------------------
int           sprnum;
FILE*         fp_log;
Input         pl_input;
SDL_bool      running     = SDL_FALSE;
SDL_Window*   window      = NULL;
SDL_Surface*  screen      = NULL;
SDL_Renderer* renderer    = NULL;
SDL_Surface** spritesheet = NULL;

//----------------------------------------------------------------------
int SDL_main(int argc, char* argv[]) {
	init();
	buildTiles();

	int i, j;
	SDL_Rect rect = {0, 0, 8*2, 8*2};

	while(running) {
		pollInput();

		SDL_RenderClear(renderer);
		SDL_FillRect(screen, 0, 0xFF00FF);

		/* === */

		if(gamestate==0) {
			if(menu_delay>0) menu_delay--;

			rect.x = SCREEN_W/2-8*1;
			rect.y = 16*2-8;
			rect.w = 16;
			rect.h = 16;

			SDL_BlitSurface(logoTile00, NULL, screen, &rect);

			char str[8];

			sprintf(str, "Loading %03d", (int) (100.0f*(560-menu_delay)/560.0f));
			drawText(str, SCREEN_W/2-8*5, 16*4, 2);

			drawText("http://stephenmeier.net/", SCREEN_W/2-16*3+4, 16*6, 1);
			drawText("Use W, A, S, D keys to move and arrow keys to fire.", SCREEN_W/2-16*6, 16*7, 1);

			if(menu_delay==0) {
				startGame();
				gamestate = 1;
				menu_delay = 560;
			}
		} else if(gamestate==1) {
			handlePlayer();
			handleEnemies();

			for(j=0; j<15; j++) {
				for(i=0; i<20; i++) {
					rect.x = 16*i;
					rect.y = 16*j;
					rect.w = 16;
					rect.h = 16;

					SDL_BlitSurface(getTile(lvl[j][i]), NULL, screen, &rect);
				}
			}

			for(i=0; i<enemy_num; i++) {
				rect.x = enemies[i].x;
				rect.y = enemies[i].y;
				rect.w = 8;
				rect.h = 8;

				if(enemies[i].alive)
					SDL_BlitSurface(enemyTile00, NULL, screen, &rect);
				else
					SDL_BlitSurface(enemyTile01, NULL, screen, &rect);
			}

			drawPlayer();

			if(enemies_alive==0) {
				lvl[8][19] = 0x03;
				cbs[8][19] = cb00;
			}

			char str[32];

			sprintf(str, "Level: %03d", curlvl);
			drawText(str, 8, 0, 1);

			sprintf(str, "Infected Hosts: %03d", enemies_alive);
			drawText(str, 8, 16, 1);

			sprintf(str, "Health: %03d", (int) (100.0f-pl_health));
			drawText(str, SCREEN_W-48, 0, 1);

			if((100.0f-pl_health)<=0) gamestate = 2;
		} else if(gamestate==2) {
			if(menu_delay>0) menu_delay--;

			rect.x = SCREEN_W/2-8*1;
			rect.y = 16*2-8;
			rect.w = 16;
			rect.h = 16;

			SDL_BlitSurface(logoTile00, NULL, screen, &rect);

			char str[128];

			sprintf(str, "Game Over %03d", (int) (100.0f*(560-menu_delay)/560.0f));
			drawText(str, SCREEN_W/2-8*6, 16*4, 2);

			sprintf(str, "You made it to Level %03d with %03d Infected Hosts!", curlvl, enemies_alive);
			drawText(str, SCREEN_W/2-16*6, 16*6, 1);

			if(menu_delay==0) {
				gamestate = 0;
				menu_delay = 560;
			}
		}

		/* === */

		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, screen);
		SDL_RenderCopy(renderer, tex, NULL, NULL);

		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tex);
	}

	destroyTiles();
	quit();
	return 0;
}
