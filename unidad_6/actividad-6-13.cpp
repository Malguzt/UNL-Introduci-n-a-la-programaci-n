#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio2.h>
using namespace std;

void dibujarAhorcado(int);

typedef char palabra[20];
int main(int argc, char const *argv[]){
  ifstream archivo("palabras.txt");

  char **palabras = NULL;
  char *nuevaPalabra = new palabra;
  char **palabrasAnteriores;
  int j = 0;

  while(!archivo.eof()){
    archivo >> nuevaPalabra;
    palabrasAnteriores = palabras;

    palabras = new char* [j + 1];

    for (int i = 0; i < j; ++i){
      palabras[i] = palabrasAnteriores[i];
    }

    palabras[j] = nuevaPalabra;

    j++;
    delete palabrasAnteriores;
    nuevaPalabra = new palabra;
  }

  srand(time(NULL));
  int x = rand()%j;

  cout << palabras[x] << endl;
  char nada[4];
  for (int i = 0; i < 6; ++i){
    dibujarAhorcado(i);
    cin >> nada;
  }
  
  return 0;
}

void dibujarAhorcado(int errores){
  clrscr();
  gotoxy(1,1);
  textcolor(BLUE);
  cout << " _______" << endl;
  cout << " |     |" << endl;
  cout << "       |" << endl;
  cout << "       |" << endl;
  cout << "       |" << endl;
  cout << "       |" << endl;
  cout << "       |" << endl;
  textcolor(GREEN);
  cout << "------------" << endl;

  switch(errores){
    case 4:
      gotoxy(2,5);
      textcolor(BLUE);
      cout << "/\\";
    case 3:
      gotoxy(1,4);
      textcolor(YELLOW);
      cout << "-()-";
    case 2:
      gotoxy(2,4);
      textcolor(YELLOW);
      cout << "()";
    case 1:
      gotoxy(2,3);
      textcolor(BROWN);
      cout << "O";
      break;
    case 5: // Dibujo especial para cuando pierda
      gotoxy(2,3); //Cabeza
      textcolor(BROWN);
      cout << "O";

      gotoxy(1,4); //Torso
      textcolor(YELLOW);
      cout << "-";
      textcolor(RED);
      cout << "(";
      textcolor(YELLOW);
      cout << ")-";

      gotoxy(2,5); //Piernas
      textcolor(RED);
      cout << "/";
      textcolor(BLUE);
      cout << "\\";

      gotoxy(2,6); //Sangre
      textcolor(RED);
      cout << ".";
      gotoxy(2,7);
      cout << "\"";
      gotoxy(1,8);
      cout << "---";
      break;
  }
}