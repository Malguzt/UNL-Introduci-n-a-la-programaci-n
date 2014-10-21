#include "Ganadores.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ncurses.h>

using namespace std;

Ganadores::Ganadores() {
	ifstream archivo("ganadores", ios::binary);
	char temp[100];
	
	if(archivo.good()){
		for (int i = 0; i < 5; ++i){
			archivo.getline(ganadores[i], 21, ';');
			archivo.getline(temp, 100, '#');
			puntos[i] = atoi(temp);
		}
	} else {
		for (int i = 0; i < 5; ++i){
			strcpy(ganadores[i], "Nadie              ");
			puntos[i] = 0;
		}
	}
	
	archivo.close();
}

Ganadores::~Ganadores() {
	guardar();
}

bool Ganadores::haceMerito(int nuevosPuntos)
{
	return nuevosPuntos > puntos[4];
}

void Ganadores::agregarGanador(int nuevosPuntos, char nombre[20])
{
	for (int i = 4; i >= 0; i--)
	{
		if(puntos[i] < nuevosPuntos)
		{
			if(i < 4)
			{
				puntos[i + 1] = puntos[i];
				strcpy(ganadores[i + 1], ganadores[i]);
			}
			
			puntos[i] = nuevosPuntos;
			strcpy(ganadores[i], nombre);
		}
	}
}

void Ganadores::dibujar()
{
	printw("Puesto  Nombre                 Puntos\n");
	for(int i = 0; i < 5; i++)
	{
		printw("%5d | %20s | %10d\n", (i + 1), ganadores[i], puntos[i]);
	}
	
	refresh();
}

void Ganadores::guardar()
{
	ofstream archivo("ganadores", ios::binary);
	char temp[2];
	
	for (int i = 0; i < 5; ++i){
		archivo << ganadores[i] << ";" << puntos[i] << "#";
	}
	
	archivo.close();
}
