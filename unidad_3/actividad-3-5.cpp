#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	srand(time(NULL));
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
		cout << "\n¿Quieres lanzar otra vez?";
		cin >> respuesta;
	}
	
	return 0;
}

