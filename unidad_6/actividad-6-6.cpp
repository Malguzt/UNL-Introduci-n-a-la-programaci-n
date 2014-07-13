#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]){
	ifstream archivo("texto");

	char texto[200];
	// archivo >> texto;
	archivo.getline(texto, 200);

	cout << "El contenido del archivo es:\n" << texto << endl;

	return 0;
}