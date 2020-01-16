#include "struct.h"
#include "deklarazioak.h"


int init() {

	//////////////////////////////////  SDL INIT   ////////////////////////////////////////

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) != 0) {
		printf("No se pudo iniciar");
		return 1;
	}

	Uint32 render_flags;
	ventana = SDL_CreateWindow("Fighter Fires Z", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!ventana) {
		printf("Error de ventana: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	//render_flags = SDL_RENDERER_ACCELERATED;
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	rend = SDL_CreateRenderer(ventana, -1, render_flags);

	if (!rend) {
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(ventana);
		SDL_Quit();
		return 1;
	}

	surface = IMG_Load("resources/favIcon.png");


	if (!surface)
	{
		printf("Error intentando crear la surface %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(ventana);
		SDL_Quit();
		return 1;
	}

	if (Mix_OpenAudio(44410, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("Error de audio: %s\n", Mix_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(ventana);
		SDL_Quit();
		return 1;
	}

	TTF_Init();
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}

	font = TTF_OpenFont("resources/fonts/Walkway_Bold.ttf", 300);


	SDL_SetWindowIcon(ventana, surface);
	SDL_FreeSurface(surface);
	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);

	initNivelak();

	//////////////////////////////////  INIT VARIABLES  ////////////////////////////////////////

	if (seleccionDeMandos == 0) jokalariKopurua = 2;

	seleccionprincipal = vuelta = randSeed = close_requested = disparoact = randSeed = transEgoera = victoria = inizializauta = 0;
	seleccionDeMandos = -1;
	teklatua.Adown = teklatua.Sdown = teklatua.Wdown = teklatua.Ddown = teklatua.UPdown = teklatua.DOWNdown = teklatua.LEFTdown = teklatua.RIGHTdown = teklatua.COMAdown = teklatua.PUNTOdown = teklatua.SHIFTdown = teklatua.SPACEdown = teklatua.Rdown = 0;
	RMinit = transSound = initCreditos = 1;
	transCoolDown = 20;

	alphaBeltz = alphaGauss = 255;

	//////////////////////////////////  INIT TEXTURAK   ////////////////////////////////////////

	initKeia();
	initTransNumbers();
	initSpriteTexturak();
	initBackgroundTextures();
	initMeteoro();
	initZutabe();
	initNumeros();
	initPuntuPantaila();
	initBlink();

	surface = IMG_Load("resources/gota.png");
	bala = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/pistolaAgua.png");
	armaSprite = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/pistolaAguaIzq.png");
	armaSpriteIzq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/rifleAgua.png");
	armaRifleSprite = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/rifleAguaIzq.png");
	armaRifleSpriteIzq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/spawner1.png");
	spawnPistola = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/spawner2.png");
	spawnPistolaBurst = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/2jugadoresPuntos.png");
	puntuazioa = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/menu.png");
	tex = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/fondoDesenfokat.png");
	menuGauss = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/fondoEnfokat.png");
	menuEnfoq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/menuControles.png");
	texMenuControls = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/exit.png");
	texBotonExit = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/controls.png");
	texBotoncontrols = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/start.png");
	texBotonstart = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/teclado.png");
	texBotonteclado = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/MandoDePlay.png");
	texBotonplay = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/CuatroJugadores.png");
	texBotonCuatroJugadores = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/TresJugadores.png");
	texBotonTresJugadores = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/DosJugadores.png");
	texBotonDosJugadores = SDL_CreateTextureFromSurface(rend, surface);

	//////////////////////////////////  INIT UR-JAURTIKETAS  ////////////////////////////////////////

	for (int i = 0; i < 20; i++) {
		disparo[i].direc = 1;
		disparo[i].speed = 30;
		disparo[i].disparado = 0;
		disparo[i].x = 1380;
		disparo[i].y = -50;
		SDL_QueryTexture(bala, NULL, NULL, &hitboxBala[i].w, &hitboxBala[i].h);
		hitboxBala[i].h /= 20;
		hitboxBala[i].w /= 20;
	}

	//////////////////////////////////  INIT JOKALARIAK   ////////////////////////////////////////

	for (int i = 0; i < 4; i++)
	{
		SDL_QueryTexture(armaSprite, NULL, NULL, &hitboxArma[i].w, &hitboxArma[i].h);
		hitbox[i].h = 60;
		hitbox[i].w = 40;
		jokalaria[i].x = (WINDOW_WIDTH - hitbox[i].w) / 2;
		jokalaria[i].y = (WINDOW_HEIGHT - hitbox[i].h) / 2;
		jokalaria[i].egoera = 1;
		jokalaria[i].anim = 0;
		jokalaria[i].blink = 0;
		jokalaria[i].arma = 0;
		jokalaria[i].kontagarri = 1;
		jokalaria[i].puntuak = 0;
		saltoaEgin[i] = 0;
		x_vel[i] = 0;
		y_vel[i] = SPEED;
		blinkPhase[i] = 0;
		hilCoolDown[i] = 0;
		mandos[i].AxisX = 0;
		easterCoolDown[i] = 0;
	}

	/////////////////////////////// INIT MUSICA //////////////////////////////////////
	initMusika();
	return 0;
}