#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio2.h>

const char corazon[] = "\xe2\x99\xa5";
const char diamante[] = "\xe2\x99\xa6";
const char pica[] = "\xe2\x99\xa4";
const char trebol[] = "\xe2\x99\xa7";

const char letras[3] = {'J', 'Q', 'K'};

using namespace std;

typedef struct {
	char numero[2];
	char palo[4];
} carta;

carta obtenerCarta(int numero);
void ordenar(int *numeros);
void nuevoMazo(int mazo[]);
void dibujarMano(int mano[], int y);
void dibujarCarta(carta laCarta, int x, int y);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	carta nuevaCarta;
	int siguienteCarta = 0;
	int manoJugador[5], manoComputadora[5];

	int mazo[52];
	nuevoMazo(mazo);
	
	for (int i = 0; i < 6; ++i){
		manoJugador[i] = mazo[siguienteCarta++];
		manoComputadora[i] = mazo[siguienteCarta++];
	}

	clrscr();

	ordenar(manoJugador);
	dibujarMano(manoJugador, 0);
	int i = 0;
	int cambio;
	int cambios[4];
	do {
    cout << "\nIngrese una pocición valida para cambiar o 0 para terminar.\n";
    cin >> cambio;
    	
  	if(cambio > 0 && cambio < 6){
  		cambios[i++] = cambio;
    }
	} while(i < 5 && cambio > 0);

	ordenar(cambios);

	bool cambiar;
	for(int i = 0; i < 4; i++){
		cambiar = true;
		if(cambios[i] <= 0 || (i > 0 && cambios[i] == cambios[i - 1])){
			cambiar = false;
		}

		if(cambiar){
			manoJugador[cambios[i] - 1] = mazo[siguienteCarta++];
		}
	}

	dibujarMano(manoJugador, 10);
	// dibujarMano(manoComputadora, 10);
}

void dibujarMano(int mano[], int y){
	for(int i = 0; i < 6; i++){
		dibujarCarta(obtenerCarta(mano[i]), i * 13, y);
		gotoxy(i * 13 + 5, y + 8);
		cout << i + 1;
	}
}

void dibujarCarta(carta laCarta, int x, int y){
	gotoxy(x, y++);
	cout << "**********" << endl;
	gotoxy(x, y++);
	cout << "*" << laCarta.numero[0] << laCarta.numero[1] << "      *\n";
	gotoxy(x, y++);
	cout << "*" << laCarta.palo << "       *" << endl;
	gotoxy(x, y++);
	cout << "*        *" << endl;
	gotoxy(x, y++);
	cout << "*        *" << endl;
	gotoxy(x, y++);
	cout << "*       " << laCarta.palo << "*" << endl;
	gotoxy(x, y++);
	cout << "*      " << laCarta.numero[0] << laCarta.numero[1] << "*\n";
	gotoxy(x, y++);
	cout << "**********" << endl;
}

void nuevoMazo(int mazo[]){
	int index;
	for (int i = 0; i < 53; ++i)
	{
		mazo[i] = 0;
	}

	for (int i = 1; i < 53; ++i){
		index = rand() % 52 + 1;
		while(mazo[index] != 0) {
		    index++;
		    if(index > 52){
		    	index = 0;
		    }
		}

		mazo[index] = i;
	}
}

carta obtenerCarta(int numero){
	carta laCarta;
	int elNumero;

	if(numero < 14){
		elNumero = numero;
		laCarta.palo[0] = corazon[0];
		laCarta.palo[1] = corazon[1];
		laCarta.palo[2] = corazon[2];
		laCarta.palo[3] = corazon[3];
	} else {
		if (numero < 27) {
			elNumero = numero - 13;
			laCarta.palo[0] = diamante[0];
			laCarta.palo[1] = diamante[1];
			laCarta.palo[2] = diamante[2];
			laCarta.palo[3] = diamante[3];
		} else {
			if(numero < 40){
				elNumero = numero - 26;
				laCarta.palo[0] = pica[0];
				laCarta.palo[1] = pica[1];
				laCarta.palo[2] = pica[2];
				laCarta.palo[3] = pica[3];
			} else {
				if (numero < 53){
					elNumero = numero - 39;
					laCarta.palo[0] = trebol[0];
					laCarta.palo[1] = trebol[1];
					laCarta.palo[2] = trebol[2];
					laCarta.palo[3] = trebol[3];
				}
			}
		}
	}

	laCarta.numero[0] = ' ';
	if(elNumero == 1){
		laCarta.numero[1] = 'A';
	} else {
		if(elNumero == 10){
			laCarta.numero[0] = '1';
			laCarta.numero[1] = '0';
		} else {
			if(elNumero < 10) {
				laCarta.numero[1] = elNumero + 48;
			} else {
				laCarta.numero[1] = letras[elNumero - 11];
			}
		}
	}

	return laCarta;
}

void ordenar(int *numeros){
	int aux;
	bool ordenado = false;
	
	while (!ordenado){
		ordenado = true;
		
		for(int i = 0; i < 5; i++){
			if(numeros[i] > numeros[i + 1]){
				ordenado = false;
				
				aux = numeros[i];
				numeros[i] = numeros[i + 1];
				numeros[i + 1] = aux;
			}
		}
	}
}