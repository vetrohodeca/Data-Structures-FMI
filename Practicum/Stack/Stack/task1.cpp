#pragma once
#include<iostream>
#include "Stack.h"
#include<string>

using namespace std;

//task1
bool isCorrectBrackets(string str)
{
	Stack<char> myStack;
	int strlen = str.length();
	for (int i = 0; i < strlen; i++)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '{')
		{
			myStack.push(str[i]);
		}
		else if (str[i] == ']' || str[i] == ')' || str[i] == '}')
		{
			if (myStack.IsEmpty())
			{
				return false;
			}
			else if (str[i] == ']' && myStack.top() == '[')
			{
				myStack.pop();
			}
			else if (str[i] == ')' && myStack.top() == '(')
			{
				myStack.pop();
			}
			else if (str[i] == '}' && myStack.top() == '{')
			{
				myStack.pop();
			}
			else
			{
				return false;
			}
		}
	}

}

//task2
Stack<int> stack;
double calculateOperations(char op, double firstArg, double SecondArg)
{
	switch (op)
	{
	case'/': return firstArg / SecondArg; break;
	case'.': return firstArg * SecondArg; break;
	case'+': return firstArg + SecondArg; break;
	case'-': return firstArg - SecondArg; break;
	}
}
double calculate(string str,Stack<char>& openingBrackets, Stack<char>& closingBrackets, Stack<int>& digits, Stack<char>& operations)
{
	double curentResult = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			openingBrackets.push(str[i]);
		}
		if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/')
		{
			operations.push(str[i]);
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			int digit = str[i]-'0';
			i++;
			while ((str[i] >= '0' && str[i] <= '9'))
			{
				digit *= 10;
				digit += str[i]-'0';
				i++;
			}
			digits.push(digit);
		} 
	}
	return 0;
}