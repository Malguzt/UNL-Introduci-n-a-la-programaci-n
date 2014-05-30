#include <iostream>
#include <conio2.h>

using namespace std;

void dibujar(char tablero[3][3]);
int controlar(char tablero[3][3]);

int main(int argc, char *argv[]) {
	int x, y, jugador = 1;
	char tablero[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	bool termino = false;
	while(!termino) {
		dibujar(tablero);
		do{
			gotoxy(0, 11);
			cout << "                            \n                                     ";
			
			gotoxy(0, 10);
			cout << "Introducir cordenadas para jugador " << jugador << endl;
			cin >> x >> y;
		} while(x < 1 || x > 3 || y < 1 || y >3 || tablero[x - 1][y - 1] != ' ');
		
		if(1 == jugador){
			tablero[x - 1][y - 1] = 'X';
			jugador = 2;
		} else {
			tablero[x - 1][y - 1] = 'O';
			jugador = 1;
		}
		
		if(controlar(tablero)){
			dibujar(tablero);
			cout << "\nPartida terminada.\n                                                        ";
			termino = true;
		}
	}
	
	return 0;
}

void dibujar(char tablero[3][3]){
	for(int i = 1; i < 4; i++){
		for(int j = 1; j < 4; j++){
			gotoxy(i * 2, j * 2 - 1);
			cout << "---";
			gotoxy(i * 2, j * 2);
			cout << "|" << tablero[i - 1][j - 1] << "| " << j;
			gotoxy(i * 2, j * 2 + 1);
			cout << "---";
		}
	}
	
	
	gotoxy(3, 8);
	cout << "1 2 3";
}

int controlar(char tablero[3][3]){
	bool gano = false;
	for(int i = 0; i < 3; i++){
		gano |= tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][1] != ' ';
		gano |= tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[1][i] != ' ';
	}
	
	if(!gano && tablero[1][1] != ' '){
		gano |= tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2];
		gano |= tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2];
	}
	
	return gano;
}
