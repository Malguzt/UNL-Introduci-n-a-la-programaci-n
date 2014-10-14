#include "Nivel.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Nivel::Nivel(): Nivel(20, 20) {
}

Nivel::Nivel(int al, int an) {
    srand(time(NULL));
    alto = al;
    ancho = an;
    fichas = new Ficha**[alto];
    for(int i = 0; i < alto; i++){
        fichas[i] = new Ficha*[ancho];
        for(int j = 0; j < ancho; j++){
            fichas[i][j] = nuevaFicha(j + 1, i + 1); //j es el ancho, por eso esta en x
        }
    }
}

Nivel::Nivel(const Nivel& orig) {
    ancho = orig.ancho;
    alto = orig.alto;
}

Nivel::~Nivel() {
    delete[] fichas[ancho];
}

void Nivel::dibujar() {
    system("clear");
    for(int i = 0; i < alto; i++){
        for(int j = 0; j < ancho; j++){
            fichas[i][j]->dibujar();
        }
        cout << endl;
    }
}

Ficha* Nivel::nuevaFicha(int x, int y)
{
    int tipoDeFicha = rand() % 6;
    switch (tipoDeFicha)
    {
        case 0:
            return new FichaA(x, y);
            break;
        case 1:
            return new FichaB(x, y);
            break;
        case 2:
            return new FichaC(x, y);
            break;
        case 3:
            return new FichaD(x, y);
            break;
        case 4:
            return new FichaE(x, y);
            break;
        case 5:
            return new FichaF(x, y);
            break;
        default:
            return new Ficha(x, y);
            break;
    }
}

bool Nivel::controlar()
{
    bool sinLineas = true;
    for(int i = 0; i < alto; i++)
    {
        for(int j = 0; j < ancho; j++)
        {
            Ficha *a, *b, *c;
            if(j < (ancho - 2))
            {
                a = fichas[i][j];
                b = fichas[i][j + 1];
                c = fichas[i][j + 2];
                if(*a == *b && *a == *c)
                {
                    a->setEnLinea(true);
                    b->setEnLinea(true);
                    c->setEnLinea(true);

                    sinLineas = false;
                }
            }

            if(i < (alto - 2)){
                a = fichas[i][j];
                b = fichas[i + 1][j];
                c = fichas[i + 2][j];
                if(*a == *b && *a == *c)
                {
                    a->setEnLinea(true);
                    b->setEnLinea(true);
                    c->setEnLinea(true);

                    sinLineas = false;
                }
            }
        }
    }

    return sinLineas;
}

void Nivel::borrarAlineadas()
{
    for(int i = 0; i < alto; i++)
    {
        for(int j = 0; j < ancho; j++)
        {
            if(fichas[i][j]->estaAlineada())
            {
                delete fichas[i][j];
                fichas[i][j] = new FichaBorrada(j + 1, i + 1);
            }
        }
    }
}

bool Nivel::rellenar()
{
    bool completo = true;
    for(int i = alto - 1; i >= 0; i--)
    {
        for(int j = 0; j < ancho; j++)
        {
            if(fichas[i][j]->estaBorrada())
            {
                bajarColumna(i, j);
                completo = false;
            }
        }
        dibujar();
    }

    return completo;
}

void Nivel::bajarColumna(int fila, int columna)
{
    delete fichas[fila][columna];
    for(int i = fila; i > 0; i--)
    {
        fichas[i][columna] = fichas[i - 1][columna];
        fichas[i][columna]->setX(columna + 1);
        fichas[i][columna]->setY(i + 1);
    }

    fichas[0][columna] = nuevaFicha(columna + 1, 1);
}
