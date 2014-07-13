#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

void todoMayusculas(char *texto);
void todoMinusculas(char *texto);
void primeraMayuscula(char *texto);

int main(int argc, char const *argv[]){
  cout << "Introdusca el texto a tratar. Escriba XX para terminar.\n";
  char letra;
  char *texto = new char[1];
  char *viejoTexto;

  int j = 1;
  while(cin.get(texto[j - 1]) && !(j > 1 && texto[j - 1] == 'X' && texto[j - 2] == 'X')){
    if(texto[j - 1] == '\n'){
      texto[j - 1] = ' ';
    }
    
    viejoTexto = texto;
    texto = new char[j + 1];

    for(int i = 0; i < j; i++){
      texto[i] = viejoTexto[i];
    }

    delete viejoTexto;

    j++;
  }

  texto[j - 3] = '\0';

  cout << "El texto completo es:\n";
  cout << texto << endl;

  cout << "Con una longitud de " << strlen(texto) << " caracteres\n";


  int opcion;
  cout << "Las opciones son:\n";
  cout << "1) Pasar a Mayúsculas\n";
  cout << "2) Pasar a Minúsculas\n";
  cout << "3) Solo la inicial en Mayúscula\n";
  cin >> opcion;

  switch(opcion){
    case 1:
      todoMayusculas(texto);
      break;
    case 2:
      todoMinusculas(texto);
      break;
    case 3:
      primeraMayuscula(texto);
      break;
    default:
      cout << "Opción invalida\n";
      break;
  }

  cout << "El texto modificado es: \n" << texto << endl;

  return 0;
}


void todoMayusculas(char *texto){
  int max = strlen(texto);
  for(int i = 0; i < max; i++){
    texto[i] = toupper(texto[i]);
  }
}

void todoMinusculas(char *texto){
  int max = strlen(texto);
  for(int i = 0; i < max; i++){
    texto[i] = tolower(texto[i]);
  }
}

void primeraMayuscula(char *texto){
  texto[0] = toupper(texto[0]);
}