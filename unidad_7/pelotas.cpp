#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define CANTIDAD_PELOTAS 20
#define _USE_MATH_DEFINES

class Pelota {
private:
  float x;
  float y;
  float angulo;
  float velocidad;
  float color;
public:
  Pelota();
  int getX();
  int getY();
  void rebotar(float anguloPared);
  void actualizar(int ancho, int alto);
  void dibujar();
};

class Cuadro {
private: 
  int ancho;
  int alto;
  int color;
  Pelota pelotas[CANTIDAD_PELOTAS];
public:
  Cuadro();
  void dibujar();
  void actualizar();
};

int main(int argc, char const *argv[]){
  srand(time(NULL));
  
  Cuadro elCuadro;

  while(true){
    elCuadro.actualizar();
    elCuadro.dibujar();
    usleep(200000);
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

  for(int i = 0; i < CANTIDAD_PELOTAS; i++){
    pelotas[i].dibujar();
  }
}

void Cuadro::actualizar(){
  for(int i = 0; i < CANTIDAD_PELOTAS; i++){
    pelotas[i].actualizar(ancho, alto);
  }
}

Pelota::Pelota(){
  x = 1;
  y = 1;
  angulo = (rand() % 20 + 26) * M_PI / 25; // 315 grados en radianes.
  velocidad = rand() % 6 + 1;
  color = rand() % 10 + 1;
}

int Pelota::getY(){
  return ceil(y);
}

int Pelota::getX(){
  return ceil(x);
}

void Pelota::dibujar(){
  gotoxy(getX(), getY());
  textcolor(color);
  cout << 'o' << endl;
}

void Pelota::rebotar(float anguloPared){
  float azar = rand() / RAND_MAX * 2 - 1;
  angulo = anguloPared - angulo;
}

void Pelota::actualizar(int ancho, int alto){
  // Calcular trayectoria de la pelota.
    y -= sin(angulo) * velocidad;
    x += cos(angulo) * velocidad;
    
    // Calcular el rebote de la pelota
    if(getX() > ancho - 2){ 
      x = ancho - 2;
      rebotar(3/2 * M_PI);
    }

    if(getX() < 1){
      x = 1;
      rebotar(3/2 * M_PI);
    }

    if(getY() > alto - 1){ 
      y = alto - 1;
      rebotar(2 * M_PI);
    }

    if(y < 1){ 
      y = 1;
      rebotar(2 * M_PI);
    }
}