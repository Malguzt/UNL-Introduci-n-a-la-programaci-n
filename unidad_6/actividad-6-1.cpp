#include <iostream>
#include <string.h>

using namespace std;

typedef char palabra[13];

palabra *agregarPalabra(palabra* palabras, palabra nuevaPalabra);

int main(int argc, char const *argv[]){
  palabra *palabras = NULL;
  
  cout << "Intodusca las palabras a procesar de menos de 12 letras.\n";
  palabra nuevaPalabra;

  while(cin.getline(nuevaPalabra, 12)){
    agregarPalabra(palabras, nuevaPalabra);
  }

  for (int i = 0; i < sizeof(palabras) / sizeof(palabra); ++i){
    cout << nuevaPalabra << endl;
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
