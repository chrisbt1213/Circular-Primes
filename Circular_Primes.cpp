#include<iostream>
#include<string>

using namespace std;

bool isPrime(int possiblePrimePar);
bool isCircularPrime(int possibleCircularPrimePar);

int main() {
	//declarations
	string output = "";
	int userInput;
	int counter;
	int countingCircularPrimes = 0;
	string display;

	//get user input
	cout << "How many circular primes are below: ";
	cin >> userInput;

	//calculations
	if (userInput == 1) {
		output = "2";
		cout << output << endl;
	}
	else {
		for (counter = 2; counter < userInput; counter++) {
			if (isPrime(counter) == true && isCircularPrime(counter)) {
				display = display + to_string(counter) + ", ";
				countingCircularPrimes++;
			}
		}
	}
	//output
	cout << countingCircularPrimes << ": ";
	cout << display;
	cout << endl;

	system("pause");
	return 0;
}

bool isPrime(int possiblePrimePar)
{
	if (possiblePrimePar <= 1)
		return false;
	if (possiblePrimePar <= 3)
		return true;

	if (possiblePrimePar % 2 == 0 || possiblePrimePar % 3 == 0)
		return false;

	for (int counter = 5; counter * counter <= possiblePrimePar; counter = counter + 6)
		if (possiblePrimePar % counter == 0 || possiblePrimePar % (counter + 2) == 0)
			return false;

	return true;
}

bool isCircularPrime(int possibleCircularPrimePar)
{
	int counter = 0;
	int temp = to_string(possibleCircularPrimePar).length();

	int num = possibleCircularPrimePar;
	while (isPrime(num)) {
		int remainder = num % 10;
		int divisor = num / 10;
		num = (pow(10, temp - 1)) * remainder + divisor;

		if (num == possibleCircularPrimePar)
			return true;
	}

	return false;
}