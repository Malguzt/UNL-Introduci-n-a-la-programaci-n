#include "Nivel.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

Nivel::Nivel(): Nivel(20, 20) {
}

Nivel::Nivel(int al, int an) {
    alto = al;
    ancho = an;
    fichas = new Ficha**[alto];
    int tipoDeFicha;
    for(int i = 0; i < alto; i++){
        fichas[i] = new Ficha*[ancho];
        for(int j = 0; j < ancho; j++){
            tipoDeFicha = rand() % 6;
            switch (tipoDeFicha)
            {
                case 0:
                    fichas[i][j] = new FichaA(j + 1, i + 1);
                    break;
                case 1:
                    fichas[i][j] = new FichaB(j + 1, i + 1);
                    break;
                case 2:
                    fichas[i][j] = new FichaC(j + 1, i + 1);
                    break;
                case 3:
                    fichas[i][j] = new FichaD(j + 1, i + 1);
                    break;
                case 4:
                    fichas[i][j] = new FichaE(j + 1, i + 1);
                    break;
                case 5:
                    fichas[i][j] = new FichaF(j + 1, i + 1);
                    break;
                default:
                    fichas[i][j] = new Ficha(j + 1, i + 1);
                    break;
            }
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
    for(int i = 0; i < alto; i++){
        for(int j = 0; j < ancho; j++){
            fichas[i][j]->dibujar();
        }
        cout << endl;
    }
}
