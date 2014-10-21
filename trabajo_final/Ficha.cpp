#include "Ficha.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

Ficha::Ficha():Ficha(1, 1)
{
}

Ficha::Ficha(int xx, int yy)
{
    x = xx;
    y = yy;

    dibujo[0][0] = '+'; dibujo[0][1] = '-'; dibujo[0][2] = '+';
    dibujo[1][0] = '|'; dibujo[1][1] = 'X'; dibujo[1][2] = '|';
    dibujo[2][0] = '+'; dibujo[2][1] = '-'; dibujo[2][2] = '+';

    color = COLOR_RED;

    enLinea = false;

    seleccionada = false;
}

Ficha::Ficha(const Ficha& orig)
{
    x = orig.x;
    y = orig.y;
}

Ficha::~Ficha()
{
}

Ficha* Ficha::setY(int yy)
{
    y = yy;

    return this;
}

Ficha* Ficha::setX(int xx)
{
    x = xx;

    return this;
}

Ficha* Ficha::setEnLinea(const bool valor)
{
    enLinea |= valor;

    return this;
}

void Ficha::dibujar()
{
	start_color();
    for(int i = 0; i < 3; i++)
    {
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        if(enLinea)
        {
			attrset(COLOR_PAIR(COLOR_WHITE));
        } else {
			init_pair(color, color, COLOR_BLACK);
			attrset(COLOR_PAIR(color));
        }
        move((y-1) * 4 + i, (x-1) * 4);

        if(seleccionada && (i == 2 || i == 0))
        {
			attrset(COLOR_PAIR(COLOR_WHITE));
        }
		addch(dibujo[i][0]);
		addch(dibujo[i][1]);
		addch(dibujo[i][2]);
    }
}

bool Ficha::controlar(Ficha* anterior, Ficha* siguiente)
{
    return false;
}

bool Ficha::operator==(const Ficha& otro)
{
    return dibujo[1][1] == otro.dibujo[1][1];
}

bool Ficha::estaBorrada()
{
    return false;
}

bool Ficha::estaAlineada()
{
    return enLinea;
}

Ficha* Ficha::deseleccionar()
{
    seleccionada = false;

    return this;
}

Ficha* Ficha::seleccionar()
{
    seleccionada = true;

    return this;
}

int Ficha::getY()
{
    return y;
}

int Ficha::getX()
{
    return x;
}

