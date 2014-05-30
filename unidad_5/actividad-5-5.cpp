#include <iostream>
#include <cstdio>
using namespace std;

int contar(char *cadena);
char* concatenar(char *cadena1, char *cadena2);
int buscar(char aguja, char* pajar);
void cambiar(char* cadena, char caracter, int posicion);

int main(int argc, char *argv[]) {
	char cadena[2][500];
	char caracter;
	int posicion;
	for(int i = 0; i < 2; i++){
		cout << "Escribe algo\n";
		cin.getline(cadena[i], 500);
		cout << "La cadena tiene una longitud de: " << contar(cadena[i]) << endl;
	}
	
	char* cadenaFinal = concatenar(cadena[0], cadena[1]);
	
	cout << endl << cadenaFinal << endl;
	
	cout << "¿Que caracter quiere buscar?" << endl;
	caracter = getchar();
	
	posicion = buscar(caracter, cadenaFinal);
	if(-1 < posicion){
		cout << "El caracter buscado aparece por primera vez en la posición: " << posicion << endl;
		
		cout << "¿Con que caracter lo quiere remplazar?\n";
		cin >> caracter;
		
		cambiar(cadenaFinal, caracter, posicion);
		cout << endl << cadenaFinal << endl;
	} else {
		cout << "No se encuentra el caracter buscado en la cadena." << endl;
	}
	
	return 0;
}

int contar(char *cadena){
	int i = 0;
	while (0 != cadena[i++]){
	}
	
	return i - 1;
}

char* concatenar(char *cadena1, char *cadena2){
	int longitud1 = contar(cadena1);
	int longitud2 = contar(cadena2);
	int longitudTotal = longitud1 + longitud2;
	
	char* cadenaFinal = new char[longitudTotal];
	
	int i = 0;
	while (0 != cadena1[i] && 0 != cadena2[i]) {
		cadenaFinal[i] = cadena1[i];
		cadenaFinal[i + longitud1] = cadena2[i];
		
		i++;
	}
	
	while (0 != cadena1[i]) {
		cadenaFinal[i] = cadena1[i];
		
		i++;
	}
	
	while (0 != cadena2[i]) {
		cadenaFinal[i + longitud1] = cadena2[i];
		
		i++;
	}
	
	return cadenaFinal;
}

int buscar(char aguja, char* pajar){
	int i = 0;
	int longitud = contar(pajar);
	while (aguja != pajar[i] && i < longitud) {
		i++;
	}
	
	if(i == longitud){
		i = -1;
	}
	
	return i;
}

void cambiar(char* cadena, char caracter, int posicion){
	cadena[posicion] = caracter;
}
