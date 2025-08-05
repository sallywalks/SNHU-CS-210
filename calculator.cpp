/*
 * Calculator.cpp
 *
 *  Date: [7/11/25]
 *  Author: [JoAnn Olney]
 */

#include <iostream>

using namespace std;

int main() //changed void to int
{
	//char statement[100]; //remove this, not used
	int op1, op2;
	char operation;
	char answer='Y'; //added missing semicolon, removed ""
	while (answer=='Y'||answer=='y') //added a statement for capital Y, y
	{
		cout << "Enter expression" <<endl;
		cin >> op2 >> operation >> op1;
		if (operation == '+') {			
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; //">>" used instead of "<<" at op2  //semicolon removed, brackets adeed//changed "" to '' BRS
        }
		if (operation == '-') {	 //semicolon removed brackets added
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; //">>" used instead of "<<" between cout and op1
		}
		if (operation == '*') {	 //brackets added
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; //semicolon added, wrong math symbol was used in cout statement
		}
		if (operation == '/') {	 //brackts added
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //wrong math symbol was used in cout statement
		}

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}
}






