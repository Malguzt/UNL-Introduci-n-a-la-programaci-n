#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio2.h>
using namespace std;

void dibujarSopa(char letras[20][20]);
int cargarPalabras(char *nombreArchivo, char **palabras);

typedef char palabra[20];
int main(int argc, char const *argv[]){
  srand(time(NULL));
  char **palabras = NULL;
  char escondidas[5][20];

  int totalPalabras = cargarPalabras("palabras.txt", palabras);

  char letras[20][20];
  
  //Poniendo letras aleatoreas para la sopa
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 20; ++j){
       letras[i][j] = 'a' + rand()%26;
    }
  }
  
  //Definiendo palabras escondidas
  for (int i = 0; i < 5; ++i){
    int x = rand()%totalPalabras;
    // for (int j = 0; j < 20; ++j){
    //   escondidas[i][j] = palabras[x][j];
    // }

    // int j = 0;
    // int posicion = rand()%20;
    // while(j < 20 && escondidas[i][j] != '\0'){
    //   letras[posicion][j] = escondidas[i][j];
    //   j++;
    // }
  }
  
  dibujarSopa(letras);
  
  return 0;
}

int cargarPalabras(char *nombreArchivo, char **palabras){
  ifstream archivo(nombreArchivo);

  char *nuevaPalabra = new palabra;
  char **palabrasAnteriores;
  int totalPalabras = 0;

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

  return totalPalabras;
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