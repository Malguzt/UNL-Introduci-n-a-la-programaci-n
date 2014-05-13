#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras = 6);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a = 0;
	a = dado(20);
	cout << "Salio " << a << endl;
	
	return 0;
}

int dado(int caras){
	return rand() % caras + 1;
}
