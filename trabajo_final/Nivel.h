#include "Ficha.h"
#include "FichaA.h"
#include "FichaB.h"
#include "FichaC.h"
#include "FichaD.h"
#include "FichaE.h"
#include "FichaF.h"
#include "FichaBorrada.h"
#include <list>
#ifndef NIVEL_H
#define NIVEL_H

class Nivel
{
public:
    Nivel();
    Nivel(int alto, int ancho);
    Nivel(const Nivel& orig);
    virtual ~Nivel();
    void dibujar();
    bool controlar();
    void borrarAlineadas();
    bool rellenar();
private:
    Ficha ***fichas;
    int ancho;
    int alto;
    Ficha* nuevaFicha(int x, int y);
    void bajarColumna(int fila, int columna);
};

#endif // NIVEL_H
