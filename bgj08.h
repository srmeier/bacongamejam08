//----------------------------------------------------------------------
#ifndef _BGJ08_HEADER_
#define _BGJ08_HEADER_

//----------------------------------------------------------------------
int curlvl = 1;
int gamestate = 0;
int menu_delay = 560;
typedef void (*Callback)(void);

int lvl[15][20] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x02},
	{0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02}
};

Callback cbs[15][20] = {
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
};

//----------------------------------------------------------------------
int pi = 0;
int pj = 0;
int px = 8*2;
int py = 16*8;

double pl_health = 0;

int pl_move_direc = 0;
int pl_move_delay = 0;
int pl_move_frame = 0;
SDL_bool pl_moving = SDL_FALSE;

int pl_fire_direc = 0;
int pl_fire_delay = 0;
int pl_fire_frame = 0;
SDL_bool pl_firing = SDL_FALSE;

//----------------------------------------------------------------------
typedef struct {
	int x, y, i, j;
	int move_direc;
	int move_delay;
	int move_frame;
	SDL_bool alive;
	SDL_bool moving;
} Enemy;

int enemy_num = 8;
int enemy_cap = 255;
Enemy enemies[0xFF];
int enemies_alive = 0;

//----------------------------------------------------------------------
SDL_Surface* logoTile00 = NULL;
SDL_Surface* doorTile00 = NULL;
SDL_Surface* rockTile00 = NULL;
SDL_Surface* enemyTile00 = NULL;
SDL_Surface* enemyTile01 = NULL;
SDL_Surface* grassTile00 = NULL;
SDL_Surface* playerTile00 = NULL;
SDL_Surface* lightningVertTile00 = NULL;
SDL_Surface* lightningVertTile01 = NULL;
SDL_Surface* lightningVertTile02 = NULL;
SDL_Surface* lightningVertTile03 = NULL;

//----------------------------------------------------------------------
void startGame(void) {
	int i;

	pi = 0;
	pj = 0;
	px = 8*2;
	py = 16*8;

	pl_health = 0;

	pl_move_direc = 0;
	pl_move_delay = 0;
	pl_move_frame = 0;
	pl_moving = SDL_FALSE;

	pl_fire_direc = 0;
	pl_fire_delay = 0;
	pl_fire_frame = 0;
	pl_firing = SDL_FALSE;

	enemy_num = 8;
	enemies_alive = 0;

	for(i=0; i<enemy_num; i++) {
		Enemy* e = &enemies[i];

		e->x = 8*(rand()%(40-4))+16;
		e->y = 8*(rand()%(30-8))+48;
		e->i = floor(e->x/8.0f);
		e->j = floor(e->y/8.0f);

		e->move_direc = 0;
		e->move_delay = 0;
		e->move_frame = 0;
		e->alive = SDL_TRUE;
		e->moving = SDL_FALSE;
	}
}

//----------------------------------------------------------------------
void buildTiles(void) {
	playerTile00 = getSprite(2, 2, (int*[]) {
		(int[]) {  1,   2},
		(int[]) { 33,  34}
	});

	lightningVertTile00 = getSprite(1, 2, (int*[]) {
		(int[]) {  3},
		(int[]) { 35}
	});

	lightningVertTile01 = getSprite(1, 2, (int*[]) {
		(int[]) {  4},
		(int[]) { 36}
	});

	lightningVertTile02 = getSprite(2, 1, (int*[]) {
		(int[]) {  5,   6}
	});

	lightningVertTile03 = getSprite(2, 1, (int*[]) {
		(int[]) { 37,  38}
	});

	rockTile00 = getSprite(2, 2, (int*[]) {
		(int[]) {  7,   8},
		(int[]) { 39,  40}
	});

	grassTile00 = getSprite(2, 2, (int*[]) {
		(int[]) {  9,  10},
		(int[]) { 41,  42}
	});

	enemyTile00 = getSprite(1, 1, (int*[]) {
		(int[]) { 11}
	});

	enemyTile01 = getSprite(1, 1, (int*[]) {
		(int[]) { 12}
	});

	doorTile00 = getSprite(2, 2, (int*[]) {
		(int[]) { 13,  14},
		(int[]) { 45,  46}
	});

	logoTile00 = getSprite(4, 4, (int*[]) {
		(int[]) { 15,  16,  17,  18},
		(int[]) { 47,  48,  49,  50},
		(int[]) { 19,  20,  21,  22},
		(int[]) { 51,  52,  53,  54}
	});
}

//----------------------------------------------------------------------
void destroyTiles(void) {
	SDL_FreeSurface(logoTile00);
	SDL_FreeSurface(doorTile00);
	SDL_FreeSurface(rockTile00);
	SDL_FreeSurface(enemyTile00);
	SDL_FreeSurface(enemyTile01);
	SDL_FreeSurface(grassTile00);
	SDL_FreeSurface(playerTile00);
	SDL_FreeSurface(lightningVertTile00);
	SDL_FreeSurface(lightningVertTile01);
	SDL_FreeSurface(lightningVertTile02);
	SDL_FreeSurface(lightningVertTile03);
}

//----------------------------------------------------------------------
SDL_Surface* getTile(int id) {
	switch(id) {
		case 0x01: return grassTile00; break;
		case 0x02: return rockTile00; break;
		case 0x03: return doorTile00; break;
	}
}

//----------------------------------------------------------------------
SDL_bool canMove(int i, int j) {
	return lvl[j][i]!=0x02;
}

//----------------------------------------------------------------------
void handlePlayer(void) {
	pi = floor(px/16.0f);
	pj = floor(py/16.0f);

	if(pl_health>0) pl_health -= 0.1f;

	if(pl_move_delay>0) pl_move_delay--;
	if(pl_move_frame>0) pl_move_frame--;
	else if(pl_moving) {
		pl_moving = SDL_FALSE;
		pl_move_delay = 0;
		if(cbs[pj][pi]) (cbs[pj][pi])();
	}

	if(pl_fire_delay>0) pl_fire_delay--;
	if(pl_fire_frame>0) pl_fire_frame--;
	else if(pl_firing) {
		pl_firing = SDL_FALSE;
		pl_fire_delay = 16;
	}

	if(pl_move_delay==0&&!pl_moving&&!pl_firing) {
		if(pl_input.w&&canMove(pi,pj-1)) {
			pl_moving = SDL_TRUE;
			pl_move_frame = 16-1;
			pl_move_direc = 0;
		} else if(pl_input.s&&canMove(pi,pj+1)) {
			pl_moving = SDL_TRUE;
			pl_move_frame = 16-1;
			pl_move_direc = 1;
		} else if(pl_input.a&&canMove(pi-1,pj)) {
			pl_moving = SDL_TRUE;
			pl_move_frame = 16-1;
			pl_move_direc = 2;
		} else if(pl_input.d&&canMove(pi+1,pj)) {
			pl_moving = SDL_TRUE;
			pl_move_frame = 16-1;
			pl_move_direc = 3;
		}
	}

	if(pl_moving) {
		switch(pl_move_direc) {
			case 0: py--; break;
			case 1: py++; break;
			case 2: px--; break;
			case 3: px++; break;
		}
	}

	if(pl_fire_delay==0&&!pl_moving&&!pl_firing) {
		if(pl_input.up&&canMove(pi,pj-1)) {
			pl_firing = SDL_TRUE;
			pl_fire_frame = 16-1;
			pl_fire_direc = 0;
		} else if(pl_input.down&&canMove(pi,pj+1)) {
			pl_firing = SDL_TRUE;
			pl_fire_frame = 16-1;
			pl_fire_direc = 1;
		} else if(pl_input.left&&canMove(pi-1,pj)) {
			pl_firing = SDL_TRUE;
			pl_fire_frame = 16-1;
			pl_fire_direc = 2;
		} else if(pl_input.right&&canMove(pi+1,pj)) {
			pl_firing = SDL_TRUE;
			pl_fire_frame = 16-1;
			pl_fire_direc = 3;
		}
	}
}

//----------------------------------------------------------------------
void drawPlayer(void) {
	int i;
	if(pl_firing) {
		switch(pl_fire_direc) {
			case 0: {
				for(i=0; i<500; i++) {
					int x = rand()%(8+1)+px;
					int y = (py-16)-rand()%SCREEN_H;
					SDL_Rect frect = {x, y, 8*1, 8*2};
					if(rand()%2==0) {
						SDL_BlitSurface(lightningVertTile00, NULL, screen, &frect);
					} else {
						SDL_BlitSurface(lightningVertTile01, NULL, screen, &frect);
					}
				}
			} break;
			case 1: {
				for(i=0; i<500; i++) {
					int x = rand()%(8+1)+px;
					int y = (py+16)+rand()%SCREEN_H;
					SDL_Rect frect = {x, y, 8*1, 8*2};
					if(rand()%2==0) {
						SDL_BlitSurface(lightningVertTile00, NULL, screen, &frect);
					} else {
						SDL_BlitSurface(lightningVertTile01, NULL, screen, &frect);
					}
				}
			} break;
			case 2: {
				for(i=0; i<500; i++) {
					int x = (px-16)-rand()%SCREEN_W;
					int y = rand()%(8+1)+py;
					SDL_Rect frect = {x, y, 8*1, 8*2};
					if(rand()%2==0) {
						SDL_BlitSurface(lightningVertTile02, NULL, screen, &frect);
					} else {
						SDL_BlitSurface(lightningVertTile03, NULL, screen, &frect);
					}
				}
			} break;
			case 3: {
				for(i=0; i<500; i++) {
					int x = (px+16)+rand()%SCREEN_W;
					int y = rand()%(8+1)+py;
					SDL_Rect frect = {x, y, 8*1, 8*2};
					if(rand()%2==0) {
						SDL_BlitSurface(lightningVertTile02, NULL, screen, &frect);
					} else {
						SDL_BlitSurface(lightningVertTile03, NULL, screen, &frect);
					}
				}
			} break;
		}
	}

	SDL_Rect pl_rect = {px, py, 8*2, 8*2};
	SDL_BlitSurface(playerTile00, NULL, screen, &pl_rect);
}

//----------------------------------------------------------------------
void handleEnemies(void) {
	int i, j;
	enemies_alive = 0;
	int enemies_toadd = 0;
	for(i=0; i<enemy_num; i++) {
		Enemy* e = &enemies[i];
		if(!e->alive) continue;

		e->i = floor(e->x/8.0f);
		e->j = floor(e->y/8.0f);

		for(j=0; j<enemy_num; j++) {
			if(j==i) continue;

			Enemy* e2 = &enemies[j];
			if(e2->alive) continue;

			if(e->i==e2->i&&e->j==e2->j) {
				e2->alive = SDL_TRUE;
				if((enemy_num+enemies_toadd)==0xFF-1||rand()%8!=0)
					continue;
				enemies_toadd++;
			}
		}

		if(e->move_delay>0) e->move_delay--;
		if(e->move_frame>0) e->move_frame--;
		else if(e->moving) {
			e->moving = SDL_FALSE;
			e->move_delay = 0;
		}

		if(e->move_delay==0&&!e->moving) {
			int i  = floor(e->x/16.0f);
			int j  = floor(e->y/16.0f);
			int il = floor((e->x+8.0f)/16.0f);
			int ju = floor((e->y+8.0f)/16.0f);
			int ir = floor((e->x-8.0f)/16.0f);
			int jd = floor((e->y-8.0f)/16.0f);

			int check1 = pi==i&&pj==j;
			int check2 = pi==il&&pj==j;
			int check3 = pi==i&&pj==jd;
			int check4 = pi==il&&pj==jd;

			if(check1||check2||check3||check4) {
				pl_health += 5.0f;
			}

			int direc = rand()%12;
			if(direc==0&&canMove(i,ju-1)) {
				e->moving = SDL_TRUE;
				e->move_frame = 16-1;
				e->move_direc = 0;
			} else if(direc==1&&canMove(i,jd+1)) {
				e->moving = SDL_TRUE;
				e->move_frame = 16-1;
				e->move_direc = 1;
			} else if(direc==2&&canMove(il-1,j)) {
				e->moving = SDL_TRUE;
				e->move_frame = 16-1;
				e->move_direc = 2;
			} else if(direc==3&&canMove(ir+1,j)) {
				e->moving = SDL_TRUE;
				e->move_frame = 16-1;
				e->move_direc = 3;
			} else {
				switch(e->move_direc) {
					case 0: {
						if(canMove(i,ju-1)) {
							e->moving = SDL_TRUE;
							e->move_frame = 16-1;
						}
					} break;
					case 1: {
						if(canMove(i,jd+1)) {
							e->moving = SDL_TRUE;
							e->move_frame = 16-1;
						}
					} break;
					case 2: {
						if(canMove(il-1,j)) {
							e->moving = SDL_TRUE;
							e->move_frame = 16-1;
						}
					} break;
					case 3: {
						if(canMove(ir+1,j)) {
							e->moving = SDL_TRUE;
							e->move_frame = 16-1;
						}
					} break;
				}
			}
		}

		if(pl_firing) {
			switch(pl_fire_direc) {
				case 0: {
					if(e->j<=2*pj&&(e->i==2*pi||e->i==2*pi+1))
						e->alive = SDL_FALSE;
				} break;
				case 1: {
					if(e->j>=2*pj&&(e->i==2*pi||e->i==2*pi+1))
						e->alive = SDL_FALSE;
				} break;
				case 2: {
					if(e->i<=2*pi&&(e->j==2*pj||e->j==2*pj+1))
						e->alive = SDL_FALSE;
				} break;
				case 3: {
					if(e->i>=2*pi&&(e->j==2*pj||e->j==2*pj+1))
						e->alive = SDL_FALSE;
				} break;
			}
		}

		if(e->alive) enemies_alive++;
		if(e->moving&&e->move_frame%2) {
			switch(e->move_direc) {
				case 0: e->y--; break;
				case 1: e->y++; break;
				case 2: e->x--; break;
				case 3: e->x++; break;
			}
		}
	}

	if(enemies_toadd>0) {
		if(enemy_num+1>=enemy_cap) return;
		Enemy* e = &enemies[enemy_num++];

		e->x = 8*(rand()%(40-4))+16;
		e->y = 8*(rand()%(30-8))+48;
		e->i = floor(e->x/8.0f);
		e->j = floor(e->y/8.0f);

		e->move_direc = 0;
		e->move_delay = 0;
		e->move_frame = 0;
		e->alive = SDL_TRUE;
		e->moving = SDL_FALSE;
	}
}

#endif
