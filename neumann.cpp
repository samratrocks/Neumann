#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <string>

/**********************************************
Function prototypes
*********************************************/
int prompt();	// Shows the main prompt


using namespace std;
int main() {
	cout 	<< ">>>    	Welcome to Neumann \n"
			<< ">>> 	Please enter you program below after the ?\n"
			<< ">>> 	You can either enter an instruction\n"
			<< ">>> 	one a time or enter a data byte.\n";

	// TODO: Write a function that displays the prompt
	// TODO: Push the operands into an array


	prompt();
	return 0;
}

/* 
* Shows the user a prompt where they can enter
* instructions that they want to execute.
* This function simply calls other functions
* based on the operation
*/
int prompt() {
	string currentInstruction = "";
	string operation = "";
	string operand = "";
	int currentLine = 0;
	
	
	while (currentInstruction != "9999") {
		// 9999 is the command to quit I
		// Displays the prommpt like this "[0]:" 
		cout << "[" << currentLine << "]: ";
		
		cin >> currentInstruction; 
		if (currentInstruction.length() != 4) {
			cout << "Instructions can only be 4 letters long!\nHALTING!\n";
			return 1;
		}
		
		// Split the first two letters and assign that to operation key
		// Split the remaining two and assign that to operand 
		operation 	= currentInstruction.substr(0,2);
		operand 	= currentInstruction.substr(2,2);
		cout << operation << endl;
		cout << operand << endl;
		
		
		currentLine++;
	}
	
	
	// User pressed 9999 thus is done writing instructions!
	// Time to execute now!
	
	
	return 0;
}

