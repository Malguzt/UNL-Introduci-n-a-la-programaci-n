#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio2.h>
using namespace std;

typedef char palabra[20];
typedef struct {
  palabra letras;
  int x;
  int y;
  bool vertical;
} p_escondida;

void dibujarSopa(char letras[20][20]);
char **cargarPalabras(char *nombreArchivo, int& totalPalabras);
p_escondida *acomodarPalabras(char **palabras, int totalPalabras);

int main(int argc, char const *argv[]){
  srand(time(NULL));
  char escondidas[5][20];

  int totalPalabras;
  char **palabras = cargarPalabras("palabras.txt", totalPalabras);

  char letras[20][20];
  
  //Poniendo espacios en blanco
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
       letras[i][j] = ' ';
    }
  }
  
  
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
      if(letras[i][j] == ' '){
        // letras[i][j] = 'A' + rand()%26;
        letras[i][j] = '_';
      }
    }
  }

  dibujarSopa(letras);
  
  return 0;
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

void dibujarSopa(char letras[20][20]){
  clrscr();
  textcolor(BLUE);
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
      gotoxy((i + 1) * 2, (j + 1));
      cout << letras[i][j];
    }
  }
  cout << endl;
}

p_escondida *acomodarPalabras(char **palabras, int totalPalabras){
  p_escondida escondidas[5];

  //Definiendo palabras escondidas
  for (int i = 0; i < 5; ++i){
    int n = rand()%totalPalabras;
    for (int j = 0; j < 20; ++j){
      escondidas[i].letras[j] = palabras[n][j];
    }

    int j = 0;
    int x, y;
    int vertical = rand()%2;
    int largo = strlen(escondidas[i].letras);

    if (vertical){
      do{
        y = rand()%20;
      } while(y + largo >= 20);
      x = rand()%20;
    } else {
      do{
        x = rand()%20;
      } while(x + largo >= 20);
      y = rand()%20;
    }

    while(j < 20 && escondidas[i].letras[j] != '\0'){
      if(vertical){
        letras[x][y + j] = toupper(escondidas[i].letras[j]);
      } else {
        letras[x + j][y] = toupper(escondidas[i].letras[j]);
      }
      j++;
    }
  }
}