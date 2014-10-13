#include "Ficha.h"
#include <iostream>
#include <conio2.h>

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

    color = RED;
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

void Ficha::dibujar()
{
    for(int i = 0; i < 3; i++)
    {
        textcolor(color);
        gotoxy(x * 4, y * 4 + i);
        cout << dibujo[i][0] << dibujo[i][1] << dibujo[i][2] ;
    }
}

