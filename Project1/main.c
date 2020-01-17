#include "deklarazioak.h"
#include "struct.h"

int main(int argc, char* argv[])
{
	/************************************************
	*												*
	*	Se llama a la funcion de inicializar todo.	*
	*												*
	*************************************************/
	init();

	/****************************************************************
	*																*
	*	Se llama a la funcion que genera los creditos iniciales.	*
	*																*
	*****************************************************************/
	creditos();

	/****************************************************************
	*																*
	*	El bucle principal del juego. Mientras no se pida salir		*
	*	(close_requested = 99) el juego continuara funcionando.		*
	*																*
	*****************************************************************/
	while (close_requested != 99) {
		
		/********************************************************
		*														*
		*	 Se llama a la animacion inicial del juego.			*
		*														*
		*********************************************************/
		hasierakoAnim();

		/****************************************************************
		*																*
		*	Se llama a la funcion del menu, si este devuelve 0 se		*
		*	procede a cerrar la aplicacion.								*	
		*																*
		*****************************************************************/
		if (!menu()) return 0;

		/********************************************************************
		*																	*
		*	 Se llama al bucle principal del juego, y si esta				*
		*	devuelve un 1, saldra hacia el menu, y si devuelve 99, saldra	*
		*	de la aplicacion.												*
		*																	*
		*********************************************************************/
		while (close_requested != 1 && close_requested != 99) close_requested = gameLoop();
		
		/****************************************************************
		*																*
		*	Se llama a la funcion que resetea el juego para que			*
		*	pueda volver a ser utilizado.								*
		*																*
		*****************************************************************/
		resetGame();
	}

	/************************************************************
	*															*
	*	Se llama a la funcion que cierra todas las texturas		*
	*	o musicas abiertas, y cierra el SDL.						*
	*															*
	*************************************************************/
	destroyAll();
	return 0;
}