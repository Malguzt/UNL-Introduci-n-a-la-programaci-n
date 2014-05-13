#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado();

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a = 0;
	a = dado();
	cout << "Salio " << a << endl;
	
	return 0;
}

int dado(){
	return rand() % 6 + 1;
}
