#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define ANCHO 80
#define ALTO 30

#define _USE_MATH_DEFINES

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	float pelotaX = rand() % (ANCHO - 10) + 2;
	float pelotaY = 2;
	float pelotaAngulo = 7 * M_PI / 4; // 315 grados en radianes.
	float pelotaVelocidad;
	
	int largoPaleta = 10;
	int paletaX = ANCHO / 2 - largoPaleta / 2;
	
	int vidas = 3;
	
	char key;
	int start = time(NULL);
	int ac = 0;
	for(int i = 0; i < 1000000000; i++){
	}
	pelotaVelocidad = 0.03 * (time(NULL) - start); //Define velocidad de acuerdo al prosesador
	clrscr();
	while(key != 's' && vidas > 0){
		// Calcular trayectoria de la pelota.
		pelotaY -= sin(pelotaAngulo) * pelotaVelocidad;
		pelotaX += cos(pelotaAngulo) * pelotaVelocidad;
		
		// Calcular el rebote de la pelota
		if(pelotaX > ANCHO - 1){ //Choca pared derecha
			pelotaX = ANCHO - 1;
			if(pelotaAngulo > M_PI * 3/4){
				pelotaAngulo -= M_PI/2;
			} else {
				pelotaAngulo += M_PI/2;
			}
		}
		
		if(pelotaX < 1){ //Choca pared izquierda
			pelotaX = 1;
			if(pelotaAngulo > M_PI){
				pelotaAngulo += M_PI/2;
			} else {
				pelotaAngulo -= M_PI/2;
			}
		}
		
		if(ceil(pelotaY) == ALTO - 3 && ceil(pelotaX) >= paletaX && ceil(pelotaX) <= (paletaX + largoPaleta)){ //Choca paleta
			pelotaY = ALTO - 4;
			if(pelotaAngulo > M_PI * 3/2){
				pelotaAngulo -= M_PI * 3/2;
			} else {
				pelotaAngulo -= M_PI/2;
			}
		}
		
		if(ceil(pelotaY) > ALTO - 1){ //Choca piso
			vidas--;
			pelotaX = rand() % (ANCHO - 10) + 2;
			pelotaY = 2;
		}
		
		if(pelotaY < 1){ // Choca techo
			pelotaY = 1;
			if(pelotaAngulo > M_PI/2){
				pelotaAngulo += M_PI/2;
			} else {
				pelotaAngulo += M_PI * 3/2;
			}
		}
		
		// Dibujar el fondo
		for(int i = 0; i < ANCHO; i++){
			for(int j = 0; j < ALTO; j++){
				gotoxy(i, j);
				if(i == ceil(pelotaX) && j == ceil(pelotaY)){
					textcolor(BLUE);
					cout << "o"; // Dibuja la pelota
				} else {
					if(i == 1 || i == ANCHO - 1 || j == 1 || j == ALTO - 1){
						if(j == ALTO - 1){
							textcolor(RED);
						} else {
							textcolor(GREEN);
						}
						cout << "*"; // Dibuja las paredes
					} else {
						if(j == ALTO - 3 && i > paletaX && i <= (paletaX + largoPaleta)){
							textcolor(YELLOW);
							cout << "=";
						} else {
							cout << " "; // Borra caracteres viejos
						}
					}
				}
			}
		}
		
		gotoxy(0, ALTO + 4);
		cout << "Vidas: " << vidas;

		usleep(2000);
		if(kbhit()){
			key = getch();
			switch(key) {
			case 67: //derecha
				if((paletaX + largoPaleta) < ANCHO - 2){
					paletaX++;
				}
				break;
			case 68: //izquierda
				if(paletaX > 2){
					paletaX--;
				}
				break;
			}
		}
		
		gotoxy(0, ALTO + 8);
	}
	
	if(vidas <= 0){
		clrscr();
		cout << "#########    #########    #########    #####       #########    #########    #########    #########" << endl;
		cout << "#       #    #            #       #    #    #          #        #                #        #        " << endl;
		cout << "#       #    #            #       #    #     #         #        #                #        #        " << endl;
		cout << "#########    #########    #########    #      #        #        #########        #        #########" << endl;
		cout << "#            #            # #          #     #         #                #        #        #        " << endl;
		cout << "#            #            #   #        #    #          #                #        #        #        " << endl;
		cout << "#            #########    #     #      #####       #########    #########        #        #########" << endl;
		getch();
	}

	return 0;
}
