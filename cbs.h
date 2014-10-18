//----------------------------------------------------------------------
#ifndef _CBS_HEADER_
#define _CBS_HEADER_

//----------------------------------------------------------------------
void cb00(void) {
	pi = 0;
	pj = 0;
	px = 8*2;
	py = 16*8;

	pl_move_direc = 0;
	pl_move_delay = 0;
	pl_move_frame = 0;
	pl_moving = SDL_FALSE;

	pl_fire_direc = 0;
	pl_fire_delay = 0;
	pl_fire_frame = 0;
	pl_firing = SDL_FALSE;

	int i;
	if(enemy_num+1<=enemy_cap)
		enemy_num += 8;
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

	lvl[8][19] = 0x02;
	cbs[8][19] = NULL;

	clearInput();
	curlvl++;
}

#endif
