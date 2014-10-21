#include "Ficha.h"
#include "FichaA.h"
#include "FichaB.h"
#include "FichaC.h"
#include "FichaD.h"
#include "FichaE.h"
#include "FichaF.h"
#include "FichaBorrada.h"
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
    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
    void moverArriba();
	void intercambiar();
	bool termino();
	int getPuntos();
private:
	Ficha* seleccionada;
    Ficha ***fichas;
    int ancho;
    int alto;
	int vidas;
	int puntos;
    Ficha* nuevaFicha(int x, int y);
    void bajarColumna(int fila, int columna);
	bool intercambiada;
};

#endif // NIVEL_H
