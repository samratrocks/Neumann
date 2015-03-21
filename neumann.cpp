#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <string>


using namespace std;
/**********************************************
Function prototypes
*********************************************/
	// Shows the main prompt
int read(string operand);
int write(string operand);
int load(string operand);
int store(string operand);
int add(string operand);
int subtract(string operand);
int divide(string operand);
int multiply(string operand);
int prompt();


int main() {
	cout 	<< ">>>    	Welcome to Neumann \n"
		<< ">>> 	Please enter you program below after the ?\n"
			<< ">>> 	You can either enter an instruction\n"
				<< ">>> 	one a time or enter a data byte.\n";

	// DONE: Write a function that displays the prompt
	// TODO: Implement the master array!


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
	int operationNumeric;		// int conversion of operation for swtich statement
	
	
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
		
		
		currentLine++;
	}
	
	operationNumeric = atoi(operation.c_str());
	cout << operationNumeric << endl;
	/************************************************************
	*************************************************************
	WARNING! This logic is flawed! What are we currently executing?
	We need to loop over and execute one at a time! Not like this!
	*************************************************************
	*************************************************************/
	
	// User pressed 9999 thus is done writing instructions!
	// Time to execute now!
	switch ( operationNumeric ) {
		case 10:
			read(operand);
			break;
		//
		// case 11:
		// 	write(operand);
		// 	break;
		//
		// case 20:
		// 	load(operand);
		// 	break;
		//
		// case 21:
		// 	store(operand);
		// 	break;
		//
		// case 30:
		// 	add(operand);
		// 	break;
		//
		// case 31:
		// 	subtract(operand);
		// 	break;
		//
		// case 32:
		// 	divide(operand);
		// 	break;
		//
		// case 33:
		// 	multiply(operand);
		// 	break;
		case 99:
			cout << "Quitting!";
			break;
		default:
			// We'll just quit the porgram for now
			cout << "Unknown command, error! Quiting!";
			return 1;
			break;
	}
	
	return 0;
}



/********************************************************
* FUNCTION DECLARATIONS!
*******************************************************/
int read(string operand){
	cout << "Reading!";
	return 0;
}

int write(string operand){
	cout << "Writing!";
	return 0;
}

int load(string operand){
	cout << "Loading!";
	return 0;
}

int store(string operand){
	cout << "Storing!";
	return 0;
}

int add(string operand){
	cout << "Adding!";
	return 0;
}

int subtract(string operand){
	cout << "Subtracting!";
	return 0;
}

int divide(string operand){
	cout << "Dividing!";
	return 0;
}

int multiply(string operand){
	cout << "Multiplying!";
	return 0;
}

