#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio2.h>
using namespace std;

const int dificultad = 5;

typedef char palabra[20];
typedef struct {
  palabra letras;
  int x;
  int y;
  bool vertical;
  bool encontrada;
} p_escondida;
typedef struct {
  int x;
  int y;
} cursor;

void dibujarSopa(char **letras, cursor seleccion, bool seleccionando, p_escondida *escondidas);
char **cargarPalabras(char *nombreArchivo, int& totalPalabras);
p_escondida *acomodarPalabras(char **palabras, int totalPalabras);
char **armarSopa(p_escondida *escondidas);
p_escondida *comprobarPalabra(p_escondida *escondidas, cursor seleccion, bool vertical);

int main(int argc, char const *argv[]){
  srand(time(NULL));

  cursor seleccion;
  seleccion.x = seleccion.y = 1;
  int totalPalabras;
  int tecla;
  bool seleccionando = false;
  char nombreArchivo[] = "palabras.txt";
  char **palabras = cargarPalabras(nombreArchivo, totalPalabras);
  p_escondida *escondidas = acomodarPalabras(palabras, totalPalabras);

  char **sopa = armarSopa(escondidas);
  
  while(tecla != 'q'){
    dibujarSopa(sopa, seleccion, seleccionando, escondidas);
    tecla = getch();
    switch(tecla) {
      case 10:
        seleccionando = true;
        break;
      case 65: //arriba
        if(seleccionando){
          escondidas = comprobarPalabra(escondidas, seleccion, true);
          seleccionando = false;
        } else {
          if(1 < seleccion.y){
            seleccion.y--;
          }
        }
        break;
      case 66: //abajo
        if(seleccionando){
          escondidas = comprobarPalabra(escondidas, seleccion, true);
          seleccionando = false;
        } else {
          if(20 > seleccion.y){
            seleccion.y++;
          }
        }
        break;
      case 67: //derecha
        if(seleccionando){
          escondidas = comprobarPalabra(escondidas, seleccion, false);
          seleccionando = false;
        } else {
          if(20 > seleccion.x){
            seleccion.x++;
          }
        }
        break;
      case 68: //izquierda
        if(seleccionando){
          escondidas = comprobarPalabra(escondidas, seleccion, false);
          seleccionando = false;
        } else {
          if(1 < seleccion.x){
            seleccion.x--;
          }
        }
        break;
      }
  }
  
  return 0;
}

p_escondida * comprobarPalabra(p_escondida *escondidas, cursor seleccion, bool vertical){
  for (int i = 0; i < dificultad; ++i){
    if (escondidas[i].vertical == vertical && escondidas[i].x + 1 == seleccion.x && escondidas[i].y + 1 == seleccion.y){
      escondidas[i].encontrada = true;
    }
  }

  return escondidas;
}

char **cargarPalabras(char *nombreArchivo, int& totalPalabras){
  char **palabras = NULL;
  ifstream archivo(nombreArchivo);

  char *nuevaPalabra = new palabra;
  char **palabrasAnteriores;
  totalPalabras = 0;

  while(!archivo.eof()){
    archivo >> nuevaPalabra;
    palabrasAnteriores = palabras;

    palabras = new char* [totalPalabras + 1];

    for (int i = 0; i < totalPalabras; ++i){
      palabras[i] = palabrasAnteriores[i];
    }

    palabras[totalPalabras] = nuevaPalabra;

    totalPalabras++;
    delete palabrasAnteriores;
    nuevaPalabra = new palabra;
  }

  return palabras;
}

void dibujarSopa(char **letras, cursor seleccion, bool seleccionando, p_escondida *escondidas){
  clrscr();
  
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
      if(seleccion.x == i + 1 && seleccion.y == j + 1){
        if(seleccionando){
          textcolor(YELLOW);
        } else {
          textcolor(BROWN);
        }
      } else {
        textcolor(BLUE);
      }
      gotoxy((i + 1) * 2, (j + 1));
      cout << letras[i][j];
    }
  }

  for (int i = 0; i < dificultad; ++i){
    textcolor(RED);
    if (escondidas[i].encontrada){
      textcolor(GREEN);
      for (int j = 0; j < strlen(escondidas[i].letras); ++j){
        if(escondidas[i].vertical){
          gotoxy((escondidas[i].x + 1) * 2, (escondidas[i].y + j + 1));
        } else {
          gotoxy((escondidas[i].x + j + 1) * 2, ( escondidas[i].y + 1));
        }
        cout << char(toupper(escondidas[i].letras[j]));
      }
    }

    gotoxy(1, 22 + i);
    cout << escondidas[i].letras;
  }

  textcolor(WHITE);
  gotoxy(44, 1);
  cout << "Mueva el cursor hasta el comienzo de la palabra.\n";
  gotoxy(44, 2);
  cout << "Precione enter.\n";
  gotoxy(44, 3);
  cout << "Con el cursor indique la dirección de la palabra.\n";
  gotoxy(44, 4);
  cout << "Para salir precione 'q'\n";
}

p_escondida *acomodarPalabras(char **palabras, int totalPalabras){
  p_escondida *escondidas = new p_escondida[dificultad];
  bool diferente, chocan;
  int n; // Numero aleatorio que indica que palabra de la lista se va a usar.

  for (int i = 0; i < dificultad; ++i){
    escondidas[i].encontrada = false;
    do{
      diferente = true;
      n = rand()%totalPalabras;
      for (int j = 0; j < i; ++j){
        if(!strcmp(palabras[n], escondidas[j].letras)){
          diferente = false;
        }
      }
    } while(!diferente);

    strcpy(escondidas[i].letras, palabras[n]);

    escondidas[i].vertical = rand()%2;
    int largo = strlen(escondidas[i].letras);

    if (escondidas[i].vertical){
      escondidas[i].y = rand()%(20 - largo);
      escondidas[i].x = rand()%20;
    } else {
      escondidas[i].y = rand()%20;
      escondidas[i].x = rand()%(20 - largo);
    }

    do{
      chocan = false;
      for (int j = 0; j < i; ++j){
        if(escondidas[i].vertical == !escondidas[j].vertical){
          if(escondidas[i].vertical){
            bool chocanEnX = escondidas[i].x >= escondidas[j].x && escondidas[i].x <= escondidas[j].x + strlen(escondidas[j].letras);
            bool chocanEnY = escondidas[j].y >= escondidas[i].y && escondidas[j].y <= escondidas[i].y + strlen(escondidas[i].letras);
            if(chocanEnX && chocanEnY){
              escondidas[i].y = rand()%(20 - largo);
              escondidas[i].x = rand()%20;
              chocan = true;
            }
          } else {
            bool chocanEnX = escondidas[j].x >= escondidas[i].x && escondidas[j].x <= escondidas[i].x + strlen(escondidas[i].letras);
            bool chocanEnY = escondidas[i].y >= escondidas[j].y && escondidas[i].y <= escondidas[j].y + strlen(escondidas[j].letras);
            if(chocanEnX && chocanEnY){
              escondidas[i].x = rand()%(20 - largo);
              escondidas[i].y = rand()%20;
              chocan = true;
            }
          }
        }
        if (escondidas[i].vertical == escondidas[j].vertical){
          if(escondidas[i].vertical){
            if (escondidas[i].x == escondidas[j].x){
              escondidas[i].x = rand()%20;
            }
          } else {
            if (escondidas[i].y == escondidas[j].y){
              escondidas[i].y = rand()%20;
            }
          }
        }
      }
    } while(chocan);
  }

  return escondidas;
}

char **armarSopa(p_escondida *escondidas){
  char **sopa = new char*[20];
  for (int i = 0; i < 20; ++i){
    sopa[i] = new char[20];
  }

  //Poniendo espacios en blanco
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
       sopa[i][j] = ' ';
    }
  }
  
  for (int i = 0; i < dificultad; ++i){
    int j = 0;
    while(j < 20 && escondidas[i].letras[j] != '\0'){
      if(escondidas[i].vertical){
        sopa[escondidas[i].x][escondidas[i].y + j] = toupper(escondidas[i].letras[j]);
      } else {
        sopa[escondidas[i].x + j][escondidas[i].y] = toupper(escondidas[i].letras[j]);
      }
      j++;
    }
  }
  
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
      if(sopa[i][j] == ' '){
        sopa[i][j] = 'A' + rand()%26;
      }
    }
  }
  
  return sopa;
}