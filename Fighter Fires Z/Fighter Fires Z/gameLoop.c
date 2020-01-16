#include "deklarazioak.h"
#include "struct.h"

int gameLoop() {
	static int kont, timer;

	//Inicializacion del gameLoop
	if (!inizializauta) {
		kont = timer = 0;
		inizializauta = 1;
		Mix_PlayMusic(inGameMusic, -1);
	}

	//Comprobador de eventos 
	if (ebentuenDetekzioa() == 99) {
		return 99;
	}
	else close_requested = 0;

	//FOR PAR SABE EN QUE PARTE DEL ARRYAMAP
	close_requested = talkatxen();
	if (close_requested != 0) return close_requested;

	// Acciones mando
	comprobarAccionesMando();

	//Choque con el spawner
	chocarSpawner(arrayNivelak[nivela].kajaKop);

	//Resetear disparoactual
	if (disparoact >= 18) disparoact = 0;

	//Conseguir posición del joystick
	calcularEjeJoystick();

	//mirar la orientacion de los jugadores con teclado o mandos
	calcularOrientacio(&teklatua, jokalaria);

	//Disparo teclado P1
	if ((teklatua).SPACEdown == 1 && jokalaria[0].arma == 1) disparar(0);

	//Disparo teclado P2
	if ((teklatua).COMAdown == 1 && jokalaria[1].arma == 1) disparar(1);

	//Disparo mandos
	for (int i = 0; i < seleccionDeMandos; i++) {
		if (mandos[i].Xdown && disparo[disparoact].disparado == 0) {
			if (mandos[i].Xdown == 1 && jokalaria[i].arma == 1 && jokalaria[i].egoera == 1)	disparar(i);
		}
	}

	//Comporbar si hay colision bala/jugador
	colisionBalaJugador();

	//Comprobar si hay colision bala mapa
	colisionBalaMapa(arrayNivelak[nivela].karratuKop);

	//Disparoarekin akabatu muajajaj
	acabarConElDisparo();

	//Teklatuaren mugimendua aplikatu
	aplicarMugimenduTeklado();
	

	//Kontagarri atributoa berrezarri
	kont = resetKontagarri(kont);

	//Transicion entre niveles
	if (transicio(kont)) {
		resetDisparos();
		for (int i = 0; i < jokalariKopurua; i++) {
			if (jokalaria[i].puntuak == 4) {
				//El 10 es el de la victoria
				nivela = 10;
				setPlayerPos();
				resetPlayers();
				resetTeklauaEtaMandua();
				ranking();
				victoria = 1;
				Mix_PlayMusic(victoriaMusic, -1);
			}
		}

		if (victoria == 0)
		{
			nivela = randomMap();
			initSpawners(arrayNivelak[nivela].kajaKop);
			setPlayerPos();
			resetPlayers();
			resetTeklauaEtaMandua();
			transEgoera = 0;
		}

		kont = 0;
	}

	//CambiarPos P
	spriteMovimiento();

	//poner el arma en la pos del jugador
	ponerArma();

	//Cambiar la pos de la bala y su HB
	balaMovimiento();

	//Limpiar pantalla
	SDL_RenderClear(rend);

	//Dibujar BG
	rendBackground(nivela, timer);

	//Dibujar Spawners
	for (int i = 0; i < arrayNivelak[nivela].kajaKop; i++) {
		if (arrayNivelak[nivela].arrayKajak[i].armaDisponible == 1 && arrayNivelak[nivela].arrayKajak[i].typoArma == 1) {
			SDL_RenderCopy(rend, spawnPistola, NULL, &hitboxSpawn[i]);
		}
		else if (arrayNivelak[nivela].arrayKajak[i].armaDisponible == 1 && arrayNivelak[nivela].arrayKajak[i].typoArma == 2)
		{
			SDL_RenderCopy(rend, spawnPistolaBurst, NULL, &hitboxSpawn[i]);
		}
	}

	//Hil Animazioa
	hilAnimazioa();


	//Dibujar Players
	for (int i = 0; i < jokalariKopurua; i++) {
		jokalaria[i].anim = spriteAnimation(jokalaria[i], hitbox[i], i, timer);
		blinkAnimacio(jokalaria[i], i, timer);
	}

	//Dibujar balas
	for (int i = 0; i < 20; i++) SDL_RenderCopy(rend, bala, NULL, &hitboxBala[i]);

	//Dibujar las armas
	pintarArmas();

	//Transicio animazio
	transizioZenbakiak(timer);

	SDL_RenderPresent(rend);
	timer++;
	SDL_Delay(1000 / 60);
	return 0;
}