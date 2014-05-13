#include <iostream>
using namespace std;

void intercambio(int &var1, int &var2);
void intercambio(char &var1, char &var2);
void intercambio(float &var1, float &var2);

int main(int argc, char *argv[]) {
	int a,b;
	float c,d;
	char e,f;
	
	a=5;
	b=10;
	
	intercambio(a,b);
	
	cout << "a= " << a <<" b= " << b << endl;
	
	c=3.5;
	d=8.7;
	
	intercambio(c,d);
	
	cout << "c= " << c <<" d= " << d << endl;
	
	e='j';
	f='k';
	
	intercambio(e,f);
	
	cout << "e= " << e <<" f= " << f << endl;
	
	return 0;
}

void intercambio(int &var1, int &var2){
	int aux = var1;
	var1 = var2;
	var2 = aux;
}

void intercambio(char &var1, char &var2){
	char aux = var1;
	var1 = var2;
	var2 = aux;
}

void intercambio(float &var1, float &var2){
	float aux = var1;
	var1 = var2;
	var2 = aux;
}
