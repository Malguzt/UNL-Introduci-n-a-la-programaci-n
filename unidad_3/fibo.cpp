#include <iostream>
using namespace std;
bool isFibo(int number);

int main(int argc, char *argv[]) {
	int number;
	cout << "Write a number.\n";
	cin >> number;
	if(isFibo(number)){
		cout << "It's a Fibonacci number\n";
	} else {
		cout << "It's not a Fibonacci number\n";
	}
	
	return 0;
}

bool isFibo(int number){
	int num1, num2, i;
	num1 = num2 = 1;
	while(num2 < number && num1 < number){
		i++;
		if(num1 < num2){
			num1 += num2;
		} else {
			num2 += num1;
		}
	}
	cout << num1 << endl << num2 << endl << i;
	if(num1 == number || num1 == number){
		
		return true;
	}
	
	return false;
}
