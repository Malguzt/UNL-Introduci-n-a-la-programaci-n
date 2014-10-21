#ifndef FICHA_H
#define FICHA_H

class Ficha
{
public:
    Ficha();
    Ficha(int xx, int yy);
    Ficha(const Ficha& orig);
    Ficha* setX(int xx);
    Ficha* setY(int yy);
    Ficha* setEnLinea(const bool valor);
    virtual ~Ficha();
    void dibujar();
    bool controlar(Ficha* anterior, Ficha* siguiente);
    bool operator==(const Ficha& otro);
    virtual bool estaBorrada();
    bool estaAlineada();
    Ficha* seleccionar();
    Ficha* deseleccionar();
    int getX();
    int getY();
protected:
    char dibujo[3][3];
    int color;
private:
    int x;
    int y;
    bool enLinea;
    bool seleccionada;
};

#endif // FICHA_H
