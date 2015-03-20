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
	// TODO:


	prompt();
	return 0;
}

/* 
* Shows the user a prompt where they can enter
* instructions that tehy want to execute.
*/
int prompt() {
	string currentInstruction = "";
	string operation = "";
	string operand = "";
	int currentLine = 0;
	
	
	while (currentInstruction != "-9999") {
		// Displays the prommpt like this "[0]:" 
		cout << "[" << currentLine << "]: ";
		
		cin >> currentInstruction; 
		if (currentInstruction.length() != 4) {
			cout << "Unknown instruction!\nHALTING!\n";
			return 1;
		}
		
		//operation 
		
		currentLine++;
	}
	
	return 0;
}

