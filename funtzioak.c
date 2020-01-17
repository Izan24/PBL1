#define _CRT_SECURE_NO_WARNINGS
#include "deklarazioak.h"
#include "struct.h"

int talkabertical(cuadrado cuadrado, jok jokalaria)
{
	/**
	* La funcion comprueba si hay una talka bertikal
	* Parametros --> Cuadrado: el cuadrado del mapa. Jokalaria: EL jugador.
	*
	*/

	//Da un 1 si hay talka y un 0 si no
	int talka = 0;

	//Comprobar si el jugador esta dentro de las coordenadas del cuadrado
	if (jokalaria.y > cuadrado.y0 - PLAYERH && jokalaria.y < cuadrado.y + PLAYERH)
	{
		if (jokalaria.x >= (cuadrado.x0 - PLAYERW) && jokalaria.x <= (cuadrado.x0 + PLAYERW))
		{
			talka = 1;
		}
		else
		{
			if (jokalaria.x > (cuadrado.x - PLAYERW) && jokalaria.x < (cuadrado.x + PLAYERW))
			{
				talka = 1;
			}
			else talka = 0;
		}
	}
	else talka = 0;

	return talka;
}

int talkahorizontal(cuadrado cuadrado, jok jokalaria)
{
	/**
	* La funcion comprueba si hay una talka horizontal
	* Parametros --> Cuadrado: el cuadrado del mapa. Jokalaria: EL jugador.
	*
	*/

	//Da un 1 si hay talka y un 0 si no
	int talka = 0;

	if (jokalaria.x > cuadrado.x0 - PLAYERW && jokalaria.x < cuadrado.x + PLAYERW)
	{
		if (jokalaria.y >= (cuadrado.y0 - PLAYERH) && jokalaria.y <= (cuadrado.y0 + PLAYERH))
		{
			talka = 1;
		}
		else
		{
			if (jokalaria.y > (cuadrado.y - PLAYERH) && jokalaria.y < (cuadrado.y + PLAYERH))
			{
				talka = 1;
			}
			else talka = 0;
		}
	}
	else talka = 0;

	return talka;
}

int talkaBarruan(cuadrado cuadrado, jok jokalaria) {
	/**
	* La funcion comprueba si el jugador se ha metido dentro de un cuadrado
	* Parametros --> Cuadrado: el cuadrado del mapa. Jokalaria: EL jugador.
	*
	*/
	// Devuelve un 1 si está dentro y un 0 si no. 
	int talka = 0;
	if (jokalaria.x >= cuadrado.x0 && jokalaria.x <= cuadrado.x && jokalaria.y >= cuadrado.y0 && jokalaria.y <= cuadrado.y) {
		talka = 1;
	}
	else talka = 0;

	return talka;
}

int spriteAnimation(jok jokalari, SDL_Rect hitboxa, int jokalariZenb, int timer) {
	/**
	* Funcion en la que se animan los jugadores
	*
	*/

	//Devuelve jokalari.anim que sprite tiene que coger del array de sprites
	if (timer % 10 == 0) {
		if (jokalari.egoera == 1) {
			if (jokalari.anim < 3) {
				jokalari.anim++;
			}
			else {
				jokalari.anim = 0;
			}

		}
	}
	//Reproducir solo cuando 
	if (jokalari.egoera != 0) {
		SDL_RenderCopy(rend, spr[jokalariZenb][jokalari.anim], NULL, &hitboxa);
	}
	//Devolvemos en que parte de la anim está del 0 al 3
	return jokalari.anim;
}

void rendBackground(int nivelZenb, int timer) {
	/**
	* Rendereamos el bg dependiendo de nivelZenb que es el mapa actual
	*
	*/
	switch (nivelZenb)
	{
	case 0:
		SDL_RenderCopy(rend, background[0][0], NULL, NULL);
		meteoroAnimation(timer);
		SDL_RenderCopy(rend, background[0][1], NULL, NULL);
		break;
	case 1:
		SDL_RenderCopy(rend, background[1][0], NULL, NULL);
		zutabeAnimation();
		SDL_RenderCopy(rend, background[1][1], NULL, NULL);
		break;
	case 2:
		SDL_RenderCopy(rend, background[2][0], NULL, NULL);
		SDL_RenderCopy(rend, background[2][1], NULL, NULL);
		break;
	case 3:
		SDL_RenderCopy(rend, background[3][0], NULL, NULL);
		SDL_RenderCopy(rend, background[3][1], NULL, NULL);
		break;
	case 4:
		SDL_RenderCopy(rend, background[4][0], NULL, NULL);
		SDL_RenderCopy(rend, background[4][1], NULL, NULL);
		break;
	case 5:
		SDL_RenderCopy(rend, background[5][0], NULL, NULL);
		SDL_RenderCopy(rend, background[5][1], NULL, NULL);
		break;
	case 6:
		SDL_RenderCopy(rend, background[6][0], NULL, NULL);
		SDL_RenderCopy(rend, background[6][1], NULL, NULL);
		break;
	case 7:
		SDL_RenderCopy(rend, background[7][0], NULL, NULL);
		SDL_RenderCopy(rend, background[7][1], NULL, NULL);
		break;
	case 8:
		SDL_RenderCopy(rend, background[8][0], NULL, NULL);
		SDL_RenderCopy(rend, background[8][1], NULL, NULL);
		break;
	case 9:
		SDL_RenderCopy(rend, background[9][0], NULL, NULL);
		SDL_RenderCopy(rend, background[9][1], NULL, NULL);
		break;
	case 10:
		SDL_RenderCopy(rend, background[10][0], NULL, NULL);
		break;
	}
}

void meteoroAnimation(int timer) {
	/**
	* Reproducir la animación de los meteoritos
	*
	*/
	static int meteorAnim[4];

	for (int i = 0; i < 4; i++) {
		if (meteorAnim[i] < 5 && meteorAnim[i] >= 1) {
			if (timer % 10 == 0) {
				if (meteorAnim[i] < 5) {
					meteorAnim[i]++;
				}
				if (meteorAnim[i] >= 5) {
					meteorAnim[i] = 1;
				}
			}
		}
		else meteorAnim[i] = 1;
		if (meteoroHB[i].x < 0 || meteoroHB[i].y > WINDOW_HEIGHT) {
			switch (i)
			{
			case 0:
				meteoroHB[0].x = (WINDOW_WIDTH / 2) + 700;
				meteoroHB[0].y = -300;
				meteorAnim[0] = 1;
				break;
			case 1:
				meteoroHB[1].x = (WINDOW_WIDTH / 2) - 100;
				meteoroHB[1].y = -150;
				meteorAnim[0] = 1;
				break;
			case 2:
				meteoroHB[2].x = (WINDOW_WIDTH / 2) - 300;
				meteoroHB[2].y = -100;
				meteorAnim[0] = 1;
				break;
			case 3:
				meteoroHB[3].x = (WINDOW_WIDTH / 2) + 1000;
				meteoroHB[3].y = -700;
				meteorAnim[0] = 1;
			}
		}
		else {
			meteoroHB[i].x = (int)(meteoroHB[i].x - 1.5);
			meteoroHB[i].y = (int)(meteoroHB[i].y + 2.5);
		}
		SDL_RenderCopy(rend, meteoro[(meteorAnim[i] - 1)], NULL, &meteoroHB[i]);
	}
}

void zutabeAnimation() {
	/**
	* Reproducir la animación dle segundo mapa
	*
	*/
	for (int i = 0; i < 3; i++) {
		if (zutabeHB[i].y > -350) {
			zutabeHB[i].y -= 1;
		}
		else zutabeHB[i].y = 150;
		SDL_RenderCopy(rend, zutabe, NULL, &zutabeHB[i]);
	}
}

int MenuPrincipal()
{
	/**
	* Funcion del menú principal, se va a seguir reproduciendo hasta que haya una selección
	* Returnea el numero de la selección
	*/

	SDL_Event event;
	int CloseRequest = 0;
	float x_pos, y_pos; //estas son las del fondo y las de EXit
	float x_pos_controls, y_pos_controls;
	float x_pos_start, y_pos_start;

	while (CloseRequest == 0)
	{

		while (SDL_PollEvent(&event))
		{
			SDL_QueryTexture(texBotonExit, NULL, NULL, &BotonExit.w, &BotonExit.h);

			x_pos = (float)((WINDOW_WIDTH - BotonExit.w) / 2);
			y_pos = (float)((WINDOW_HEIGHT - BotonExit.h) / 2) + 250;

			BotonExit.y = (int)y_pos;
			BotonExit.x = (int)x_pos;

			SDL_QueryTexture(texBotoncontrols, NULL, NULL, &Botoncontrols.w, &Botoncontrols.h);

			x_pos_controls = (float)((WINDOW_WIDTH - Botoncontrols.w) / 2);
			y_pos_controls = (float)((WINDOW_HEIGHT - Botoncontrols.h) / 2) + 125;

			Botoncontrols.y = (int)y_pos_controls;
			Botoncontrols.x = (int)x_pos_controls;


			SDL_QueryTexture(texBotonstart, NULL, NULL, &Botonstart.w, &Botonstart.h);

			x_pos_start = (float)((WINDOW_WIDTH - Botonstart.w) / 2);
			y_pos_start = (float)((WINDOW_HEIGHT - Botonstart.h) / 2) - 10;

			Botonstart.y = (int)y_pos_start;
			Botonstart.x = (int)x_pos_start;

			if (SDL_MOUSEMOTION)
			{
				if (event.motion.x > 0 && event.motion.x <= WINDOW_WIDTH) {
					if (event.motion.y > 0 && event.motion.y <= WINDOW_HEIGHT) {
						sagua.x = event.motion.x;
						sagua.y = event.motion.y;
					}
				}

				if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
				{
					BotonExit.h = 70;
					BotonExit.w = 183;

					BotonExit.x = 590;
					BotonExit.y = 601;
				}
				if ((sagua.x > x_pos_controls&& sagua.x < Botoncontrols.w + x_pos_controls) && (sagua.y > y_pos_controls&& sagua.y < Botoncontrols.h + y_pos_controls)) // boton de controles
				{
					Botoncontrols.h = 65;
					Botoncontrols.w = 225;

					Botoncontrols.x = 570;
					Botoncontrols.y = 475;
				}

				if ((sagua.x > x_pos_start&& sagua.x < Botonstart.w + x_pos_start) && (sagua.y > y_pos_start&& sagua.y < Botonstart.h + y_pos_start)) // boton de start
				{
					Botonstart.h = 75;
					Botonstart.w = 184;

					Botonstart.x = 589;
					Botonstart.y = 338;
				}
			}

			//printf("Sagua X: %d Y: %d", sagua.x, sagua.y);
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON_LEFT)
				{
					if ((sagua.x > x_pos && sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
					{
						return 3;
					}

					if ((sagua.x > x_pos_controls&& sagua.x < Botoncontrols.w + x_pos_controls) && (sagua.y > y_pos_controls&& sagua.y < Botoncontrols.h + y_pos_controls)) // boton de controles
					{
						return 2;
					}

					if ((sagua.x > x_pos_start&& sagua.x < Botonstart.w + x_pos_start) && (sagua.y > y_pos_start&& sagua.y < Botonstart.h + y_pos_start)) // boton de start
					{
						return 1;
					}
				}
				break;
			case SDL_QUIT:
				return 3;
			}

			SDL_RenderCopy(rend, tex, NULL, NULL);
			SDL_RenderCopy(rend, texBotonExit, NULL, &BotonExit);
			SDL_RenderCopy(rend, texBotoncontrols, NULL, &Botoncontrols);
			SDL_RenderCopy(rend, texBotonstart, NULL, &Botonstart);
			SDL_RenderPresent(rend);

		}
		if (randSeed < 1000) randSeed++;
		else randSeed = 0;
	}
	// Valor de los returns: Exit 3, controles 2, start 1
	return CloseRequest;
}

int MenuController() 
{
	/**
	* Funcion del menú de controles, se va a seguir reproduciendo hasta que haya una selección
	* Returnea el numero de la selección
	*/
	SDL_Event event;

	int CloseRequest = 10;
	float x_pos, y_pos; //estas son las del fondo y las de EXit
	float x_pos_teclado, y_pos_teclado;
	float x_pos_play, y_pos_play;

	while (CloseRequest == 10)
	{
		while (SDL_PollEvent(&event))
		{
			SDL_QueryTexture(tex, NULL, NULL, &Fondo.w, &Fondo.h);


			x_pos = (float)(WINDOW_WIDTH - Fondo.w) / 2;
			y_pos = (float)(WINDOW_HEIGHT - Fondo.h) / 2;

			Fondo.y = (int)y_pos;
			Fondo.x = (int)x_pos;

			SDL_QueryTexture(texBotonExit, NULL, NULL, &BotonExit.w, &BotonExit.h);

			x_pos = (float)((WINDOW_WIDTH - BotonExit.w) / 2);
			y_pos = (float)((WINDOW_HEIGHT - BotonExit.h) / 2) + 250;

			BotonExit.y = (int)y_pos;
			BotonExit.x = (int)x_pos;

			SDL_QueryTexture(texBotonteclado, NULL, NULL, &Botonteclado.w, &Botonteclado.h);

			Botonteclado.h /= 2;
			Botonteclado.w /= 2;


			x_pos_teclado = (float)((WINDOW_WIDTH - Botonteclado.w) / 2) - 200;
			y_pos_teclado = (float)((WINDOW_HEIGHT - Botonteclado.h) / 2) + 125;

			Botonteclado.y = (int)y_pos_teclado;
			Botonteclado.x = (int)x_pos_teclado;


			SDL_QueryTexture(texBotonplay, NULL, NULL, &Botonplay.w, &Botonplay.h);

			Botonplay.h /= 2;
			Botonplay.w /= 2;


			x_pos_play = (float)((WINDOW_WIDTH - Botonplay.w) / 2) + 200;
			y_pos_play = (float)((WINDOW_HEIGHT - Botonplay.h) / 2) + 125;

			Botonplay.y = (int)y_pos_play;
			Botonplay.x = (int)x_pos_play;

			if (SDL_MOUSEMOTION)
			{
				if (event.motion.x > 0 && event.motion.x <= WINDOW_WIDTH) {
					if (event.motion.y > 0 && event.motion.y <= WINDOW_HEIGHT) {
						sagua.x = event.motion.x;
						sagua.y = event.motion.y;
					}
				}
			}

			if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos))
			{
				BotonExit.h = 70;
				BotonExit.w = 183;

				BotonExit.x = 590;
				BotonExit.y = 601;
			}

			if ((sagua.x > x_pos_teclado&& sagua.x < Botonteclado.w + x_pos_teclado) && (sagua.y > y_pos_teclado&& sagua.y < Botonteclado.h + y_pos_teclado))
			{
				Botonteclado.h = 90;
				Botonteclado.w = 213;

				Botonteclado.x = 380;
				Botonteclado.y = 466;
			}

			if ((sagua.x > x_pos_play&& sagua.x < Botonplay.w + x_pos_play) && (sagua.y > y_pos_play&& sagua.y < Botonplay.h + y_pos_play))
			{
				Botonplay.h = 100;
				Botonplay.w = 140;

				Botonplay.x = 813;
				Botonplay.y = 462;
			}

			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON_LEFT)
				{
					if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
					{
						CloseRequest = 1;
					}

					if ((sagua.x > x_pos_teclado&& sagua.x < Botonteclado.w + x_pos_teclado) && (sagua.y > y_pos_teclado&& sagua.y < Botonteclado.h + y_pos_teclado)) // boton de controles es del teklado 
					{
						CloseRequest = 0;
					}

					if ((sagua.x > x_pos_play&& sagua.x < Botonplay.w + x_pos_play) && (sagua.y > y_pos_play&& sagua.y < Botonplay.h + y_pos_play)) // boton de start es del mando de play
					{
						CloseRequest = -1;
					}

				}
				break;
			case SDL_QUIT:
				CloseRequest = 5;
				break;
			}
		}

		SDL_RenderCopy(rend, tex, NULL, &Fondo);
		SDL_RenderCopy(rend, texBotonExit, NULL, &BotonExit);
		SDL_RenderCopy(rend, texBotonteclado, NULL, &Botonteclado);
		SDL_RenderCopy(rend, texBotonplay, NULL, &Botonplay);

		SDL_RenderPresent(rend);

	}

	if (CloseRequest == -1) // boton play
	{

		CloseRequest = CuantosJugadores(rend);

	}
	// Returnea 1 en el exit, 0 en jugar con teclado y -1 en jugar con mando
	return CloseRequest;
}

int CuantosJugadores()
{
	/**
	* Funcion del menú de seleccion de jugadores , se va a seguir reproduciendo hasta que haya una selección
	* Returnea el numero de la selección
	*/
	SDL_Event event;

	SDL_Rect BotonCuatroJugadores;
	SDL_Rect BotonTresJugadores;
	SDL_Rect BotonDosJugadores;

	int CloseRequest = 10;
	float x_pos, y_pos; //estas son las del fondo y las de EXit
	float x_pos_TresJugadores, y_pos_TresJugadores;
	float x_pos_DosJugadores, y_pos_DosJugadores;
	float x_pos_CuatroJugadores, y_pos_CuatroJugadores;

	while (CloseRequest == 10)
	{

		while (SDL_PollEvent(&event))
		{
			SDL_QueryTexture(tex, NULL, NULL, &Fondo.w, &Fondo.h);

			x_pos = (float)(WINDOW_WIDTH - Fondo.w) / 2;
			y_pos = (float)(WINDOW_HEIGHT - Fondo.h) / 2;

			Fondo.y = (int)y_pos;
			Fondo.x = (int)x_pos;

			SDL_QueryTexture(texBotonExit, NULL, NULL, &BotonExit.w, &BotonExit.h);

			x_pos = (float)((WINDOW_WIDTH - BotonExit.w) / 2);
			y_pos = (float)((WINDOW_HEIGHT - BotonExit.h) / 2) + 300;

			BotonExit.y = (int)y_pos;
			BotonExit.x = (int)x_pos;

			SDL_QueryTexture(texBotonCuatroJugadores, NULL, NULL, &BotonCuatroJugadores.w, &BotonCuatroJugadores.h);

			BotonCuatroJugadores.h /= 3;
			BotonCuatroJugadores.w /= 3;

			x_pos_CuatroJugadores = (float)((WINDOW_WIDTH - BotonCuatroJugadores.w) / 2) + 200;
			y_pos_CuatroJugadores = (float)((WINDOW_HEIGHT - BotonCuatroJugadores.h) / 2) + 100;

			BotonCuatroJugadores.y = (int)y_pos_CuatroJugadores;
			BotonCuatroJugadores.x = (int)x_pos_CuatroJugadores;

			SDL_QueryTexture(texBotonTresJugadores, NULL, NULL, &BotonTresJugadores.w, &BotonTresJugadores.h);

			BotonTresJugadores.h /= 3;
			BotonTresJugadores.w /= 3;

			x_pos_TresJugadores = (float)((WINDOW_WIDTH - BotonTresJugadores.w) / 2);
			y_pos_TresJugadores = (float)((WINDOW_HEIGHT - BotonTresJugadores.h) / 2) + 100;

			BotonTresJugadores.y = (int)y_pos_TresJugadores;
			BotonTresJugadores.x = (int)x_pos_TresJugadores;

			SDL_QueryTexture(texBotonDosJugadores, NULL, NULL, &BotonDosJugadores.w, &BotonDosJugadores.h);

			BotonDosJugadores.h /= 2;
			BotonDosJugadores.w /= 2;


			x_pos_DosJugadores = (float)((WINDOW_WIDTH - BotonDosJugadores.w) / 2) - 200;
			y_pos_DosJugadores = (float)((WINDOW_HEIGHT - BotonDosJugadores.h) / 2) + 100;

			BotonDosJugadores.y = (int)y_pos_DosJugadores;
			BotonDosJugadores.x = (int)x_pos_DosJugadores;

			if (SDL_MOUSEMOTION)
			{
				if (event.motion.x > 0 && event.motion.x <= WINDOW_WIDTH) {
					if (event.motion.y > 0 && event.motion.y <= WINDOW_HEIGHT) {
						sagua.x = event.motion.x;
						sagua.y = event.motion.y;
					}
				}
			}
			if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
			{
				BotonExit.h = 75;
				BotonExit.w = 180;

				BotonExit.x = 595;
				BotonExit.y = 651;
			}

			if ((sagua.x > x_pos_TresJugadores&& sagua.x < BotonTresJugadores.w + x_pos_TresJugadores) && (sagua.y > y_pos_TresJugadores&& sagua.y < BotonTresJugadores.h + y_pos_TresJugadores)) // boton de 3 jugadores 
			{
				BotonTresJugadores.h = 170;
				BotonTresJugadores.w = 120;

				BotonTresJugadores.x = 625;
				BotonTresJugadores.y = 404;
			}

			if ((sagua.x > x_pos_DosJugadores&& sagua.x < BotonDosJugadores.w + x_pos_DosJugadores) && (sagua.y > y_pos_DosJugadores&& sagua.y < BotonDosJugadores.h + y_pos_DosJugadores)) // boton de start es 2 jugadores
			{
				BotonDosJugadores.x = 395;
				BotonDosJugadores.y = 423;
				BotonDosJugadores.w = 180;
				BotonDosJugadores.h = 132;
			}

			if ((sagua.x > x_pos_CuatroJugadores&& sagua.x < BotonCuatroJugadores.w + x_pos_CuatroJugadores) && (sagua.y > y_pos_CuatroJugadores&& sagua.y < BotonCuatroJugadores.h + y_pos_CuatroJugadores))
			{
				BotonCuatroJugadores.x = 825;
				BotonCuatroJugadores.y = 404;
				BotonCuatroJugadores.w = 120;
				BotonCuatroJugadores.h = 170;
			}

			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON_LEFT)
				{
					if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
					{
						CloseRequest = 1;
					}

					if ((sagua.x > x_pos_TresJugadores&& sagua.x < BotonTresJugadores.w + x_pos_TresJugadores) && (sagua.y > y_pos_TresJugadores&& sagua.y < BotonTresJugadores.h + y_pos_TresJugadores)) // boton de 3 jugadores 
					{
						CloseRequest = 3;
					}

					if ((sagua.x > x_pos_DosJugadores&& sagua.x < BotonDosJugadores.w + x_pos_DosJugadores) && (sagua.y > y_pos_DosJugadores&& sagua.y < BotonDosJugadores.h + y_pos_DosJugadores)) // boton de start es 2 jugadores
					{
						CloseRequest = 2;
					}

					if ((sagua.x > x_pos_CuatroJugadores&& sagua.x < BotonCuatroJugadores.w + x_pos_CuatroJugadores) && (sagua.y > y_pos_CuatroJugadores&& sagua.y < BotonCuatroJugadores.h + y_pos_CuatroJugadores))
					{
						CloseRequest = 4;
					}

				}
				break;
			case SDL_QUIT:
				CloseRequest = 5;
				break;
			}
		}
		SDL_RenderCopy(rend, tex, NULL, &Fondo);
		SDL_RenderCopy(rend, texBotonExit, NULL, &BotonExit);
		SDL_RenderCopy(rend, texBotonTresJugadores, NULL, &BotonTresJugadores);
		SDL_RenderCopy(rend, texBotonDosJugadores, NULL, &BotonDosJugadores);
		SDL_RenderCopy(rend, texBotonCuatroJugadores, NULL, &BotonCuatroJugadores);

		SDL_RenderPresent(rend);

	}
	//Devuelve 1 boton exit, 2 dos jugadores, 3 tres, 4 cuatro jugadores
	return CloseRequest;
}

int MenuDeComoJugar()
{
	/**
	* Funcion del menú de como jugar , se va a seguir reproduciendo hasta que haya una selección
	* Returnea el numero de la selección
	*/
	SDL_Event event;
	saguPos sagua;
	SDL_Rect Fondo;
	SDL_Rect BotonExit;

	int CloseRequest = 10;
	float x_pos, y_pos; //estas son las del fondo y las de EXit


	while (CloseRequest == 10)
	{
		while (SDL_PollEvent(&event))
		{
			SDL_QueryTexture(texMenuControls, NULL, NULL, &Fondo.w, &Fondo.h);


			x_pos = (float)(WINDOW_WIDTH - Fondo.w) / 2;
			y_pos = (float)(WINDOW_HEIGHT - Fondo.h) / 2;

			Fondo.y = (int)y_pos;
			Fondo.x = (int)x_pos;


			SDL_QueryTexture(texBotonExit, NULL, NULL, &BotonExit.w, &BotonExit.h);

			x_pos = (float)((WINDOW_WIDTH - BotonExit.w) / 2);
			y_pos = (float)((WINDOW_HEIGHT - BotonExit.h) / 2) + 300;

			BotonExit.y = (int)y_pos;
			BotonExit.x = (int)x_pos;

			if (SDL_MOUSEMOTION)
			{
				sagua.x = event.motion.x;
				sagua.y = event.motion.y;
			}

			if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
			{
				BotonExit.x = 590;
				BotonExit.y = 648;
				BotonExit.w = 180;
				BotonExit.h = 75;
			}
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON_LEFT)
				{
					if ((sagua.x > x_pos&& sagua.x < BotonExit.w + x_pos) && (sagua.y > y_pos&& sagua.y < BotonExit.h + y_pos)) // bonton de exit
					{
						CloseRequest = 1;
					}

				}
				break;
			case SDL_QUIT:
				CloseRequest = 3;
				break;
			}
		}
		SDL_RenderCopy(rend, texMenuControls, NULL, &Fondo);
		SDL_RenderCopy(rend, texBotonExit, NULL, &BotonExit);
		SDL_RenderPresent(rend);
	}
	// devuelve 1 para salir
	return CloseRequest;
}

void balaMovimiento() {

	/**
	* Aplica el movimiento a la bala
	*
	*/

	for (int i = 0; i < 20; i++)
	{
		//Si la velocidad es distinta a 0 y se está disparando le aplica la velocidad.
		if (disparo[i].speed != 0 && disparo[i].disparado == 1)
		{
			disparo[i].x += disparo[i].speed;
			hitboxBala[i].x = disparo[i].x;
		}
	}
}

void spriteMovimiento() {
	/**
	* En esta funcion movemos a los players y a sus hitboxes
	*
	*/
	for (int i = 0; i < jokalariKopurua; i++) {
		if (jokalaria[i].egoera == 1) {
			jokalaria[i].x += (int)x_vel[i] / 60;
			jokalaria[i].y += (int)y_vel[i] / 60;
			hitbox[i].y = jokalaria[i].y - PLAYERH;
			hitbox[i].x = jokalaria[i].x - PLAYERW;
		}
	}
}

void rendPuntuPantaila()
{
	/**
	* Segun que caso printea una imagen u otra; coon 3 jugadores printea 3
	*
	*/
	switch (jokalariKopurua)
	{
	case 2:
		SDL_RenderCopy(rend, puntuPantaila[0], NULL, NULL);
		break;
	case 3:
		SDL_RenderCopy(rend, puntuPantaila[1], NULL, NULL);
		break;
	case 4:
		SDL_RenderCopy(rend, puntuPantaila[2], NULL, NULL);
		break;
	}
}

void rendNumeros(int puntuak, int x, int y)
{
	/**
	* Segun cauntos puntos tenga va a printear una imagen u otra
	*
	*/
	switch (puntuak)
	{
	case 0:
		posNum[0].x = x;
		posNum[0].y = y;
		SDL_RenderCopy(rend, numeros[0], NULL, &posNum[0]);
		break;
	case 1:
		posNum[1].x = x;
		posNum[1].y = y;
		SDL_RenderCopy(rend, numeros[1], NULL, &posNum[1]);
		break;
	case 2:
		posNum[2].x = x;
		posNum[2].y = y;
		SDL_RenderCopy(rend, numeros[2], NULL, &posNum[2]);
		break;
	case 3:
		posNum[3].x = x;
		posNum[3].y = y;
		SDL_RenderCopy(rend, numeros[3], NULL, &posNum[3]);
		break;
	case 4:
		posNum[4].x = x;
		posNum[4].y = y;
		SDL_RenderCopy(rend, numeros[4], NULL, &posNum[4]);
		break;
	case 5:
		posNum[5].x = x;
		posNum[5].y = y;
		SDL_RenderCopy(rend, numeros[5], NULL, &posNum[5]);
		break;
	case 6:
		posNum[6].x = x;
		posNum[6].y = y;
		SDL_RenderCopy(rend, numeros[6], NULL, &posNum[6]);
		break;
	case 7:
		posNum[7].x = x;
		posNum[7].y = y;
		SDL_RenderCopy(rend, numeros[7], NULL, &posNum[7]);
		break;
	case 8:
		posNum[8].x = x;
		posNum[8].y = y;
		SDL_RenderCopy(rend, numeros[8], NULL, &posNum[8]);
		break;
	case 9:
		posNum[9].x = x;
		posNum[9].y = y;
		SDL_RenderCopy(rend, numeros[9], NULL, &posNum[9]);
		break;
	}
}

void aplicarMugimenduTeklado() {

	/**
	* Alpicar el movimiento caundo no hay mandos conectados
	*
	*/

	if (seleccionDeMandos == 0) {
		x_vel[0] = 0;
		x_vel[1] = 0;
		if (transEgoera == -1) {

			//Aplicar movimiento P1
			if (jokalaria[0].egoera == 1) {

				//Movimiento Salto
				if (teklatua.Wdown && saltoaEgin[0] == 1)
				{
					saltoaEgin[0] = 0;
					y_vel[0] = -1050;
					Mix_PlayChannel(-1, jumpSound, 0);
				}

				//Movimiento lateral
				if (teklatua.Ddown && !teklatua.Adown) x_vel[0] = SPEED;
				if (teklatua.Adown && !teklatua.Ddown) x_vel[0] = -SPEED;


				//Movimiento Blink
				if (teklatua.Adown && !teklatua.Ddown && teklatua.SHIFTdown == 1)
				{
					if (jokalaria[0].blink == 0)
					{
						jokalaria[0].x = jokalaria[0].x - DASH;
						x_vel[0] = (float)jokalaria[0].x;
						blinkPhase[0] = -1;
						jokalaria[0].blink = 60;
					}
				}
				if (teklatua.Ddown && !teklatua.Adown && teklatua.SHIFTdown == 1)
				{
					if (jokalaria[0].blink == 0)
					{
						jokalaria[0].x = jokalaria[0].x + DASH;
						x_vel[0] = (float)jokalaria[0].x;
						blinkPhase[0] = -1;
						jokalaria[0].blink = 60;
					}
				}
			}


			//Aplicar movimiento P2
			if (jokalaria[1].egoera == 1) {
				//Movimiento Salto
				if (teklatua.UPdown && saltoaEgin[1] == 1)
				{
					saltoaEgin[1] = 0;
					y_vel[1] = -1050;
					Mix_PlayChannel(-1, jumpSound, 0);
				}

				//Movimiento lateral
				if (teklatua.RIGHTdown && !teklatua.LEFTdown) x_vel[1] = SPEED;
				if (teklatua.LEFTdown && !teklatua.RIGHTdown) x_vel[1] = -SPEED;

				//Movimiento Blink
				if (teklatua.RIGHTdown && !teklatua.LEFTdown && teklatua.PUNTOdown == 1)
				{
					if (jokalaria[1].blink == 0)
					{
						jokalaria[1].x = jokalaria[1].x + DASH;
						x_vel[1] = (float)jokalaria[1].x;
						blinkPhase[1] = -1;
						jokalaria[1].blink = 60;
					}
				}
				if (teklatua.LEFTdown && !teklatua.RIGHTdown && teklatua.PUNTOdown == 1)
				{
					if (jokalaria[1].blink == 0)
					{
						jokalaria[1].x = jokalaria[1].x - DASH;
						x_vel[1] = (float)jokalaria[1].x;
						blinkPhase[1] = -1;
						jokalaria[1].blink = 60;
					}
				}
			}

			if (jokalaria[0].blink > 0) jokalaria[0].blink--;
			if (jokalaria[1].blink > 0) jokalaria[1].blink--;
		}
	}
}

void acabarConElDisparo() {

	/**
	* Acabar con el disparo si choca con el mapa o se sale de la pantalla
	*
	*/

	for (int i = 0; i < 20; i++)
	{
		//Fuera del mapa
		if (disparo[i].x < 0 || disparo[i].x > 1366)
		{
			disparo[i].disparado = 0;
		}
		//talka con el mapa (falta)

		//Solucion de la talka
		if (disparo[i].disparado == 0)
		{
			disparo[i].direc = 1;
			disparo[i].speed = 30;
			disparo[i].x = 0;
			disparo[i].y = -100;
			hitboxBala[i].x = disparo[i].x;
			hitboxBala[i].y = disparo[i].y;
		}
	}
}

int transicio(int kont) {
	/**
	 *	En esta funcion se suma un punto al ultimo jugador vivo y se llama a la pantalla de transicion
	 *
	 */

	if (jokalariKopurua - kont <= 1)
	{
		for (int i = 0; i < jokalariKopurua; i++)
		{
			if (jokalaria[i].egoera == 1)
			{
				jokalaria[i].puntuak++;
			}
		}

		//Renderear los puntos en la pantalla
		rendPuntuPantaila();

		//Pone los puntos actuales en la pos que le pasamos
		for (int i = 0; i < jokalariKopurua; i++)
		{
			if (i == 0)
			{
				rendNumeros(jokalaria[i].puntuak, 470, 330);
			}
			if (i == 1)
			{
				rendNumeros(jokalaria[i].puntuak, 788, 330);
			}
			if (i == 2)
			{
				rendNumeros(jokalaria[i].puntuak, 620, 244);
			}
			if (i == 3)
			{
				rendNumeros(jokalaria[i].puntuak, 620, 423);
			}
			jokalaria[i].egoera = 1;
			jokalaria[i].kontagarri = 1;
			jokalaria[i].x = WINDOW_WIDTH / 2;
			jokalaria[i].y = WINDOW_HEIGHT / 2;
			y_vel[i] = 0;
		}
		SDL_RenderPresent(rend);
		//Delay para que de tiempo a verlo
		SDL_Delay(2000);
		return 1;
	}
	else return 0;
}

int resetKontagarri(int kont) {
	// El kontagarri es para que solo mueras una vez por mapa, en esta funcion lo reseteamos
	//Parametros --> kont: es lo que te impide morir mas de una vez.
	for (int i = 0; i < jokalariKopurua; i++)
	{
		if (jokalaria[i].egoera == 0 && jokalaria[i].kontagarri == 1)
		{
			jokalaria[i].kontagarri = 0;
			kont++;
		}
	}
	return kont;
}

void disparar(int i) {

	/**
	* Esta funcion hace el disparo.
	*
	*/

	//Llevamos la bala y su HB a la pos del jugador + un chachito para que no se mate
	if (jokalaria[i].orient == 1 && jokalaria[i].egoera == 1)
	{
		disparo[disparoact].x = jokalaria[i].x + PLAYERW;
		disparo[disparoact].y = jokalaria[i].y;
		hitboxBala[disparoact].x = disparo[disparoact].x;
		hitboxBala[disparoact].y = disparo[disparoact].y;
		Mix_PlayChannel(-1, pistolaSound, 0);
	}
	else
	{
		disparo[disparoact].x = jokalaria[i].x - PLAYERW;
		disparo[disparoact].y = jokalaria[i].y;
		hitboxBala[disparoact].x = disparo[disparoact].x;
		hitboxBala[disparoact].y = disparo[disparoact].y;
		Mix_PlayChannel(-1, pistolaSound, 0);
	}

	jokalaria[i].munizioa -= 1;
	//Si la municion es 0 le quito el arma
	if (jokalaria[i].munizioa == 0)
	{
		jokalaria[i].arma = 0;
	}

	//Ponerle la orientacion que es debida en caso de que no este disparado y lo pongo en estado disparado, y sumo uno a disparoact
	if (disparo[disparoact].disparado == 0)
	{
		if (jokalaria[i].orient == 1)
		{
			disparo[disparoact].direc = 1;
		}
		else if (jokalaria[i].orient == 0)
		{
			disparo[disparoact].direc = 0;
		}

		if (disparo[disparoact].direc == 0)
		{
			if (disparo[disparoact].speed > 0)
			{
				disparo[disparoact].speed *= -1;
			}
			disparo[disparoact].disparado = 1;
			disparoact++;
		}
		else if (disparo[disparoact].direc == 1)
		{
			if (disparo[disparoact].speed < 0)
			{
				disparo[disparoact].speed *= -1;
			}
			disparo[disparoact].disparado = 1;
			disparoact++;
		}
	}
}

void colisionBalaJugador() {

	/**
	* Esta funcion comprueba si hay colision entre el jugador y la bala.
	*
	*/

	for (int i = 0; i < jokalariKopurua; i++)
	{
		//20 porque el array de balas tiene 20
		for (int j = 0; j < 20; j++)
		{
			if (disparo[j].x > jokalaria[i].x - PLAYERW && disparo[j].x < jokalaria[i].x + PLAYERW)
			{
				if (disparo[j].y > jokalaria[i].y - PLAYERH && disparo[j].y < jokalaria[i].y + PLAYERH)
				{
					//en caso de colision la bala se pone en 0 por lo cual desaparece y el jugador en -1 por lo cual
					//Empezará la anim de morir.
					if (jokalaria[i].egoera == 1) {
						jokalaria[i].egoera = -1;
						disparo[j].disparado = 0;
					}
				}
			}
		}
	}
}

void calcularOrientacio(teklau* teklatua, jok jokalaria[]) {

	/**
	* Esta funcion calcula la orientación del jugador.
	*
	*/

	//Si hay mandos lo compruebo con los joysticks y si no con el Dpad
	if (seleccionDeMandos != 0) {
		for (int i = 0; i < jokalariKopurua; i++)
		{

			if (mandos[i].RIGHTdown == 1 || mandos[i].AxisX == 1)
			{
				jokalaria[i].orient = 1;
			}
			else if (mandos[i].LEFTdown == 1 || mandos[i].AxisX == -1)
			{
				jokalaria[i].orient = 0;
			}

		}
	}
	// SI no ha mandos lo compruebo con el teclado
	else {
		if ((*teklatua).Ddown == 1)
		{
			jokalaria[0].orient = 1;
		}
		else if ((*teklatua).Adown == 1)
		{
			jokalaria[0].orient = 0;
		}
		if ((*teklatua).RIGHTdown == 1)
		{
			jokalaria[1].orient = 1;
		}
		else if ((*teklatua).LEFTdown == 1)
		{
			jokalaria[1].orient = 0;
		}
	}
}

void comprobarAccionesMando() {
	/**
	* Esta funcion calculo todas las acciones de los mandos
	*
	*/
	if (!seleccionDeMandos == 0 && transEgoera == -1) {
		for (int i = 0; i < jokalariKopurua; i++) {
			if (jokalaria[i].egoera == 1) {
				x_vel[i] = 0;

				//Salto
				if (mandos[i].Adown == 1 && saltoaEgin[i] == 1)
				{
					saltoaEgin[i] = 0;
					y_vel[i] = -1050;
					Mix_PlayChannel(-1, jumpSound, 0);
				}

				//Movimiento
				if ((mandos[i].RIGHTdown && !mandos[i].LEFTdown) || (mandos[i].AxisX == 1)) x_vel[i] = SPEED;
				if ((mandos[i].LEFTdown && !mandos[i].RIGHTdown) || (mandos[i].AxisX == -1)) x_vel[i] = -SPEED;

				//EasterEgg
				if (mandos[i].Ydown && easterCoolDown[i] == 0) {
					Mix_PlayChannel(-1, miauSound, 0);
					easterCoolDown[i] = 40;
				}

				//Blink
				if ((mandos[i].RIGHTdown && !mandos[i].LEFTdown && mandos[i].Bdown == 1) || (mandos[i].AxisX == 1 && mandos[i].Bdown == 1))
				{
					if (jokalaria[i].blink == 0)
					{
						jokalaria[i].x = jokalaria[i].x + DASH;
						x_vel[i] = (float)jokalaria[i].x;
						blinkPhase[i] = -1;
						jokalaria[i].blink = 60;
					}
				}
				if ((mandos[i].LEFTdown && !mandos[i].RIGHTdown && mandos[i].Bdown == 1) || (mandos[i].AxisX == -1 && mandos[i].Bdown == 1))
				{
					if (jokalaria[i].blink == 0)
					{
						jokalaria[i].x = jokalaria[i].x - DASH;
						x_vel[i] = (float)jokalaria[i].x;
						blinkPhase[i] = -1;
						jokalaria[i].blink = 60;
					}
				}

				//CD del blink
				if (jokalaria[i].blink > 0)
				{
					jokalaria[i].blink -= 1;
				}
			}
			//Reser CD
			if (easterCoolDown[i] > 0) easterCoolDown[i] -= 1;

		}
	}
}

void chocarSpawner(int spawnerkopurua) {

	/**
	* Esta funcion comprueba las coliciones con los spawners de armas.
	*
	*/

	//Todos los jugadores
	for (int i = 0; i < jokalariKopurua; i++)
	{
		//todos los spawners
		for (int j = 0; j < spawnerkopurua; j++)
		{
			//Mira el spawner del mapa
			if (jokalaria[i].x + PLAYERW > arrayNivelak[nivela].arrayKajak[j].x&& jokalaria[i].x - PLAYERW < arrayNivelak[nivela].arrayKajak[j].x + 31)
			{
				// Mira el spawner 
				if (jokalaria[i].y + PLAYERH > arrayNivelak[nivela].arrayKajak[j].y&& jokalaria[i].y - PLAYERH < arrayNivelak[nivela].arrayKajak[j].y + 30)
				{
					//Si choca player. arma es uno y depende con que tipo choque le da 1 o 3 de ammo
					if (arrayNivelak[nivela].arrayKajak[j].armaDisponible == 1)
					{
						jokalaria[i].arma = 1;
						if (arrayNivelak[nivela].arrayKajak[j].typoArma == 1)
						{
							jokalaria[i].munizioa = 1;
						}
						else if (arrayNivelak[nivela].arrayKajak[j].typoArma == 2)
						{
							jokalaria[i].munizioa = 3;
						}
						//Le ponemos el CD al spawner
						arrayNivelak[nivela].arrayKajak[j].armaDisponible = 0;
						arrayNivelak[nivela].arrayKajak[j].CD = 120;
					}
				}
			}
		}
	}

	//Aplicar el CD
	for (int i = 0; i < spawnerkopurua; i++)
	{
		if (arrayNivelak[nivela].arrayKajak[i].armaDisponible == 0)
		{
			arrayNivelak[nivela].arrayKajak[i].CD -= 1;
		}
		if (arrayNivelak[nivela].arrayKajak[i].CD == 0)
		{
			arrayNivelak[nivela].arrayKajak[i].armaDisponible = 1;
		}
	}
}

int talkatxen() {
	/**
   * Comprobar si hay una talka
   *
   */
	for (int j = 0; j < jokalariKopurua; j++)
	{
		//Caida por los niveles
		if (nivela != 10) {
			if (jokalaria[j].y > WINDOW_HEIGHT + 70 && jokalaria[j].y < 1000)
			{
				jokalaria[j].egoera = -1;
				jokalaria[j].y = 1000;
			}
			if (jokalaria[j].y > 1000)
			{
				jokalaria[j].y = 1000;
			}
		}
		//Caidas mapa de victoria
		else if (nivela == 10) {
			if (jokalaria[j].y > WINDOW_HEIGHT + 70 )
			{
				if (jokalaria[j].x < WINDOW_HEIGHT / 2) {
					close_requested = 1;
					return 1;
				}
				else {
					close_requested = 99;
					return 99;
				}
			}
		}

		int i = 0;
		//Lineakop va a ser la cantidad de lineas que metamos en el arraylineas[]
		while (i < arrayNivelak[nivela].karratuKop)
		{
			int talkahoriz, talkabert, talkabarru;
			talkahoriz = talkabert = talkabarru = 0;

			if (jokalaria[j].x - arrayNivelak[nivela].arrayKarratu[i].x0 > arrayNivelak[nivela].arrayKarratu[i].x - jokalaria[j].x)
			{
				distX[j] = arrayNivelak[nivela].arrayKarratu[i].x - jokalaria[j].x;
			}
			else
			{
				distX[j] = jokalaria[j].x - arrayNivelak[nivela].arrayKarratu[i].x0;
			}
			if (jokalaria[j].y - arrayNivelak[nivela].arrayKarratu[i].y0 > arrayNivelak[nivela].arrayKarratu[i].y - jokalaria[j].y)
			{
				distY[j] = arrayNivelak[nivela].arrayKarratu[i].y - jokalaria[j].y;
			}
			else
			{
				distY[j] = jokalaria[j].y - arrayNivelak[nivela].arrayKarratu[i].y0;
			}


			//Mirar en que parte del mapa esta y si hay talka
			if (distX[j] >= distY[j])
			{
				talkahoriz = talkahorizontal(arrayNivelak[nivela].arrayKarratu[i], jokalaria[j]);
			}
			else
			{
				talkabert = talkabertical(arrayNivelak[nivela].arrayKarratu[i], jokalaria[j]);
			}

			talkabarru = talkaBarruan(arrayNivelak[nivela].arrayKarratu[i], jokalaria[j]);

			//Aplicar la talka
			if (talkabarru == 1)
			{
				if (jokalaria[j].x - arrayNivelak[nivela].arrayKarratu[i].x0 <= arrayNivelak[nivela].arrayKarratu[i].x - jokalaria[j].x && arrayNivelak[nivela].arrayKarratu[i].ondoan == -1)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x0 - PLAYERW;
				}
				else if (jokalaria[j].x - arrayNivelak[nivela].arrayKarratu[i].x0 > arrayNivelak[nivela].arrayKarratu[i].x - jokalaria[j].x && arrayNivelak[nivela].arrayKarratu[i].ondoan == -1)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x + PLAYERW;
				}
				else if (arrayNivelak[nivela].arrayKarratu[i].ondoan == 1)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x0 - PLAYERW;
				}
				else if (arrayNivelak[nivela].arrayKarratu[i].ondoan == 0)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x + PLAYERW;
				}
			}

			else if (talkabert == 1)
			{
				//aplicartalkabert(arrayNivelak[0].arrayLinea[i], jokalaria[j]);

				if (jokalaria[j].x <= arrayNivelak[nivela].arrayKarratu[i].x + PLAYERW && jokalaria[j].x >= arrayNivelak[nivela].arrayKarratu[i].x)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x + PLAYERW;
				}
				else if (jokalaria[j].x > arrayNivelak[nivela].arrayKarratu[i].x0 - PLAYERW && jokalaria[j].x < arrayNivelak[nivela].arrayKarratu[i].x0)
				{
					jokalaria[j].x = arrayNivelak[nivela].arrayKarratu[i].x0 - PLAYERW;
				}
				//printf("V");
			}
			else if (talkahoriz == 1)
			{
				//aplicartalkahoriz(arrayNivelak[0].arrayLinea[i], jokalaria[j]);
				if (jokalaria[j].y <= arrayNivelak[nivela].arrayKarratu[i].y + PLAYERH && jokalaria[j].y >= arrayNivelak[nivela].arrayKarratu[i].y)
				{
					jokalaria[j].y = arrayNivelak[nivela].arrayKarratu[i].y + PLAYERH;
					if (y_vel[j] <= 0)
					{
						y_vel[j] = 0;
					}
				}
				else if (jokalaria[j].y >= arrayNivelak[nivela].arrayKarratu[i].y0 - PLAYERH && jokalaria[j].y <= arrayNivelak[nivela].arrayKarratu[i].y0)
				{
					jokalaria[j].y = arrayNivelak[nivela].arrayKarratu[i].y0 - PLAYERH;
					if (y_vel[j] >= 0)
					{
						y_vel[j] = 0;
						saltoaEgin[j] = 1;
					}
				}
			}
			i++;
		}
		y_vel[j] = y_vel[j] + GRAVEDAD;
	}
	return 0;
}

void colisionBalaMapa(int karratuKop)
{
	/**
	* Comprueba la colision de la bala con el mapa
	*
	*/

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < karratuKop; j++)
		{
			//Si se choca mandamos el estado de la bala a 0 por lo cual se va del mapa y le quitamos la velocidad etc etc...
			if (disparo[i].x + DISPAROW > arrayNivelak[nivela].arrayKarratu[j].x0&& disparo[i].x < arrayNivelak[nivela].arrayKarratu[j].x)
			{
				if (disparo[i].y + DISPAROH > arrayNivelak[nivela].arrayKarratu[j].y0&& disparo[i].y < arrayNivelak[nivela].arrayKarratu[j].y)
				{
					disparo[i].disparado = 0;
				}
			}
		}
	}
}

void setPlayerPos()
{

	/**
	* Ponemos los players en las posiciones de spawn
	*
	*/

	for (int i = 0; i < jokalariKopurua; i++)
	{
		jokalaria[i].x = arrayNivelak[nivela].spawnPoint[i].x;
		jokalaria[i].y = arrayNivelak[nivela].spawnPoint[i].y;
		hitbox[i].x = jokalaria[i].x;
		hitbox[i].y = jokalaria[i].y;
	}
}

int ebentuenDetekzioa() {
	/**
   * Esta funcion comprueba todos los inputs
   *
   */

	SDL_Event event;
	if (transEgoera == -1) {
		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				close_requested = 99;
				break;
			case SDL_CONTROLLERBUTTONDOWN:
				for (int i = 0; i < actualMandos; i++) {
					mandos[i].Adown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_A);
					mandos[i].Xdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_X);
					mandos[i].Bdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_B);
					mandos[i].Ydown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_Y);
					mandos[i].UPdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_UP);
					mandos[i].DOWNdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
					mandos[i].RIGHTdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
					mandos[i].LEFTdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
				}
			case SDL_CONTROLLERBUTTONUP:
				for (int i = 0; i < actualMandos; i++) {
					mandos[i].Adown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_A);
					mandos[i].Xdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_X);
					mandos[i].Ydown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_Y);
					mandos[i].UPdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_UP);
					mandos[i].Bdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_B);
					mandos[i].DOWNdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
					mandos[i].RIGHTdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
					mandos[i].LEFTdown = SDL_GameControllerGetButton(pad[i], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
				}
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
					teklatua.Wdown = 1;
					break;
				case SDL_SCANCODE_UP:
					teklatua.UPdown = 1;
					break;
				case SDL_SCANCODE_A:
					teklatua.Adown = 1;
					break;
				case SDL_SCANCODE_LEFT:
					teklatua.LEFTdown = 1;
					break;
				case SDL_SCANCODE_S:
					teklatua.Sdown = 1;
					break;
				case SDL_SCANCODE_DOWN:
					teklatua.DOWNdown = 1;
					break;
				case SDL_SCANCODE_D:
					teklatua.Ddown = 1;
					break;
				case SDL_SCANCODE_RIGHT:
					teklatua.RIGHTdown = 1;
					break;
				case SDL_SCANCODE_LSHIFT:
					teklatua.SHIFTdown = 1;
					break;
				case SDL_SCANCODE_PERIOD:
					teklatua.PUNTOdown = 1;
					break;
				case SDL_SCANCODE_SPACE:
					teklatua.SPACEdown = 1;
					break;
				case SDL_SCANCODE_COMMA:
					teklatua.COMAdown = 1;
					break;
				case SDL_SCANCODE_R:
					teklatua.Rdown = 1;
					break;
				case SDL_SCANCODE_Q:
					if (easterCoolDown[0] == 0) {
						Mix_PlayChannel(-1, miauSound, 0);
						easterCoolDown[0] = 15;
					}
				case SDL_SCANCODE_M:
					if (easterCoolDown[1] == 0) {
						Mix_PlayChannel(-1, miauSound, 0);
						easterCoolDown[1] = 15;
					}
					break;
				case SDL_SCANCODE_ESCAPE:
					close_requested = 99;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
					teklatua.Wdown = 0;
					break;
				case SDL_SCANCODE_UP:
					teklatua.UPdown = 0;
					break;
				case SDL_SCANCODE_A:
					teklatua.Adown = 0;
					break;
				case SDL_SCANCODE_LEFT:
					teklatua.LEFTdown = 0;
					break;
				case SDL_SCANCODE_S:
					teklatua.Sdown = 0;
					break;
				case SDL_SCANCODE_DOWN:
					teklatua.DOWNdown = 0;
					break;
				case SDL_SCANCODE_D:
					teklatua.Ddown = 0;
					break;
				case SDL_SCANCODE_RIGHT:
					teklatua.RIGHTdown = 0;
					break;
				case SDL_SCANCODE_LSHIFT:
					teklatua.SHIFTdown = 0;
					break;
				case SDL_SCANCODE_PERIOD:
					teklatua.PUNTOdown = 0;
					break;
				case SDL_SCANCODE_SPACE:
					teklatua.SPACEdown = 0;
					break;
				case SDL_SCANCODE_COMMA:
					teklatua.COMAdown = 0;
					break;
				case SDL_SCANCODE_R:
					teklatua.Rdown = 0;
					break;
				case SDL_SCANCODE_ESCAPE:
					close_requested = 0;
					break;
				}
				break;
			}

		}
	}
	if (easterCoolDown[0] > 0) easterCoolDown[0] -= 1;
	
	if (easterCoolDown[1] > 0) easterCoolDown[1] -= 1;

	return close_requested;
}

void ponerArma() {
	/**
   * Ponemos el arma en la pos del jugador pero solo lo pintamos si el jugador tiene municion
   *
   */
	for (int i = 0; i < jokalariKopurua; i++)
	{
		if (jokalaria[i].orient == 1 && jokalaria[i].munizioa == 1)
		{
			armas[i].x = jokalaria[i].x + 10;
			armas[i].y = jokalaria[i].y;
			hitboxArma[i].x = armas[i].x;
			hitboxArma[i].y = armas[i].y;
		}
		else if (jokalaria[i].orient == 0 && jokalaria[i].munizioa == 1)
		{
			armas[i].x = jokalaria[i].x - (PLAYERW * 2);
			armas[i].y = jokalaria[i].y;
			hitboxArma[i].x = armas[i].x;
			hitboxArma[i].y = armas[i].y;
		}
		if (jokalaria[i].orient == 1 && jokalaria[i].munizioa == 3)
		{
			armas[i].x = jokalaria[i].x + 10;
			armas[i].y = jokalaria[i].y;
			hitboxArma[i].x = armas[i].x;
			hitboxArma[i].y = armas[i].y;
		}
		else if (jokalaria[i].orient == 0 && jokalaria[i].munizioa == 3)
		{
			armas[i].x = jokalaria[i].x - (PLAYERW * 2);
			armas[i].y = jokalaria[i].y;
			hitboxArma[i].x = armas[i].x;
			hitboxArma[i].y = armas[i].y;
		}
	}
}

void pintarArmas() {
	/**
	* Pintar las armas si el jugador etsa vivo y segun su orientacion
	*
	*/

	for (int i = 0; i < jokalariKopurua; i++)
	{
		if (jokalaria[i].arma == 1 && jokalaria[i].orient == 1 && jokalaria[i].munizioa == 1 && jokalaria[i].egoera == 1)
		{
			SDL_RenderCopy(rend, armaSprite, NULL, &hitboxArma[i]);
		}
		if (jokalaria[i].arma == 1 && jokalaria[i].orient == 0 && jokalaria[i].munizioa == 1 && jokalaria[i].egoera == 1)
		{
			SDL_RenderCopy(rend, armaSpriteIzq, NULL, &hitboxArma[i]);
		}
		if (jokalaria[i].arma == 1 && jokalaria[i].orient == 1 && jokalaria[i].munizioa == 3 && jokalaria[i].egoera == 1)
		{
			SDL_RenderCopy(rend, armaRifleSprite, NULL, &hitboxArma[i]);
		}
		if (jokalaria[i].arma == 1 && jokalaria[i].orient == 0 && jokalaria[i].munizioa == 3 && jokalaria[i].egoera == 1)
		{
			SDL_RenderCopy(rend, armaRifleSpriteIzq, NULL, &hitboxArma[i]);
		}
	}
}

void resetPlayers()
{
	/**
	* Reseteamos a los players
	*
	*/
	for (int i = 0; i < jokalariKopurua; i++)
	{
		jokalaria[i].arma = 0;
		jokalaria[i].egoera = 1;
		hitbox[i].w = 40;
		hitbox[i].h = 60;
	}
}

int randomMap()
{
	/**
   * EN esta funcion sacamos un mapa random y lo guardamos en un array para que no se repita hastyq eue todos los mapas hayan sido usados
   *
   */
	static int mapasTocados[10];
	int numProvisional = 0, estadentro = 0, aurkituta = 0, todosUsados = 1, i = 0;

	if (RMinit) {
		for (int i = 0; i < 10; i++) mapasTocados[i] = 0;
		RMinit = 0;
	}

	while (i < 10 && todosUsados == 1)
	{
		if (mapasTocados[i] == 0)
		{
			todosUsados = 0;
		}
		i++;
	}

	if (todosUsados == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			mapasTocados[i] = 0;
		}
		todosUsados = 0;
	}

	while (aurkituta == 0)
	{
		numProvisional = (rand() % 10);

		if (mapasTocados[numProvisional] == 1)
		{
			estadentro = 1;
			randSeed++;
		}
		else estadentro = 0;

		if (estadentro == 0)
		{
			nivela = numProvisional;
			aurkituta = 1;
			mapasTocados[nivela] = 1;
		}
	}

	return(nivela);
}

void resetGame() {
	/**
	* En esta funcion reseteamos el juego para que cada vez que entres a jugar otra vez este todo desde 0
	*
	*/

	//Iniciamos los niveles
	initNivelak();

	// Si seleccion de mandos es 0 (escogiendo el teclado) le damos 2 a jokalari kopurua
	if (seleccionDeMandos == 0) jokalariKopurua = 2;

	//Reset actualMandos
	actualMandos = 0;

	// Init mandos
	for (int i = 0; i < numeroDeMandos; ++i) {
		if (SDL_IsGameController(i)) {
			pad[i] = SDL_GameControllerOpen(i);
			if (!pad) {
				fprintf(stderr, "Could not open gamecontroller %i: %s\n", i, SDL_GetError());
			}
			//else printf("Konetat %d ", i);
			actualMandos++;
		}
	}

	//Reiniciamos las variables
	seleccionprincipal = vuelta = randSeed = nivela = disparoact = randSeed = transEgoera = victoria = inizializauta = 0;
	seleccionDeMandos = -1;
	teklatua.Adown = teklatua.Sdown = teklatua.Wdown = teklatua.Ddown = teklatua.UPdown = teklatua.DOWNdown = teklatua.LEFTdown = teklatua.RIGHTdown = teklatua.COMAdown = teklatua.PUNTOdown = teklatua.SHIFTdown = teklatua.SPACEdown = teklatua.Rdown = 0;

	//Reiniciamos los disparos
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

	// Reiniciamos los jugadores
	for (int i = 0; i < jokalariKopurua; i++)
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
	}
	setPlayerPos();
	initSpawners(arrayNivelak[nivela].kajaKop);
	srand(randSeed);
	RMinit = 1;
}

void resetDisparos() {
	/**
	* Resetear los disparos
	*
	*/
	for (int i = 0; i < 20; i++) {
		disparo[i].direc = 1;
		disparo[i].speed = 30;
		disparo[i].disparado = 0;
		disparo[i].x = 1380;
		disparo[i].y = -50;
	}
}

void blinkAnimacio(jok jokalaria, int jokZenb, int timer) {
	/**
	* Hacer la animacion del blink
	*
	*/
	if (blinkPhase[jokZenb] == -1) {
		if (jokalaria.orient) blinkHB[jokZenb * 2].x = jokalaria.x - (blinkHB[0].w / 2) - DASH;
		else blinkHB[jokZenb * 2].x = jokalaria.x - (blinkHB[0].w / 2) + DASH;
		blinkHB[jokZenb * 2].y = jokalaria.y - (blinkHB[0].h / 2);
		blinkPhase[jokZenb] = 1;
		Mix_PlayChannel(-1, blinkSound, 0);
	}




	blinkHB[jokZenb * 2 + 1].x = jokalaria.x - (blinkHB[0].w / 2);
	blinkHB[jokZenb * 2 + 1].y = jokalaria.y - (blinkHB[0].h / 2);


	if (blinkPhase[jokZenb] != 0 && blinkPhase[jokZenb] < 3 && timer % 10 == 0) {
		blinkPhase[jokZenb] = blinkPhase[jokZenb] + 1;
	}

	if (blinkPhase[jokZenb] != 0 && blinkPhase[jokZenb] > 3 && timer % 10 == 0) {
		blinkPhase[jokZenb] = 0;
	}

	if (blinkPhase[jokZenb] != 0 && blinkPhase[jokZenb] < 4) {
		SDL_RenderCopy(rend, blink[blinkPhase[jokZenb]], NULL, &blinkHB[jokZenb * 2]);
		SDL_RenderCopy(rend, blink[blinkPhase[jokZenb]], NULL, &blinkHB[jokZenb * 2 + 1]);
	}

}

void transizioZenbakiak() {
	/**
	* Hacer la transicion
	*
	*/
	if (transEgoera >= 0 && transEgoera < 4) {
		if (transEgoera < 3) {
			SDL_RenderCopy(rend, transNumbers[transEgoera], NULL, &transNumbersHB[0]);
			if (transSound) {
				Mix_PlayChannel(-1, transDingSound[0], 0);
				transSound = 0;
				transCoolDown = 20;
			}
		}
		else {
			SDL_RenderCopy(rend, transNumbers[transEgoera], NULL, &transNumbersHB[1]);
			if (transSound) {
				Mix_PlayChannel(-1, transDingSound[1], 0);
				transSound = 0;
				transCoolDown = 20;
			}
		}
		if (transCoolDown == 0) {
			transEgoera++;
			transSound = 1;
		}
		else transCoolDown--;
	}
	else transEgoera = -1;
}

void resetTeklauaEtaMandua() {
	/**
   * EN esta funcion reseteamos el teclado y el mando
   *
   */
	teklatua.Adown = 0;
	teklatua.Sdown = 0;
	teklatua.Wdown = 0;
	teklatua.Ddown = 0;
	teklatua.UPdown = 0;
	teklatua.LEFTdown = 0;
	teklatua.DOWNdown = 0;
	teklatua.RIGHTdown = 0;
	teklatua.SHIFTdown = 0;
	teklatua.SPACEdown = 0;
	teklatua.COMAdown = 0;
	teklatua.PUNTOdown = 0;

	for (int i = 0; i < jokalariKopurua; i++) {
		mandos[i].AxisX = 0;
		mandos[i].Adown = 0;
		mandos[i].Xdown = 0;
		mandos[i].RIGHTdown = 0;
		mandos[i].LEFTdown = 0;
		mandos[i].UPdown = 0;
		mandos[i].DOWNdown = 0;
		x_vel[i] = 0;
		x_vel[i] = 0;
	}
}

void hilAnimazioa() {
	/**
   * EN esta funcion reproducimos la animacion de apagarse
   *
   */
	for (int i = 0; i < jokalariKopurua; i++) {
		if (jokalaria[i].egoera == -1 && hilCoolDown[i] == 0) {
			hilCoolDown[i] = 40;
			jokalaria[i].egoera = -2;
			Mix_PlayChannel(-1, fizzSound, 0);
		}
		if (jokalaria[i].egoera == -2) {
			if (hitbox[i].w > 0) {
				hitbox[i].w = hitbox[i].w - 2;
				hitbox[i].h = hitbox[i].h - 3;
				hitbox[i].x += 1;
				hitbox[i].y += 3;
				keiaHB[i].x = jokalaria[i].x - keiaHB[i].w / 2;
				keiaHB[i].y = jokalaria[i].y - keiaHB[i].h / 2 - hitbox[i].h / 2;
			}
			if (hilCoolDown[i] <= 40 && hilCoolDown[i] > 30) {

				SDL_RenderCopy(rend, keia[0], NULL, &keiaHB[i]);
			}
			else if (hilCoolDown[i] <= 30 && hilCoolDown[i] > 20) {
				SDL_RenderCopy(rend, keia[1], NULL, &keiaHB[i]);
			}
			else if (hilCoolDown[i] <= 20 && hilCoolDown[i] > 10) {
				SDL_RenderCopy(rend, keia[2], NULL, &keiaHB[i]);
			}
			else if (hilCoolDown[i] <= 10 && hilCoolDown[i] > 0) {
				SDL_RenderCopy(rend, keia[3], NULL, &keiaHB[i]);
			}
		}
		if (jokalaria[i].egoera == -2 && hilCoolDown[i] == 0) {
			jokalaria[i].egoera = 0;
			jokalaria[i].munizioa = 0;
			jokalaria[i].y = 1000;
		}
		if (hilCoolDown[i] > 0) hilCoolDown[i] -= 1;
	}
}

void hasierakoAnim() {
	/**
	* Con esto reproducimos el fade del principio
	*
	*/
	SDL_SetTextureBlendMode(menuGauss, SDL_BLENDMODE_BLEND);
	while (alphaGauss > 0) {
		while (alphaBeltz > 5) {
			SDL_RenderCopy(rend, menuEnfoq, NULL, NULL);
			SDL_SetTextureAlphaMod(menuGauss, alphaGauss);
			SDL_RenderCopy(rend, menuGauss, NULL, NULL);
			SDL_SetRenderDrawColor(rend, 0, 0, 0, alphaBeltz);
			SDL_RenderFillRect(rend, NULL);
			alphaBeltz -= 2;
			alphaGauss -= 2;
			SDL_RenderPresent(rend);
		}
		SDL_RenderCopy(rend, menuEnfoq, NULL, NULL);
		SDL_SetTextureAlphaMod(menuGauss, alphaGauss);
		SDL_RenderCopy(rend, menuGauss, NULL, NULL);
		alphaGauss -= 2;
		SDL_RenderPresent(rend);
	}
	SDL_RenderCopy(rend, menuEnfoq, NULL, NULL);
	SDL_RenderPresent(rend);
}

void destroyAll() {

	/**
	* En esta funcion destruimos todo lo que se ha creado en el juego
	*
	*/
	SDL_DestroyTexture(spr[0][0]);
	SDL_DestroyTexture(spr[0][1]);
	SDL_DestroyTexture(spr[1][0]);
	SDL_DestroyTexture(spr[1][1]);
	SDL_DestroyTexture(spr[2][0]);
	SDL_DestroyTexture(spr[2][1]);
	SDL_DestroyTexture(spr[3][0]);
	SDL_DestroyTexture(spr[3][1]);
	SDL_DestroyTexture(background[0][0]);
	SDL_DestroyTexture(background[0][1]);
	SDL_DestroyTexture(background[1][0]);
	SDL_DestroyTexture(background[1][1]);
	SDL_DestroyTexture(background[2][0]);
	SDL_DestroyTexture(background[2][1]);
	SDL_DestroyTexture(background[3][0]);
	SDL_DestroyTexture(background[3][1]);
	SDL_DestroyTexture(background[4][0]);
	SDL_DestroyTexture(background[4][1]);
	SDL_DestroyTexture(background[5][0]);
	SDL_DestroyTexture(background[5][1]);
	SDL_DestroyTexture(background[6][0]);
	SDL_DestroyTexture(background[6][1]);
	SDL_DestroyTexture(background[7][0]);
	SDL_DestroyTexture(background[7][1]);
	SDL_DestroyTexture(background[8][0]);
	SDL_DestroyTexture(background[8][1]);
	SDL_DestroyTexture(background[9][0]);
	SDL_DestroyTexture(background[9][1]);
	SDL_DestroyTexture(background[10][0]);
	SDL_DestroyTexture(background[10][1]);
	SDL_DestroyTexture(meteoro[0]);
	SDL_DestroyTexture(meteoro[1]);
	SDL_DestroyTexture(meteoro[2]);
	SDL_DestroyTexture(meteoro[3]);
	SDL_DestroyTexture(numeros[0]);
	SDL_DestroyTexture(numeros[1]);
	SDL_DestroyTexture(numeros[2]);
	SDL_DestroyTexture(numeros[3]);
	SDL_DestroyTexture(numeros[4]);
	SDL_DestroyTexture(numeros[5]);
	SDL_DestroyTexture(numeros[6]);
	SDL_DestroyTexture(numeros[7]);
	SDL_DestroyTexture(numeros[8]);
	SDL_DestroyTexture(numeros[9]);
	SDL_DestroyTexture(puntuPantaila[0]);
	SDL_DestroyTexture(puntuPantaila[1]);
	SDL_DestroyTexture(puntuPantaila[2]);
	SDL_DestroyTexture(blink[0]);
	SDL_DestroyTexture(blink[1]);
	SDL_DestroyTexture(blink[2]);
	SDL_DestroyTexture(transNumbers[0]);
	SDL_DestroyTexture(transNumbers[1]);
	SDL_DestroyTexture(transNumbers[2]);
	SDL_DestroyTexture(transNumbers[3]);
	SDL_DestroyTexture(keia[0]);
	SDL_DestroyTexture(keia[1]);
	SDL_DestroyTexture(keia[2]);
	SDL_DestroyTexture(keia[3]);
	SDL_DestroyTexture(zutabe);
	SDL_DestroyTexture(bala);
	SDL_DestroyTexture(armaSprite);
	SDL_DestroyTexture(armaRifleSpriteIzq);
	SDL_DestroyTexture(spawnPistola);
	SDL_DestroyTexture(puntuazioa);
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(texBotoncontrols);
	SDL_DestroyTexture(armaRifleSprite);
	SDL_DestroyTexture(armaRifleSpriteIzq);
	SDL_DestroyTexture(menuGauss);
	SDL_DestroyTexture(menuEnfoq);
	SDL_DestroyTexture(texBotonstart);
	SDL_DestroyTexture(texBotonteclado);
	SDL_DestroyTexture(texBotonplay);
	SDL_DestroyTexture(texBotonCuatroJugadores);
	SDL_DestroyTexture(texBotonTresJugadores);
	SDL_DestroyTexture(texBotonDosJugadores);
	SDL_DestroyTexture(texMenuControls);
	SDL_DestroyTexture(spawnPistolaBurst);
	Mix_FreeChunk(blinkSound);
	Mix_FreeChunk(pistolaSound);
	Mix_FreeChunk(jumpSound);
	Mix_FreeChunk(rifleSound);
	Mix_FreeChunk(fizzSound);
	Mix_FreeChunk(transDingSound[0]);
	Mix_FreeChunk(transDingSound[1]);
	Mix_FreeMusic(menuMusic);
	Mix_FreeMusic(inGameMusic);
	Mix_HaltMusic();
	Mix_Quit();
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(ventana);
	SDL_Quit();
}

void DrawText(SDL_Surface* textSurface, TTF_Font* font, SDL_Color foregroundColor, SDL_Rect textLocation, int xpos, int ypos, int anchura, int altura)
{
	/**
	* Una funcion que printea texto en la pantalla
	* Parametrosw --> textSurface: SUperficie del texto, message: una textura en la que va a estar el mensaje, foregrounCOlor: un color rgb, TExtlocation: el rect en el que va a etsar,xpos,ypos: las posiciones x e y
	* anchura, altura: la anchura y la altura (Genious)
	*/
	textLocation.x = xpos;
	textLocation.y = ypos;
	textLocation.w = anchura;
	textLocation.h = altura;

	SDL_Texture* Message;

	textSurface = TTF_RenderText_Blended(font, creditText, foregroundColor);
	Message = SDL_CreateTextureFromSurface(rend, textSurface);

	SDL_RenderCopy(rend, Message, NULL, &textLocation);
	SDL_RenderPresent(rend);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(Message);
}

void calcularEjeJoystick() {
	/**
	* Calculamos la posicion de los joysticks y le damos el valor al player para que se pueda mover
	*
	*/
	//SI no estamso en el 3,2,1 go
	if (transEgoera == -1) {
		//miramos todos los mandos
		for (int i = 0; i < actualMandos; i++)
		{
			//Si esta mas adelante que 0 y la deadzone seactiva
			if (SDL_GameControllerGetAxis(pad[i], 0) >= DEADZONE)
			{
				mandos[i].AxisX = 1;
			}
			// Si esta mas atras que 0 y la deadzone seactiva
			else if (SDL_GameControllerGetAxis(pad[i], 0) < -DEADZONE)
			{
				mandos[i].AxisX = -1;
			}
			//Si no 0
			else mandos[i].AxisX = 0;
		}
	}
}

void creditos() {

	/**
	* EN esta funcion se llama a DrawText para crear el texto del principio
	*
	*/

	int tiempoDeEspera = 1000, letraHeight = 90;
	int fbr, fbb, fbg, bgr, bgb, bgg;
	int x, y, w, h;
	fbr = fbb = fbg = 255;
	bgr = bgb = bgg = 0;
	SDL_Event event;
	SDL_Surface* textSurface = NULL;
	SDL_Texture* Message = NULL, *waterBucket;
	SDL_Color foregroundColor = { fbr, fbb, fbg };
	SDL_Color bgColor = { bgr, bgb, bgg, 1 };
	SDL_Rect textLocation, spriteLocation[2], waterBucketHB;

	surface = IMG_Load("resources/images/miscellaneous/cuboDeAgua.png");
	waterBucket = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface;

	waterBucketHB.x = 540;
	waterBucketHB.y = 300;
	waterBucketHB.w = 225;
	waterBucketHB.h = 225;


	textLocation.x = 0;
	textLocation.y = 0;
	textLocation.w = 0;
	textLocation.h = 0;

	x = 680;
	y = 384;

	spriteLocation[0].w = 175;
	spriteLocation[0].h = 275;
	spriteLocation[0].x = 100;
	spriteLocation[0].y = 250;
	spriteLocation[1].w = 175;
	spriteLocation[1].h = 275;
	spriteLocation[1].x = 1100;
	spriteLocation[1].y = 250;


	static int timer, skipRequested;

	//empezamos con la musica
	Mix_PlayMusic(creditosMusic, -1);

	//Mientras no le des al esc vamos printeando texto en el momento exacto para que vaya cuadraado con la musica
	if (initCreditos) {
		timer = 0, skipRequested = 0;
	}
	while (!skipRequested && timer < 3000) {
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_ESCAPE:
					skipRequested = 1;
					break;

				}
				break;
			}
		}
		if (timer == 1) {
			SDL_RenderClear(rend);
			strcpy(creditText, "Long time ago...");
			w = 500;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 250) {
			SDL_RenderClear(rend);
			strcpy(creditText, "The whole world was a giant sphere of fire");
			w = 1200;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 500) {
			SDL_RenderClear(rend);
			strcpy(creditText, "After lots of centuries it became the planet we all know");
			w = 1300;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 650) {
			SDL_RenderClear(rend);
			strcpy(creditText, "But something was different.");
			w = 800;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 850) {
			SDL_RenderClear(rend);
			strcpy(creditText, "Due to the fire a new species was born...");
			w = 1000;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 1030) {
			SDL_RenderClear(rend);
			strcpy(creditText, "The Flames");
			w = 500;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 1205) {

			SDL_RenderCopy(rend, spr[0][1], NULL, &spriteLocation[0]);
			SDL_RenderPresent(rend);
		}
		else if (timer == 1270) {
			SDL_RenderCopy(rend, spr[1][1], NULL, &spriteLocation[1]);
			SDL_RenderPresent(rend);
		}
		else if (timer == 1500) {
			SDL_RenderClear(rend);
			strcpy(creditText, "They thought about making a competition");
			w = 1300;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "to see who was the strongest");
			w = 900;
			h = letraHeight;
			y = 384 + h;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			//Reset y
			y = 384;
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 1750) {
			SDL_RenderClear(rend);
			strcpy(creditText, "the winner would rule all of them");
			w = 900;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 2000) {
			SDL_RenderClear(rend);
			strcpy(creditText, "Only the strongest flame would become the king of the world");
			w = 1300;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y - (h / 2), w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
		}
		else if (timer == 2250) {
			SDL_RenderClear(rend);
			strcpy(creditText, "WaterDrop Studios presents....");
			w = 800;
			h = letraHeight;
			DrawText(textSurface, font, foregroundColor, textLocation, x - (w / 2), y + 200, w, h);
			strcpy(creditText, "Press ESC to skip intro...");
			DrawText(textSurface, font, foregroundColor, textLocation, 0, 0, 250, 30);
			SDL_RenderCopy(rend, waterBucket, NULL, &waterBucketHB);
			SDL_RenderPresent(rend);
		}
		timer++;
		SDL_Delay(15);
	}

	TTF_CloseFont(font);
	TTF_Quit();
	Mix_HaltMusic();
}

void ranking()
{
	int posicionesVictoria[4][2];
	int tmp, aurkituta = 0, i = 0, j = 1;

	int ranking[4];
	for (int i = 0; i < 4; i++) ranking[i] = 0; // Para quitar un warning

	/********************************************************
	*														*
	*	Un for para asignar los puntos de cada jokalari		*
	*	al la array de ranking.								*
	*														*
	*********************************************************/
	for (int r = 0; r < jokalariKopurua; r++)
	{
		ranking[r] = jokalaria[r].puntuak;
	}

	//Ganador
	posicionesVictoria[0][0] = 707;
	posicionesVictoria[0][1] = 540;
	//Segundo
	posicionesVictoria[1][0] = 586;
	posicionesVictoria[1][1] = 568;
	//Tercero
	posicionesVictoria[2][0] = 833;
	posicionesVictoria[2][1] = 600;
	//Cuarto
	posicionesVictoria[3][0] = 369;
	posicionesVictoria[3][1] = 1;


	/********************************************************
	*														*
	*	Ordena el array de ranking de mayor a menor.		*
	*														*
	*********************************************************/
	while (i < 4)
	{
		while (j < 4)
		{
			if (ranking[i] < ranking[j])
			{
				tmp = ranking[j];
				ranking[j] = ranking[i];
				ranking[i] = tmp;
				j++;
			}
			else
			{
				j++;
			}
		}
		i++;
		j = i + 1;
	}


	/********************************************************
	*														*
	*	Asignar posicion del podio a los jugadores segun	*
	*	el ranking.											*
	*														*
	*********************************************************/
	for (int n = 0; n < jokalariKopurua; n++)
	{
		if (jokalaria[n].puntuak == ranking[0])
		{
			jokalaria[n].x = posicionesVictoria[0][0];
			jokalaria[n].y = posicionesVictoria[0][1];
			hitbox[n].x = jokalaria[n].x;
			hitbox[n].y = jokalaria[n].y;
		}
		else if (jokalaria[n].puntuak == ranking[1])
		{
			jokalaria[n].x = posicionesVictoria[1][0];
			jokalaria[n].y = posicionesVictoria[1][1];
			hitbox[n].x = jokalaria[n].x;
			hitbox[n].y = jokalaria[n].y;
		}
		else if (jokalaria[n].puntuak == ranking[2])
		{
			jokalaria[n].x = posicionesVictoria[2][0];
			jokalaria[n].y = posicionesVictoria[2][1];
			hitbox[n].x = jokalaria[n].x;
			hitbox[n].y = jokalaria[n].y;
		}
		else if (jokalaria[n].puntuak == ranking[3])
		{
			jokalaria[n].x = posicionesVictoria[3][0];
			jokalaria[n].y = posicionesVictoria[3][1];
			hitbox[n].x = jokalaria[n].x;
			hitbox[n].y = jokalaria[n].y;
		}
	}
}