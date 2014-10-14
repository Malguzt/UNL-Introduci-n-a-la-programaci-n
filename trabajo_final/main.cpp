#include <iostream>
#include "Nivel.h"
#include <unistd.h>

using namespace std;

int main()
{
    Nivel elNivel(10, 15);
    elNivel.dibujar();
    usleep(300000);
    while(!elNivel.controlar())
    {
        elNivel.dibujar();
        usleep(300000);
        elNivel.borrarAlineadas();
        elNivel.dibujar();
        usleep(300000);
        while(!elNivel.rellenar())
        {
            usleep(800000);
        }
    }

    return 0;
}
