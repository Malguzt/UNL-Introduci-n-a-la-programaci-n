#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
#define G 9.8 //aceleracion de la gravedad 9,8 m/s
#define PI 3.14162

void disparar(int numeroDisparo, int blanco){
	float angulo;
	float distancia;
	float velocidad;
	
	cout << "\nIntroduce el angulo de disparo " << numeroDisparo << ": ";
	cin >> angulo;
	cout << "Introduce la velocidad del disparo " << numeroDisparo << ": ";
	cin >> velocidad;
	distancia = pow(velocidad, 2) * sin(2 * angulo * PI/180)/G; //calculo de la distancia
	
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<"\nLa bala cayo a " << distancia <<" metros.\n";
	cout<<"La bala cayo a " << distancia - blanco <<" metros del blanco.\n";
}

int main(int argc, char *argv[]) {
	int x;

	srand(time(NULL)); //se obtiene una distancia al azar
	x=rand()%201+100;
	
	cout<<"Intenta dar en el Blanco"<<endl<<"Para ello tienes cinco balas"<<endl;
	cout<<"Te indicare que tan lejos del blanco has hecho impacto"<<endl;
	cout<<"El blanco se encuentra a "<<x<<" metros"<<endl<<endl;
	
	disparar(1, x);
	disparar(2, x);
	disparar(3, x);
	disparar(4, x);
	disparar(5, x);
	
	system("PAUSE"); //espera la pulsaci\ufffdn de una tecla
	
	return 0;
}
