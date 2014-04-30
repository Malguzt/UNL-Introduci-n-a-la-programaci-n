#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int lanzarDados(int tipo, int cantidad, int base){
	srand(time(NULL));
	int resultado = 0;
	
	for(int i = 0; i < cantidad; i++){
		resultado += rand() % tipo + 1;
	}
	
	return resultado + base;
}

int main(int argc, char *argv[]) {
	
	char respuesta = 'S';
	
	while (respuesta == 's' || respuesta == 'S'){

		int dado1 = rand()%6+1;
		int dado2 = rand()%6+1;
		
		cout << "Los resultados fueron: " << dado1 << " y " << dado2 << endl;
		if(dado1 == dado2){
			cout << "Ambos dados dieron el mismo resultado" << endl;
		} else {
			cout << "Ambos dados son diferentes\n";
		}
		
		cout << "En total ambos dados suman: " << dado1 + dado2 << endl;
		cout << "\n¿Quieres lanzar otra vez?\n";
		cin >> respuesta;
	}
	
	return 0;
}

