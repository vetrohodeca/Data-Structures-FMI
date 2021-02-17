#include<iostream>
using namespace std;
int main()
{
	/*
	task 1

	int n;
	cin >> n;
	long long int factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial = factorial * i;
	}
	cout << factorial;

	task 2

	int number, counter = 0;
	cin >> number;
	if (number == 0)
	{
		cout << 0;
	}
	else
	{
		while (number != 0)
		{
			number = number / 10;
			counter++;
		}
	}
	cout << counter;


	task 3 - while
		int number, divisor = 2;
	cin >> number;
	while (divisor < 10)
	{
		if (number % divisor == 0)
		{
			cout << divisor << " is divisor" << endl;
		}
		divisor++;
	}

	task 3 do - while

		int number, divisor = 2;
	cin >> number;
	do
	{
		if (number % divisor == 0)
		{
			cout << divisor << " is divisor" << endl;
		}
		divisor++;
	} while (divisor <= 10);

	4 task

		int beforeLastNumber = 0;
	int lastNumber = 1;
	cout << beforeLastNumber << " " << lastNumber << " ";
	for (int i = 0; i < 18; i++)
	{
		int current = lastNumber + beforeLastNumber;
		cout << current << " ";
		beforeLastNumber = lastNumber;
		lastNumber = current;
	}

	5 task

		for (int i = 100; i < 1000; i++)
		{
			int thirdDigit = i % 10;
			int secondDigit = i / 10 % 10;
			int firstDigit = i / 100 % 10;
			if (firstDigit != secondDigit && firstDigit != thirdDigit && thirdDigit != secondDigit)
			{
				cout << i << " ";
			}
		}

	task 6

		int n;
	cin >> n;
	for (int i = 2; i < 1000; i++)
	{
		if (i % n == 0)
		{
			cout << i << "  ";
		}
	}

	task 7

	int number, sumOfDeviders=0;
	cin >> number;
	for (int i = 1; i <= number/2; i++)
	{
		if (number % i == 0)
		{
			sumOfDeviders += i;
		}
	}
	if (sumOfDeviders == number)
	{
		cout << "true";
	}
	else
	{
		cout << "fasle";
	}
	*/
	int number,sum=0, countOfDigits=0;
	cin >> number;
	int copyOfNumber = number;
	while (copyOfNumber!=0)
	{
		copyOfNumber /= 10;
		countOfDigits++;
	}
	copyOfNumber = number;
	for (int i = 0; i < countOfDigits; i++)
	{
		sum += pow(copyOfNumber % 10,countOfDigits);
		copyOfNumber /= 10;
	}
	if (sum == number)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}