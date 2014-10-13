#include "Ficha.h"
#include "FichaA.h"
#include "FichaB.h"
#include "FichaC.h"
#include "FichaD.h"
#include "FichaE.h"
#include "FichaF.h"
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
private:
    Ficha ***fichas;
    int ancho;
    int alto;
};

#endif // NIVEL_H
