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

	surface = IMG_Load("resources/images/miscellaneous/favIcon.png");


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

	surface = IMG_Load("resources/images/miscellaneous/gota.png");
	bala = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/pistolaAgua.png");
	armaSprite = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/pistolaAguaIzq.png");
	armaSpriteIzq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/rifleAgua.png");
	armaRifleSprite = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/rifleAguaIzq.png");
	armaRifleSpriteIzq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/spawner1.png");
	spawnPistola = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/spawner2.png");
	spawnPistolaBurst = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/menu.png");
	tex = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/fondoDesenfokat.png");
	menuGauss = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/fondoEnfokat.png");
	menuEnfoq = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/menuControles.png");
	texMenuControls = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/exit.png");
	texBotonExit = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/controls.png");
	texBotoncontrols = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/start.png");
	texBotonstart = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/teclado.png");
	texBotonteclado = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/MandoDePlay.png");
	texBotonplay = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/CuatroJugadores.png");
	texBotonCuatroJugadores = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/TresJugadores.png");
	texBotonTresJugadores = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/DosJugadores.png");
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

void initMusika() {
	/********************************************************
	*														*
	*	Inicializa la musica y los sonidos.					*
	*														*
	*														*
	*********************************************************/
	int flags = MIX_INIT_MP3;
	Mix_Init(flags);

	creditosMusic = Mix_LoadMUS("resources/music/cancionCreditos.mp3");
	menuMusic = Mix_LoadMUS("resources/music/cancionMenu.mp3");
	inGameMusic = Mix_LoadMUS("resources/music/cancionInGame.mp3");
	victoriaMusic = Mix_LoadMUS("resources/music/cancionVictoria.mp3");
	miauSound = Mix_LoadWAV("resources/music/miau.wav");
	blinkSound = Mix_LoadWAV("resources/music/blink.wav");
	fizzSound = Mix_LoadWAV("resources/music/fizz.wav");
	jumpSound = Mix_LoadWAV("resources/music/jump.wav");
	pistolaSound = Mix_LoadWAV("resources/music/pistola.wav");
	rifleSound = Mix_LoadWAV("resources/music/rifle.wav");
	transDingSound[0] = Mix_LoadWAV("resources/music/ding.wav");
	transDingSound[1] = Mix_LoadWAV("resources/music/ding2.wav");
}

void initKeia() {
	/**
	* INIciamos los sprites del humo de apagarse
	*
	*/
	surface = IMG_Load("resources/images/miscellaneous/keia1.png");
	keia[0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/keia2.png");
	keia[1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/keia3.png");
	keia[2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/keia4.png");
	keia[3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	for (int i = 0; i < 4; i++) {
		keiaHB[i].w = 60;
		keiaHB[i].h = 160;
	}

}

void initBlink() {
	/**
	* PIniciamos los sprites del blink animazioa
	*
	*/

	surface = IMG_Load("resources/images/miscellaneous/flashAtze1.png");
	blink[0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/flashAtze2.png");
	blink[1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/flashAtze3.png");
	blink[2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	for (int i = 0; i < 8; i++) {
		blinkHB[i].w = 100;
		blinkHB[i].h = 100;
	}
}

void initSpawners(int kajakop)
{
	/**
	* Iniciamos los spawners del mapa acrtual
	*
	*/

	for (int i = 0; i < kajakop; i++) {
		hitboxSpawn[i].h = 30;
		hitboxSpawn[i].w = 31;
		hitboxSpawn[i].x = arrayNivelak[nivela].arrayKajak[i].x;
		hitboxSpawn[i].y = arrayNivelak[nivela].arrayKajak[i].y;
		arrayNivelak[nivela].arrayKajak[i].armaDisponible = 1;
		arrayNivelak[nivela].arrayKajak[i].CD = 0;
	}

}

void initNumeros()
{
	/**
	* Init todos los numeros de las puntuaciónes.
	*
	*/
	surface = IMG_Load("resources/images/miscellaneous/0.png");
	numeros[0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/1.png");
	numeros[1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/2.png");
	numeros[2] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/3.png");
	numeros[3] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/4.png");
	numeros[4] = SDL_CreateTextureFromSurface(rend, surface);

	posNum[0].w = 100;
	posNum[0].h = 100;

	posNum[1].w = 100;
	posNum[1].h = 100;

	posNum[2].w = 100;
	posNum[2].h = 100;

	posNum[3].w = 100;
	posNum[3].h = 100;

	posNum[4].w = 100;
	posNum[4].h = 100;

}

void initPuntuPantaila()
{
	/**
	* init el BG de la pantalla de puntos
	*
	*/
	surface = IMG_Load("resources/images/backgrounds/2players.png");
	puntuPantaila[0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/3players.png");
	puntuPantaila[1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/4players.png");
	puntuPantaila[2] = SDL_CreateTextureFromSurface(rend, surface);
}

void initMeteoro() {

	/**
	* INIT las texturas de los meteoritos
	*
	*/
	// Init Sprites meteoros

	surface = IMG_Load("resources/images/miscellaneous/Meteor1.png");
	meteoro[0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/Meteor2.png");
	meteoro[1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/Meteor3.png");
	meteoro[2] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/miscellaneous/Meteor4.png");
	meteoro[3] = SDL_CreateTextureFromSurface(rend, surface);

	meteoroHB[0].w = 60;
	meteoroHB[0].h = 60;

	meteoroHB[1].w = 120;
	meteoroHB[1].h = 120;

	meteoroHB[2].w = 60;
	meteoroHB[2].h = 60;

	meteoroHB[3].w = 200;
	meteoroHB[3].h = 200;

}

void initZutabe() {

	/**
	* INIT el BG del segundo mapa
	*
	*
	*/

	// Init Animación BG segundo mapa
	surface = IMG_Load("resources/images/miscellaneous/zutabetxo.png");
	zutabe = SDL_CreateTextureFromSurface(rend, surface);
	for (int i = 0; i < 3; i++) {
		SDL_QueryTexture(zutabe, NULL, NULL, &zutabeHB[i].w, &zutabeHB[i].h);
		zutabeHB[i].w = (int)(zutabeHB[i].w / 2.5);
		zutabeHB[i].h = (int)(zutabeHB[i].h / 2);
	}
	for (int i = 0; i < 3; i++) zutabeHB[i].y = 150;
	zutabeHB[0].x = 100;

	zutabeHB[1].x = 825;

	zutabeHB[2].x = 1195;
}

void initBackgroundTextures() {

	/**
	* La funcion comprueba si hay una talka bertikal
	*
	*/

	//Init BG texures

	surface = IMG_Load("resources/images/backgrounds/nivela1.png");
	background[0][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela1-2.png");
	background[0][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela2.png");
	background[1][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela2-2.png");
	background[1][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela3.png");
	background[2][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela3-2.png");
	background[2][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela4.png");
	background[3][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela4-2.png");
	background[3][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela5.png");
	background[4][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela5-2.png");
	background[4][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela6.png");
	background[5][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela6-2.png");
	background[5][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela7.png");
	background[6][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela7-2.png");
	background[6][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela8.png");
	background[7][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela8-2.png");
	background[7][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela9.png");
	background[8][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela9-2.png");
	background[8][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela10.png");
	background[9][0] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/nivela10-2.png");
	background[9][1] = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/backgrounds/victoryScreen.png");
	background[10][0] = SDL_CreateTextureFromSurface(rend, surface);
}

void initSpriteTexturak() {

	/**
	* INIT las texturas de los players
	*
	*/

	// Init Sprite texturess

	surface = IMG_Load("resources/images/sprites/spriteSua1.png");
	spr[0][0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSua2.png");
	spr[0][1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSua3.png");
	spr[0][2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSua4.png");
	spr[0][3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/sprites/spriteSuaBlue1.png");
	spr[1][0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaBlue2.png");
	spr[1][1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaBlue3.png");
	spr[1][2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaBlue4.png");
	spr[1][3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/sprites/spriteSuaGreen1.png");
	spr[2][0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaGreen2.png");
	spr[2][1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaGreen3.png");
	spr[2][2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaGreen4.png");
	spr[2][3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/sprites/spriteSuaPurple1.png");
	spr[3][0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaPurple2.png");
	spr[3][1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaPurple3.png");
	spr[3][2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("resources/images/sprites/spriteSuaPurple4.png");
	spr[3][3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

}

void initTransNumbers() {
	/**
	* Iniciamos los numeros de la transicion de mapa a mapa
	*
	*/
	surface = IMG_Load("resources/images/miscellaneous/trans1.png");
	transNumbers[2] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/trans2.png");
	transNumbers[1] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/trans3.png");
	transNumbers[0] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("resources/images/miscellaneous/trans4.png");
	transNumbers[3] = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	transNumbersHB[0].w = 150;
	transNumbersHB[0].h = 300;
	transNumbersHB[0].x = WINDOW_WIDTH / 2 - 75;
	transNumbersHB[0].y = WINDOW_HEIGHT / 2 - 150;

	transNumbersHB[1].w = 300;
	transNumbersHB[1].h = 300;
	transNumbersHB[1].x = WINDOW_WIDTH / 2 - 150;
	transNumbersHB[1].y = WINDOW_HEIGHT / 2 - 150;

}