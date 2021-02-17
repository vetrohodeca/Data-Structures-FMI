#include<iostream>
#include "Stack.h"
#include<string>
#include"task1.cpp"
using namespace std;
int main()
{
	Stack<char> openingBrackets;
	Stack<char> closingBrackets;
	Stack<int> digits;
	Stack<char> operations;
	cout << calculate("(78 + (2 * (3 + 42)))",openingBrackets, closingBrackets,digits,operations)<<endl;
	while (digits.getSize() != 0)
	{
		cout<<digits.top()<<endl;
		digits.pop();
	}
	return 0;
}