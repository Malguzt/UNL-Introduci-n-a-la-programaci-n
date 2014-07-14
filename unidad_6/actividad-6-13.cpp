#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

char *leerPalabra(char *archivo);

int main(int argc, char const *argv[]){
  ifstream archivo("palabras.txt");
  char *palabra;

  palabra = leerPalabra(archivo);

  cout << "El contenido del archivo es:\n" << palabra << endl;

  return 0;
}

char *leerPalabra(char *archivo){
  char *palabra = new char[1];
  char *viejaPalabra;

  int j = 1;
  while(archivo.get(palabra[j - 1]) && !(palabra[j - 1] == ' ' || palabra[j - 1] == '\n')){
    viejaPalabra = palabra;
    palabra = new char[j + 1];

    for(int i = 0; i < j; i++){
      palabra[i] = viejaPalabra[i];
    }

    delete viejaPalabra;

    j++;
  }

  palabra[j - 1] = '\0';

  return palabra;
}