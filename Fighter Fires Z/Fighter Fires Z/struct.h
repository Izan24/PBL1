#ifndef STRUCT_H
#define STRUCT_H

typedef struct jokalaria {
	int x;
	int y;
	int puntuak;
	int egoera;
	int arma;
	int munizioa;
	int blink;
	int anim;
	int orient;
	int kontagarri;
} jok;

typedef struct manduak {
	int Adown;
	int Xdown;
	int UPdown;
	int DOWNdown;
	int RIGHTdown;
	int LEFTdown;
	int AxisX;


	int Bdown;
	int Ydown;
} mand;

typedef struct teklaua {
	int Wdown;
	int Sdown;
	int Adown;
	int Ddown;
	int SHIFTdown;
	int SPACEdown;

	int Rdown;

	int UPdown;
	int DOWNdown;
	int LEFTdown;
	int RIGHTdown;
	int COMAdown;
	int PUNTOdown;
} teklau;

typedef struct cuadrado {
	int x0;
	int y0;
	int x;
	int y;
	int ondoan;
} cuadrado;

typedef struct kajak {
	int x;
	int y;
	int typoArma;
	int armaDisponible;
	int CD;
	int anim;
	int estado;
} kaja;

typedef struct spawnPlayers {
	int x;
	int y;
}spawnPlayer;

typedef struct nivela {
	int id;
	int karratuKop;
	int kajaKop;
	cuadrado arrayKarratu[35];
	kaja arrayKajak[20];
	spawnPlayer spawnPoint[4];
}niv;

typedef struct bullet {
	int x;
	int y;
	int speed;
	//0 izquierda 1 derecha
	int direc;
	int disparado;
}bullet;

typedef struct posizioaSagua {
	int y;
	int x;
}saguPos;

typedef struct arma
{
	int x;
	int y;
}arma;

#endif // !STRUCT_H