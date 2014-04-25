#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
#define G 9.8 //aceleracion de la gravedad 9,8 m/s
#define PI 3.14162

int main(int argc, char *argv[]) {
	float a; //variable que contendra el angulo del disparo
	float d; //variable que contendra la distancia
	float V0=60; //velocidad inicial 60 m/s
	int x;

	srand(time(NULL)); //se obtiene una distancia al azar
	x=rand()%201+100;
	
	cout<<"Intenta dar en el Blanco"<<endl<<"Para ello tienes cinco balas"<<endl;
	cout<<"Te indicare que tan lejos del blanco has hecho impacto"<<endl;
	cout<<"El blanco se encuentra a "<<x<<" metros"<<endl<<endl;
	
	cout<<"introduce el angulo de disparo 1: ";
	cin>>a;
	d=pow(V0,2)*sin(2*a*PI/180)/G; //calculo de la distancia
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<"\nLa bala cayo a " << d <<" metros.\n";
	
	cout<<"introduce el angulo de disparo 2: ";
	cin>>a;
	d=pow(V0,2)*sin(2*a*PI/180)/G; //calculo de la distancia
	cout<<"\nLa bala cayo a "<<d<<" metros.\n";
	
	cout<<"introduce el angulo de disparo 3: ";
	cin>>a;
	d=pow(V0,2)*sin(2*a*PI/180)/G - x; //calculo de la distancia
	cout<<"\nLa bala cayo a "<<d<<" metros del blanco.\n";
	
	cout<<"introduce el angulo de disparo 4: ";
	cin>>a;
	cout<<"introduce la velocidad del disparo 4: ";
	cin>>V0;
	d=pow(V0,2)*sin(2*a*PI/180)/G; //calculo de la distancia
	cout<<"\nLa bala cayo a "<<d<<" metros.\n";
	
	srand(time(NULL)); //se obtiene una distancia al azar
	x=rand()%501+1000;
	cout<<"El blanco se movi� a "<<x<<" metros"<<endl<<endl;
	
	cout<<"introduce el angulo de disparo 5: ";
	cin>>a;
	cout<<"introduce la velocidad del disparo 5: ";
	cin>>V0;
	d=pow(V0,2)*sin(2*a*PI/180)/G; //calculo de la distancia
	cout<<"\nLa bala cayo a "<<d<<" metros.\n";
	system("PAUSE"); //espera la pulsaci\ufffdn de una tecla
	
	return 0;
}
