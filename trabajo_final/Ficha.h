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
    virtual ~Ficha();
    void dibujar();
protected:
    char dibujo[3][3];
    int color;
private:
    int x;
    int y;
};

#endif // FICHA_H
