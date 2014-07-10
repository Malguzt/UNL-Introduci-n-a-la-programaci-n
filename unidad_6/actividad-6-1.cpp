#include <iostream>
#include <string.h>

using namespace std;

typedef char palabra[13];

palabra *agregarPalabra(palabra* palabras, palabra nuevaPalabra);

int main(int argc, char const *argv[]){
  char **palabras = NULL;
  
  cout << "Intodusca las palabras a procesar de menos de 12 letras.\n";
  
  char *nuevaPalabra;
  char **palabrasAnteriores;
  int j = 0;

  while(cin.getline(nuevaPalabra, 12) && !strstr(nuevaPalabra, "XX")){
    palabrasAnteriores = palabras;

    palabras = new char* [j + 1];

    for (int i = 0; i < j; ++i){
      palabras[i] = palabrasAnteriores[i];
    }

    palabras[j] = nuevaPalabra;

    j++;
    delete palabrasAnteriores;
  }

  cout << "\nLas palabras cargadas fueron: \n";
  
  for (int i = 0; i < j; ++i){
    cout << palabras[i] << endl;
  }

  return 0;
}

palabra *agregarPalabra(palabra* palabras, palabra nuevaPalabra){
  cout << palabras[0] << endl;

  palabra *palabrasAnteriores;
  palabrasAnteriores = palabras;

  int cantidad = sizeof(palabrasAnteriores) / sizeof(palabra);
  palabras = new palabra[cantidad + 1];

  if(cantidad > 0){
    memcpy (palabras, palabrasAnteriores, sizeof(palabrasAnteriores));
  }
  strcpy(palabras[cantidad], nuevaPalabra);

  delete palabrasAnteriores;
  
  return palabras;
}
