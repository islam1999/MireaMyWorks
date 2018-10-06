#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	double number1, number2, result;
	char operation;
	bool repeat = true;

	while (repeat) {
		cout << "Enter expression with numbers in following format: {number} {operation} {number}\nExample: 12 + 31" << endl;

		scanf("%lg %c %lg", &number1, &operation, &number2);

		switch(operation) {
			case '+':
				result = number1 + number2;
				repeat = false;
				break;
			case '-':
				result = number1 - number2;
				repeat = false;
				break;
			case '*':
				result = number1 * number2;
				repeat = false;
				break;
			case '/':
				result = number1 / number2;
				repeat = false;
				break;
			default:
				cout << "Unsupported operation " << operation << " .\nTry on of supported: +, -, /, *\n";
				break;
		}
	}

	printf("%lg %c %lg = %lg\n", number1, operation, number2, result);

	return 0;
}
