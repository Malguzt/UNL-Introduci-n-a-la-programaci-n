#include <iostream>
#include <cstdlib>

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

int main(int argc, char *argv[]) {
	carta nuevaCarta;
	
	for (int i = 1; i < 53; ++i)
	{
		nuevaCarta = obtenerCarta(i);
  	cout << nuevaCarta.numero[0] << nuevaCarta.numero[1] << " de " << nuevaCarta.palo << '\n';
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