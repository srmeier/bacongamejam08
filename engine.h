//----------------------------------------------------------------------
#ifndef _ENGINE_HEADER_
#define _ENGINE_HEADER_

//----------------------------------------------------------------------
typedef struct {
	SDL_bool up;
	SDL_bool down;
	SDL_bool left;
	SDL_bool right;
	SDL_bool abnt, bbnt;
	SDL_bool w, a, s, d;
	SDL_bool left_mouse;
	SDL_bool right_mouse;
	int mouse_x, mouse_y;
} Input;

//----------------------------------------------------------------------
extern int           sprnum;
extern FILE*         fp_log;
extern Input         pl_input;
extern SDL_bool      running;
extern SDL_Window*   window;
extern SDL_Surface*  screen;
extern SDL_Renderer* renderer;
extern SDL_Surface** spritesheet;

//----------------------------------------------------------------------
void init(void) {
	fp_log = freopen("log.txt", "w", stdout);

	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(
		SCREEN_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_SCALE*SCREEN_W,
		SCREEN_SCALE*SCREEN_H,
		0
	);

	renderer = SDL_CreateRenderer(
		window, -1,
		SDL_RENDERER_ACCELERATED|
		SDL_RENDERER_PRESENTVSYNC
	);

	screen = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H, 24, 0x00, 0x00, 0x00, 0x00);
	SDL_SetColorKey(screen, 1, 0xFF00FF);
	SDL_FillRect(screen, 0, 0xFF00FF);

	SDL_Surface* surface = SDL_LoadBMP("spritesheet.bmp");

	sprnum = ((surface->w/8)*(surface->h/8)+1);
	spritesheet = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*sprnum);

	int i, x, y;
	SDL_Rect rect = {0, 0, 8, 8};
	for(i=0; i<sprnum; i++) {
		spritesheet[i] = SDL_CreateRGBSurface(0, 8, 8, 24, 0x00, 0x00, 0x00, 0x00);
		SDL_SetColorKey(spritesheet[i], 1, 0xFF00FF);
		SDL_FillRect(spritesheet[i], 0, 0xFF00FF);
		if(i!=0) {
			x = (i-1)%(surface->w/8);
			y = (i-x)/(surface->w/8);
			rect.x = x*8, rect.y = y*8;
			SDL_BlitSurface(surface, &rect, spritesheet[i], NULL);
		}
	}

	SDL_FreeSurface(surface);

	running = SDL_TRUE;
}

//----------------------------------------------------------------------
void quit(void) {
	int i;
	for(i=0; i<sprnum; i++)
		SDL_FreeSurface(spritesheet[i]);
	free(spritesheet);
	spritesheet = NULL;

	SDL_FreeSurface(screen);
	screen = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
	TTF_Quit();

	fclose(fp_log);
}

//----------------------------------------------------------------------
void pollInput(void) {
	pl_input.left_mouse = SDL_FALSE;
	pl_input.right_mouse = SDL_FALSE;

	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT: {
				running = SDL_FALSE;
			} break;
			case SDL_KEYDOWN: {
				switch(event.key.keysym.sym) {
					case SDLK_UP: pl_input.up = SDL_TRUE; break;
					case SDLK_DOWN: pl_input.down = SDL_TRUE; break;
					case SDLK_LEFT: pl_input.left = SDL_TRUE; break;
					case SDLK_RIGHT: pl_input.right = SDL_TRUE; break;
					case SDLK_LCTRL: pl_input.abnt = SDL_TRUE; break;
					case SDLK_LALT: pl_input.bbnt = SDL_TRUE; break;
					case SDLK_w: pl_input.w = SDL_TRUE; break;
					case SDLK_a: pl_input.a = SDL_TRUE; break;
					case SDLK_s: pl_input.s = SDL_TRUE; break;
					case SDLK_d: pl_input.d = SDL_TRUE; break;
				}
			} break;
			case SDL_KEYUP: {
				switch(event.key.keysym.sym) {
					case SDLK_UP: pl_input.up = SDL_FALSE; break;
					case SDLK_DOWN: pl_input.down = SDL_FALSE; break;
					case SDLK_LEFT: pl_input.left = SDL_FALSE; break;
					case SDLK_RIGHT: pl_input.right = SDL_FALSE; break;
					case SDLK_LCTRL: pl_input.abnt = SDL_FALSE; break;
					case SDLK_LALT: pl_input.bbnt = SDL_FALSE; break;
					case SDLK_w: pl_input.w = SDL_FALSE; break;
					case SDLK_a: pl_input.a = SDL_FALSE; break;
					case SDLK_s: pl_input.s = SDL_FALSE; break;
					case SDLK_d: pl_input.d = SDL_FALSE; break;
				}
			} break;
			case SDL_MOUSEBUTTONDOWN: {
				switch(event.button.button) {
					case SDL_BUTTON_LEFT: pl_input.left_mouse = SDL_TRUE; break;
					case SDL_BUTTON_RIGHT: pl_input.right_mouse = SDL_TRUE; break;
				}
			} break;
			case SDL_MOUSEMOTION: {
				pl_input.mouse_x = event.motion.x;
				pl_input.mouse_y = event.motion.y;
			} break;
		}
	}
}

//----------------------------------------------------------------------
SDL_Surface* getSprite(unsigned int w, unsigned int h, int** inds) {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, 8*w, 8*h, 24, 0x00, 0x00, 0x00, 0x00);
	SDL_SetColorKey(surface, 1, 0xFF00FF);
	SDL_FillRect(surface, 0, 0xFF00FF);

	int i, j;
	SDL_Rect rect = {0, 0, 8, 8};
	for(j=0; j<h; j++) {
		for(i=0; i<w; i++) {
			rect.x = i*8, rect.y = j*8;
			SDL_BlitSurface(spritesheet[inds[j][i]], NULL, surface, &rect);
		}
	}

	return surface;
}

//----------------------------------------------------------------------
void drawText(const char* str, int x, int y, int scale) {
	TTF_Font* font = TTF_OpenFont("font.ttf", scale*10);

	SDL_Color color = {0xFF, 0xFF, 0xFF, 0x00};
	SDL_Surface* text = TTF_RenderText_Solid(font, str, color);

	SDL_Rect rect = {x, y, text->w, text->h};
	SDL_BlitSurface(text, NULL, screen, &rect);

	SDL_FreeSurface(text);
	TTF_CloseFont(font);
}

//----------------------------------------------------------------------
void clearInput(void) {
	pl_input.w = SDL_FALSE;
	pl_input.s = SDL_FALSE;
	pl_input.a = SDL_FALSE;
	pl_input.d = SDL_FALSE;
	pl_input.up = SDL_FALSE;
	pl_input.abnt = SDL_FALSE;
	pl_input.bbnt = SDL_FALSE;
	pl_input.down = SDL_FALSE;
	pl_input.left = SDL_FALSE;
	pl_input.right = SDL_FALSE;
	pl_input.left_mouse = SDL_FALSE;
	pl_input.right_mouse = SDL_FALSE;
}

#endif
