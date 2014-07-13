#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int contarVocales(char *texto);
int contarConsonantes(char *texto);
void todoMinusculas(char *texto);
bool esVocal(char letra);
bool esConsonante(char letra);

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

  todoMinusculas(texto);
  
  cout << "Con " << contarVocales(texto) << " vocales.\n";
  cout << "Con " << contarConsonantes(texto) << " consonantes.\n";

  return 0;
}

bool esVocal(char letra){
  switch (letra){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        
        return true;
        break;
    }

    return false;
}

int contarVocales(char *texto){
  int max = strlen(texto);
  int vocales = 0;
  for(int i = 0; i < max; i++){
    if(esVocal(texto[i])){
      vocales++;
    }
  }

  return vocales;
}

bool esConsonante(char letra){
  switch (letra){
      case 'b':
      case 'c':
      case 'd':
      case 'f':
      case 'g':
      case 'h':
      case 'j':
      case 'k':
      case 'l':
      case 'm':
      case 'n':
      case 'p':
      case 'q':
      case 'r':
      case 's':
      case 't':
      case 'v':
      case 'w':
      case 'x':
      case 'y':
      case 'z':
        
        return true;
        break;
    }

    return false;
}

void todoMinusculas(char *texto){
  int max = strlen(texto);
  for(int i = 0; i < max; i++){
    texto[i] = tolower(texto[i]);
  }
}

int contarConsonantes(char *texto){
  int max = strlen(texto);
  int consonantes = 0;
  for(int i = 0; i < max; i++){
    if(esConsonante(texto[i])){
      consonantes++;
    }
  }

  return consonantes;
}