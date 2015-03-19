#include <iostream>

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
	// How to ge the line number this is currently on?
	// should it be passed as a parameter or should there
	// be another loop controlling this?
	int currentInstruction = 0;
	int currentLine = 0;
	while (currentInstruction != -9999) {
		// Displays the prommpt like this "[0]:" 
		cout << "[" << currentLine << "]: ";
		
		cin >> currentInstruction;
		currentLine++;
	}
	
	return 0;
}

