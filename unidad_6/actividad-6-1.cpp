#include <iostream>
#include <string.h>

using namespace std;

typedef char palabra[13];
void ordenar(char **palabras, int cantidad);

int main(int argc, char const *argv[]){
  char **palabras = NULL;
  
  cout << "Intodusca las palabras a procesar de menos de 12 letras.\n";
  
  char *nuevaPalabra = new palabra;
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
    nuevaPalabra = new palabra;
  }

  cout << "\nLas palabras cargadas fueron: \n";

  ordenar(palabras, j);
  
  for (int i = 0; i < j; ++i){
    cout << palabras[i] << endl;
  }

  return 0;
}

void ordenar(char **palabras, int cantidad){
  char *aux;
  bool ordenado = false;
  
  while (!ordenado){
    ordenado = true;
    
    for(int i = 0; i < cantidad; i++){
      if(strcmp(palabras[i], palabras[i + 1]) > 0){
        ordenado = false;
        
        aux = palabras[i];
        palabras[i] = palabras[i + 1];
        palabras[i + 1] = aux;
      }
    }
  }
}