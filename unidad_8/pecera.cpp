#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define CANTIDAD_PECES 5
#define _USE_MATH_DEFINES

class Pez {
protected:
  int color;
  float velocidad;
  int tamano;
private:
  float x;
  float y;
  float direccion;
public:
  Pez();
  int getX();
  int getY();
  void actualizar(int ancho, int alto);
  void dibujar();
};

class PezGrande: public Pez{
public:
  void girar();
  void dibujar();
  PezGrande();
};

class PezChico: public Pez{
public:
  void cambiarColor();
};

class Cuadro {
private: 
  int ancho;
  int alto;
  int color;
  PezGrande pecesGrandes[CANTIDAD_PECES];
  PezChico pecesChicos[CANTIDAD_PECES];
public:
  Cuadro();
  void dibujar();
  void actualizar();
  void girar();
  void cambiarColor();
};

int main(int argc, char const *argv[]){
  srand(time(NULL));
  char key;
  
  Cuadro elCuadro;

  while(true){
    elCuadro.actualizar();
    elCuadro.dibujar();
    usleep(200000);

    if(kbhit()){
      key = getch();
      switch(key) {
      case '1': //derecha
        elCuadro.girar();
        break;
      case '2': //izquierda
        elCuadro.cambiarColor();
        break;
      }
    }
  }

  return 0;
}

Cuadro::Cuadro(){
  ancho = 80;
  alto = 30;
}

void Cuadro::dibujar(){
  clrscr();
  textcolor(GREEN);

  string tablero;
  
  for(int j = 1; j < alto; j++){
    for(int i = 1; i < ancho; i++){
      if(i == 1 || i == ancho - 1 || j == 1 || j == alto - 1){
        tablero += '*'; // Dibuja las paredes
      } else {
        tablero += ' '; // Borra caracteres viejos
      }
    }
    tablero += '\n';
  }
  cout << tablero;

  gotoxy(1, 1);

  for(int i = 0; i < CANTIDAD_PECES; i++){
    pecesGrandes[i].dibujar();
    pecesChicos[i].dibujar();
  }
}

void Cuadro::actualizar(){
  for(int i = 0; i < CANTIDAD_PECES; i++){
    pecesGrandes[i].actualizar(ancho, alto);
    pecesChicos[i].actualizar(ancho, alto);
  }
}

void Cuadro::girar(){
  for(int i = 0; i < CANTIDAD_PECES; i++){
    pecesGrandes[i].girar();
  }
}

void Cuadro::cambiarColor(){
  for(int i = 0; i < CANTIDAD_PECES; i++){
    pecesChicos[i].cambiarColor();
  }
}

Pez::Pez(){
  x = 5;
  y = 5;
  velocidad = rand() % 10 + 1;
  color = rand() % 10 + 1;
  tamano = 8;
}

int Pez::getY(){
  return ceil(y);
}

int Pez::getX(){
  return ceil(x);
}

void Pez::dibujar(){
  gotoxy(getX(), getY());
  textcolor(color);
  if(velocidad > 0){
    cout << "><((((º>" << endl;
  } else {
    cout << "<º))))><" << endl;
  }
}

void Pez::actualizar(int ancho, int alto){
  velocidad += rand() % 3 - 1;
  // Calcular trayectoria de la Pez.
  y += rand() % 3 - 1;
  x += velocidad;
  
  // Calcular el rebote de la Pez
  if(getX() > ancho - tamano){ 
    x = ancho - tamano;
    velocidad = -velocidad;
  }

  if(getX() < 1){
    x = 1;
    velocidad = -velocidad;
  }

  if(getY() > alto - tamano / 5){ 
    y = alto - tamano / 4;
  }

  if(y < 1){ 
    y = 1;
  }
}

PezGrande::PezGrande(){
  tamano = 23;
}

void PezGrande::dibujar(){
  textcolor(color);
  gotoxy(getX(), getY());
  if(velocidad > 0){
    cout << "           .----.";
    gotoxy(getX(), getY() + 1);
    cout << " ____    __\\\\\\\\\\\\__";
    gotoxy(getX(), getY() + 2);
    cout << " \\___'--'          .-.";
    gotoxy(getX(), getY() + 3);
    cout << " /___<             '0'";
    gotoxy(getX(), getY() + 4);
    cout << "/____,--.       y     B";
    gotoxy(getX(), getY() + 5);
    cout << "        ''.____  ___-'";
    gotoxy(getX(), getY() + 6);
    cout << "        //    / /";
    gotoxy(getX(), getY() + 7);
    cout << "              ]/";
  } else {
    cout << "        ,----,";
    gotoxy(getX(), getY() + 1);
    cout << "    ___//////__    ____";
    gotoxy(getX(), getY() + 2);
    cout << " .-.           '--'___/";
    gotoxy(getX(), getY() + 3);
    cout << " '0'              >___\\";
    gotoxy(getX(), getY() + 4);
    cout << "8     q        ,--.____\\";
    gotoxy(getX(), getY() + 5);
    cout << " '-___  ____,''";
    gotoxy(getX(), getY() + 6);
    cout << "      \\ \\   \\\\     ";
    gotoxy(getX(), getY() + 7);
    cout << "       \\['";
   } 
}

void PezGrande::girar(){
  velocidad = -velocidad;
}

void PezChico::cambiarColor(){
  color = rand() % 19 + 1;
}