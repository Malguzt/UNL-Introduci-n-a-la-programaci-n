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
  srand(time(NULL));
  ifstream archivo("palabras.txt");

  char **palabras = NULL;
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

  int errores;
  char letra;
  bool existe;
  int encontradas;
  palabra descubiertas;
  char respuesta;
  for (int i = 0; i < totalPalabras; ++i){
    int x = rand()%totalPalabras;
    errores = 0;
    encontradas = 0;

    for (int j = 0; j < strlen(palabras[x]); ++j){
      descubiertas[j] = '_';
      descubiertas[j + 1] = '\0';
    }

    while(errores < 5 && encontradas < strlen(palabras[x])){
      dibujarAhorcado(errores);
      gotoxy(10,3);
      textcolor(WHITE);
      cout << descubiertas;
      gotoxy(1, 10);
      letra = getch();

      existe = false;
      for (int j = 0; j < strlen(palabras[x]); ++j){
        if(palabras[x][j] == letra && descubiertas[j] != letra){
          descubiertas[j] = letra;
          encontradas++;
          existe = true;
        }
      }

      if(!existe){
        errores++;
      }
    }


    if(errores == 5){
      dibujarAhorcado(5);
      gotoxy(1, 9);
      textcolor(RED);
      cout << "Lo lamento, has perdido. La palabra era: " << palabras[x] << endl;
    }

    if(encontradas == strlen(palabras[x])){
      gotoxy(10,3);
      textcolor(WHITE);
      cout << descubiertas;
      gotoxy(1, 9);
      textcolor(GREEN);
      cout << "Felicidades, has ganado\n";
    }

    cout << "¿Jugar de nuevo? s/n\n";
    respuesta = ' ';
    while(respuesta != 's' && respuesta != 'n'){
      respuesta = getch();
    }

    if(respuesta == 'n'){
      break;
    }
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