#include "deklarazioak.h"
#include "struct.h"

int menu() {
	close_requested = 0;
	Mix_PlayMusic(menuMusic, -1);
	while (vuelta == 0 && seleccionprincipal != 3)
	{
		seleccionprincipal = MenuPrincipal();

		if (seleccionprincipal == 1)
		{
			seleccionDeMandos = MenuController(rend);
			if (seleccionDeMandos == 0) jokalariKopurua = 2;
			else jokalariKopurua = seleccionDeMandos;
			setPlayerPos();

			if (seleccionDeMandos != 1)
			{
				vuelta = 1;
			}
		}

		if (seleccionprincipal == 2)
		{
			seleccionprincipal = MenuDeComoJugar(rend);
		}
		
	}

	if (seleccionprincipal == 3 || seleccionDeMandos == 5)
	{
		SDL_DestroyWindow(ventana);
		SDL_Quit();
		return 0;
	}
	srand(randSeed);
	nivela = randomMap();
	for (int i = 0; i < seleccionDeMandos; ++i) {
		if (SDL_IsGameController(i)) {
			pad[i] = SDL_GameControllerOpen(i);
			if (!pad) {
				fprintf(stderr, "Could not open gamecontroller %i: %s\n", i, SDL_GetError());
			}
			//else printf("Konetat %d ", i);
			actualMandos++;
		}
	}
	initSpawners(arrayNivelak[nivela].kajaKop);
	setPlayerPos();

	
	Mix_HaltMusic();
	//Mix_PlayChannel(-1, transDingSound, 0);
	return 1;
}