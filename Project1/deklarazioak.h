#ifndef DEKLARAZIOAK_H
#define DEKLARAZIOAK_H

#include <stdio.h>
#include "struct.h"
#include "include/SDL.h"
#include "include/SDL_image.h"
#include "include/SDL_timer.h"
#include "include/SDL_gamecontroller.h"
#include "include/SDL_joystick.h"
#include <string.h>
#include <stdlib.h>
#include "include/SDL_ttf.h"
#include "include/SDL_mixer.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                   CONST                                                                              */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define WINDOW_HEIGHT (768) 
#define WINDOW_WIDTH (1360)
#define SPEED (300)
#define PLAYERW (20)
#define PLAYERH (30)
#define GRAVEDAD (40)
#define DASH (100)
#define SPAWNERH (30)
#define DISPAROW (20)
#define DISPAROH (20)
#define SPAWNERH (30)
#define DEADZONE (10000)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                VARIABLIAK                                                                            */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mix_Music* menuMusic, * inGameMusic, *creditosMusic, *victoriaMusic;
Mix_Chunk* blinkSound, *pistolaSound, *rifleSound, *fizzSound, *jumpSound, *transDingSound[2], *miauSound;
TTF_Font* font;

niv arrayNivelak[11];
SDL_Window* ventana;
SDL_Renderer* rend;
SDL_Surface* surface;
SDL_AudioDeviceID deviceId;
SDL_Rect meteoroHB[4], zutabeHB[3], posNum[10], hitboxBala[20], hitboxArma[4], hitboxSpawn[20], hitbox[4], blinkHB[8], Fondo, BotonExit, Botoncontrols, Botonstart, Botonplay, Botonteclado, transNumbersHB[2], keiaHB[4];
SDL_GameController* pad[4];
SDL_Texture* spr[4][4], * background[11][2], * meteoro[4], * numeros[10], * puntuPantaila[3], * blink[4], *transNumbers[4], *keia[4];
SDL_Texture* zutabe, * bala, * armaSprite, * armaSpriteIzq, * spawnPistola, * puntuazioa, * tex, * texBotonExit, * texBotoncontrols, *armaRifleSprite, *armaRifleSpriteIzq, * menuGauss, *menuEnfoq;
SDL_Texture* texBotonstart, * texBotonteclado, * texBotonplay, * texBotonCuatroJugadores, * texBotonTresJugadores, * texBotonDosJugadores, * texMenuControls, * spawnPistolaBurst;
Uint8* wavBuffer;
jok jokalaria[4];
teklau teklatua;
arma armas[4];
mand mandos[4];
bullet disparo[20];
SDL_AudioSpec wavSpec;
Uint32 wavLength;
saguPos sagua;
int seleccionprincipal, inizializauta, seleccionDeMandos, vuelta, randSeed, numeroDeMandos, nivela, actualMandos, jokalariKopurua, disparoact, close_requested, distX[4], distY[4], saltoaEgin[4], RMinit, blinkPhase[4];
int transEgoera, transSound, transCoolDown, hilCoolDown[4], alphaBeltz, alphaGauss, initCreditos, easterCoolDown[4], victoria;
float x_vel[4], y_vel[4];
char creditText[125];
 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                FUNTZIOAK                                                                             */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


extern void initNivelak();
extern int init();
extern int menu();
extern int gameLoop();

extern int talkabertical(cuadrado linea, jok jokalaria);
extern int talkahorizontal(cuadrado linea, jok jokalaria);
extern void initMeteoro();
extern void initBackgroundTextures();
extern void initSpriteTexturak();
extern int spriteAnimation(jok jokalari, SDL_Rect hitboxa, int jokalariZenb, int timer);
extern void rendBackground(int nivelZenb, int timer);
extern void meteoroAnimation(int timer);
extern void initZutabe();
extern void zutabeAnimation();
extern void initNumeros();
extern void initPuntuPantaila();
extern int MenuPrincipal();
extern int MenuController();
extern int CuantosJugadores();
extern int MenuDeComoJugar();
extern void balaMovimiento();
extern void rendNumeros(int puntuak, int x, int y);
extern void rendPuntuPantaila();
extern void spriteMovimiento();
extern void aplicarMugimenduTeklado();
extern void acabarConElDisparo();
extern int transicio(int kont);
extern int resetKontagarri(int kont);
extern void disparar(int i);
extern void calcularOrientacio(teklau* teklatua, jok jokalaria[]);
extern void colisionBalaJugador();
extern int talkatxen();
extern void chocarSpawner(int spawnerkopurua);
extern void comprobarAccionesMando();
extern void initSpawners(int kajakop);
extern void setPlayerPos();
extern void colisionBalaMapa(int karratuKop);
extern void ponerArma();
extern void pintarArmas();
extern int ebentuenDetekzioa();
extern int randomMap();
extern void resetPlayers();
extern void resetGame();
extern int randomMap();
extern void resetPlayers();
extern void resetDisparos();
extern void initBlink();
extern void blinkAnimacio(jok jokalaria, int jokZenb, int timer);
extern void initTransNumbers();
extern void transizioZenbakiak();
extern void resetTeklauaEtaMandua();
extern void hilAnimazioa();
extern void initKeia();
extern void hasierakoAnim();
extern void destroyAll();
extern void DrawText(SDL_Surface* textSurface, TTF_Font* font, SDL_Color foregroundColor, SDL_Rect textLocation, int xpos, int ypos, int anchura, int altura);
extern int creditos();
extern void calcularEjeJoystick();
extern void initMusika();
extern void ranking();

#endif // !DEKLARAZIOAK_H