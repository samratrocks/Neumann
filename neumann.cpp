#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <string>


using namespace std;
/**********************************************
Function prototypes
*********************************************/
// Shows the main prompt
int read(string operand, int mainStack[]);
int write(string operand, int mainStack[]);
int load(string operand, int mainStack[], int accumulator);
int store(string operand, int mainStack[], int accumulator);
int add(string operand, int mainStack[], int accumulator);
int subtract(string operand, int mainStack[], int accumulator);
int divide(string operand, int mainStack[], int accumulator);
int multiply(string operand, int mainStack[], int accumulator);


int prompt();
void dump();


// This is the main stack that contains all the data
int mainStack[100];

// This is the A register in the CPU
int accumulator; 



int main() {
	cout 		<< ">>>    	Welcome to Neumann \n"
				<< ">>> 	Please enter you program below after the ?\n"
				<< ">>> 	You can either enter an instruction\n"
				<< ">>> 	one a time or enter a data byte.\n";

	// DONE: Write a function that displays the prompt
	// DONE: Implement the master array!
	// TODO: Write out the Program Design Document
	// TODO: Add a dump function that dumps the contetnts of the array

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
	int operationNumeric;		// int conversion of operation for switch statement
	
	
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
	/**************************************************************************
	***************************************************************************
	Updates: Added the functions to load and add string to the memory.
	Updates: Need to write out the design of the program.
	***************************************************************************
	***************************************************************************/
	
	// User pressed 9999 thus is done writing instructions!
	// Time to execute now!
	switch ( operationNumeric ) {
		case 10:
		read(operand, mainStack);
			break;

		case 11:
		write(operand, mainStack);
			break;
		case 20:
		load(operand, mainStack, accumulator);
		break;

		case 21:
		store(operand, mainStack, accumulator);
		break;

		case 30:
		add(operand, mainStack, accumulator);
		break;

		case 31:
		subtract(operand, mainStack, accumulator);
		break;

		case 32:
		divide(operand, mainStack, accumulator);
		break;

		case 33:
		multiply(operand, mainStack, accumulator);
		break;
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
int read(string operand, int mainStack[]){
	int address = atoi(operand.c_str());	// convert the address from string to integer
	int userInput = 0;
	cin >> userInput;
	mainStack[address] = userInput; 
	return 0;
}

int write(string operand, int mainStack[]){
	int address = atoi(operand.c_str());	// convert the address from string to integer
	cout << mainStack[address];
	return 0;
}

int load(string operand, int mainStack[], int accumulator){
	// Load takes the given address and stores the data in that location
	// in the memory to the A register
	int address = atoi(operand.c_str()); 	// convert the address from string to integer
	accumulator = mainStack[address];
	return 0;
}

int store(string operand, int mainStack[], int accumulator){
	// Store a word from the memory into the accumulator
	int address = atoi(operand.c_str());
	mainStack[address] = accumulator;
	return 0;
}

int add(string operand, int mainStack[], int accumulator){
	// Add the value in the given address into the accumulator
	// and leave the result there
	int address = atoi(operand.c_str());
	mainStack[address] += accumulator;
	return 0;
}

int subtract(string operand, int mainStack[], int accumulator){
	// Subtract the value in the given address into the accumulator
	// and leave the result there 
	int address = atoi(operand.c_str());
	int value = accumulator - mainStack[address];
	accumulator = value;
	return 0;
}

int divide(string operand, int mainStack[], int accumulator){
	/*** Possible source of bug ***/
	// What is it supposed to be ?
	// acc / stack or stack / acc ??
	int address = atoi(operand.c_str());
	int value = accumulator / mainStack[address];
	accumulator = value;
	return 0;
}

int multiply(string operand, int mainStack[], int accumulator){
	int address = atoi(operand.c_str());
	int value = accumulator * mainStack[address];
	accumulator = value;
	return 0;
}

