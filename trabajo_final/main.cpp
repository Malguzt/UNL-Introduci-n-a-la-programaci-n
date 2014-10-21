#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include "Nivel.h"
#include "Ganadores.h"

#define VELOCIDAD 500000

using namespace std;

int main()
{
    Nivel elNivel(10, 15);
    elNivel.dibujar();
    usleep(VELOCIDAD);
    int tecla;
    while(tecla != 'q' && !elNivel.termino())
    {
        while(!elNivel.controlar())
        {
            elNivel.borrarAlineadas();
            elNivel.dibujar();
            usleep(VELOCIDAD);
            while(!elNivel.rellenar())
            {
				elNivel.dibujar();
                usleep(VELOCIDAD);
            }
        }
		elNivel.dibujar();
		
		tecla = getch();
		switch(tecla){
		case 10:
			elNivel.intercambiar();
			break;
		case 68:
			elNivel.moverIzquierda();
			break;
		case 67:
			elNivel.moverDerecha();
			break;
		case 65:
			elNivel.moverArriba();
			break;
		case 66:
			elNivel.moverAbajo();
			break;
		}
    }
	
	elNivel.dibujar();
	
	Ganadores lista;
	if(lista.haceMerito(elNivel.getPuntos()))
	{
		char nombre[20];
		printw("Ingresa tu nombre\n");
		refresh();
		getstr(nombre);
		lista.agregarGanador(elNivel.getPuntos(), nombre);
	}
	
	lista.dibujar();

    return 0;
}
