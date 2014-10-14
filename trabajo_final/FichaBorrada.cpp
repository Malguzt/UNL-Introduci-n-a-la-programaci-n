#include "FichaBorrada.h"

FichaBorrada::FichaBorrada(int xx, int yy): Ficha(xx, yy)
{
    dibujo[1][1] = ' ';
    color = 7;
}

bool FichaBorrada::estaBorrada()
{
    return true;
}
