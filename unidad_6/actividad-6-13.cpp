#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;



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
  
  return 0;
}