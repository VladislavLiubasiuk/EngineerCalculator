// Engineer's Calculator.cpp

using namespace std;
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

const double e = 2.71828182846;
const double PI = 3.14159265359;
const int ADD = 1;
const int SUBSTRACT = 2;
const int MULTIPLY = 3;
const int DIVIDE = 4;
const int POW = 5;
const int SQRT = 6;
const int ABSTRACT = 7;
const int TENTHPART = 8;
const int EXPONENT = 9;
const int REMAINDER = 10;
const int FACTORIAL = 11;
const int TENTOPOWER = 12;
const int LOGARITHM = 13;
const int SQRTCUSTOM = 14;
const int SQRTCUBE = 15;
const int TWOTOPOWER = 16;
const int NUMTOPOWERTWO = 17;
const int NUMTOPOWERTHREE = 18;

double number1, number2, result3;
int  operation;
char answer;

double addNumbers(double number1, double number2)
{
    //add number1 to number2
    return (number1 + number2);
}

double substractNumbers(double number1, double number2)
{
    //substract number2 from number1
    return (number1 - number2);
}

double divideNumbers(double number1, double number2)
{
    //divide number1 by number2
    return (number1 / number2);
}

double multiplyNumbers(double number1, double number2)
{
    //multiply number1 by number2
    return (number1 * number2);
}

double powNumbers(double number1, double number2)
{   
    //return an exponentiated number
    return pow(number1, number2);
}

double sqrtNumber(double number1)
{
    //return the square root of the given number
    return sqrt(number1);
}

double absNumber(double number1)
{
    //return the module of a variable -> |-20| = 20
    return abs(number1);
}

double tenthPartOfNumber(double number1) 
{
    // return 10th part of the number1
    int temp = log10((number1)+1);
    int temp2 = pow(10, temp);
    return (number1 / temp2);
}

double exponentNumber(double number1) 
{
    //return Eilner's number in number1 power
    return pow(e, 2);
}

double remainderFromNumber(int number1, int number2) //possible data loss because of the implycit change?
{
    //return remainder from the divide operation between number1 and number2
    return (number1 % number2);
}

double factorialFromNumber(int number1)
{
    //return factorial from number1
    int sum = 1;
    for (int i = 1; i <= number1; i++) {
        sum = sum * i;
    }
    return sum;
}

double tenToPower(double number1)
{
    //return 10 with power number1
    return pow(10, number1);
}

double logarithmFromNumber(double number1)
{
    //return log from number1
    return log(number1);
}

double sqrtCustomNumber(double number1, double number2) 
{
	//return the custom root of the given number
	return pow(number1, 1 / number2);
}

double sqrtCubeNumber(double number1)
{
	//return the cube root of the given number
	return pow(number1, 1 / 3);
}

double twoToPower(double number1)
{
	//return 2 in power of number1
	return pow(2, number1);
}

double numberToPowerTwo(double number1)
{
	//return number1 in power of 2
	return pow(number1, 2);
}

double numberToPowerThree(double number1)
{
	//return number1 in power of 3
	return pow(number1, 3);
}

void writingIntoFile(double number1, double number2, double result3, int operation, string Symbol)
{
	ofstream myfile("PerformedOperationsList.txt", ios::app);
	if (myfile.is_open())
	{
		if (operation != ADD && operation != SUBSTRACT && operation != MULTIPLY && operation != DIVIDE &&
			operation != POW && operation != REMAINDER && operation != SQRTCUSTOM)
		{
			myfile << number1 << " " << Symbol << " = " << result3 << std::endl;
		}
		else if (operation == TENTOPOWER || operation == LOGARITHM || operation == TWOTOPOWER)
		{
			myfile << Symbol << number1 << " "<< " = " << result3 << std::endl;
		}
		else
		{
			myfile << number1 << " " << Symbol << " " << number2 << " = " << result3 << std::endl;
		}
	}
	else 
	{
		cout << "An error has occured. File was not created.";
	}
	myfile.flush();
	myfile.close();
	
}

double operationPick(double number1, double number2, int operation)
{
	switch (operation) {
	case ADD:
		return (addNumbers(number1, number2));
	case SUBSTRACT:
		return (substractNumbers(number1, number2));
	case MULTIPLY:
		return (multiplyNumbers(number1, number2));
	case DIVIDE:
		return (divideNumbers(number1, number2));
	case POW:
		return (powNumbers(number1, number2));
	case SQRT:
		return (sqrtNumber(number1));
	case ABSTRACT:
		return (absNumber(number1));
	case TENTHPART:
		return (tenthPartOfNumber(number1));
	case EXPONENT:
		return (exponentNumber(number1));
	case REMAINDER:
		return (remainderFromNumber(number1, number2));
	case FACTORIAL:
		return (factorialFromNumber(number1));
	case TENTOPOWER:
		return (tenToPower(number1));
	case LOGARITHM:
		return (logarithmFromNumber(number1));
	case SQRTCUSTOM:
		return (sqrtCustomNumber(number1, number2));
	case SQRTCUBE:
		return (sqrtCubeNumber(number1));
	case TWOTOPOWER:
		return (twoToPower(number1));
	case NUMTOPOWERTWO:
		return (numberToPowerTwo(number1));
	case NUMTOPOWERTHREE:
		return (numberToPowerThree(number1));
	}
}

string operationVisualizer(int operation) 
{
	switch(operation)
	{
	case ADD:
		return "+";
	case SUBSTRACT:
		return "-";
	case MULTIPLY:
		return "*";
	case DIVIDE:
		return ":";
	case POW:
		return "**";
	case SQRT:
		return "sqrt 2";
	case ABSTRACT:
		return "||";
	case TENTHPART:
		return "/10";
	case EXPONENT:
		return "**2";
	case REMAINDER:
		return "%";
	case FACTORIAL:
		return "!";
	case TENTOPOWER:
		return "10**";
	case LOGARITHM:
		return "log";
	case SQRTCUSTOM:
		return "sqrt";
	case SQRTCUBE:
		return "sqrt 3";
	case TWOTOPOWER:
		return "2**";
	case NUMTOPOWERTWO:
		return "**2";
	case NUMTOPOWERTHREE:
		return "**3";
	}
}

void operationGuide() 
{
	cout << "This is a short (butchered up) guide for what operation represent which number to choose from." << endl;;
	cout << "1 - Add num1 to num2.\n";
	cout << "2 - Substract num2 from num1.\n";
	cout << "3 - Multiply num1 by num2.\n";
	cout << "4 - Divide num1 by num2.\n";
	cout << "5 - Return an exponentiated num1.\n";
	cout << "6 - Return the square root of the num1.\n";
	cout << "7 - Return the module of a variable -> |-20| = 20.\n";
	cout << "8 - Return 10th part of the num1.\n";
	cout << "9 - Return Eilner's number in num1 power.\n";
	cout << "10 - Return remainder from the divide operation between num1 and num2.\n";
	cout << "11 - Return factorial from num1.\n";
	cout << "12 - Return 10 in power num1.\n";
	cout << "13 - Return log from num1.\n";
	cout << "14 - Return the custom (num2) root of the given num1.\n";
	cout << "15 - Return the cube root of the given num1.\n";
	cout << "16 - Return 2 in power of num1.\n";
	cout << "17 - Return num1 in power of 2.\n";
	cout << "18 - Return num1 in power of 3.\n" << endl;
}

void userInput()
{
	cout << "Input operation to perform (1-18): ";
	cin >> operation;
	while (!cin || operation > 18 || operation < 1)
	{
		cout << "Wrong input, must be numeric, or above 1 and below 18." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input operation to perform (1-18): ";
		cin >> operation;
	}

	if (operation == ADD || operation == SUBSTRACT || operation == MULTIPLY || operation == DIVIDE ||
		operation == POW || operation == REMAINDER || operation == SQRTCUSTOM)
	{
		cout << "Input first number: ";
		cin >> number1;
		while (!cin)
		{
			cout << "Wrong input, must be numeric." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input first number: ";
			cin >> number1;
		}

		cout << "Input second number: ";
		cin >> number2;
		while (!cin)
		{
			cout << "Wrong input, must be numeric." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input second number: ";
			cin >> number2;
		}
	}

	else
	{
		cout << "Input first number: ";
		cin >> number1;
		while (!cin)
		{
			cout << "Wrong input, must be numeric." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input the number: ";
			cin >> number1;
		}
	}

	result3 = operationPick(number1, number2, operation);

	string OperationSymbol = operationVisualizer(operation);

	writingIntoFile(number1, number2, result3, operation, OperationSymbol);
	cout << "The result of operation No." << operation << " is " << result3 << endl;
}

void repeatOrExit()
{
	cout << "Would you like to continue? y/n" << endl;
	cin >> answer;
	if (answer == 'y')
	{
		userInput();
		repeatOrExit();
	}
	else
	{
		exit(0);
	}
}

void main()
{
	operationGuide();
	while (true) 
	{
		userInput();
		repeatOrExit();
	}
}