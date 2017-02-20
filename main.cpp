// This is the main.cpp function of the TopSpin program. 
// This program was made by Andrew.
// This program was made on 13/11/2016.
// This program was last modified on 23/11/2016


//Preprocessor Directives
#include "CircularDoublyLinkedList.h"
#include "TopSpin.h"

#include <iostream>
using namespace std;


/*
1.	Creates a TopSpin object of size 20 and spinSize 4.

2.	Asks the user for a number of random moves to initialize the puzzle with.A random move is
defined as shifting left randomly 1 - 19 pieces(consider a shiftLeft that takes a parameter)
followed by a spin.

3.	The user will then be repeatedly shown the puzzle(using cout and our << operator) and given a
menu which asks if they want to : shift, spin, or quit. (hint cin)
*/


void main() {

	//Create a topspin object of size 20.
	//Create a topspin object of size 4.
	//TopSpin board(20, 4);

	//Asks about randomization.
	int randVal = 1;
	int boardSz = 20;
	int spinnerSz = 4;

	cout
		<< "======================== TopSpin ======================" << endl;

	cout << endl << endl;
	cout << "Please enter the board size (enter 20 for Default): ";
	cin >> boardSz;
	cout << endl << endl;
	cout << "Please enter the spinner size (enter 4 for Default): ";
	cin >> spinnerSz;
	cout << endl << endl;
	cout << "Please enter how many radomization you would like: ";
	cin >> randVal;

	TopSpin board(boardSz, spinnerSz);
	board.randomize(randVal);

	//Keeps track of the users choice.
	int choice = 0;

	//Prints out the main values.
	while (choice != 4) {

		system("cls");

		cout
			<< "======================== TopSpin ===================================" << endl
			<< endl
			<< "Please pick an option from the following list: " << endl
			<< endl
			<< "	1. Shift Right" << endl
			<< "	2. Shift Left" << endl
			<< "	3. Spin" << endl
			<< "	4. Quit" << endl
			<< endl
			<< "=====================================================================" << endl
			<< endl
			<< board
			<< endl
			<< "=====================================================================" << endl
			<< endl;
			
		bool stillplaying = true;
		
		cout << "The board is ";
		if (board.isSolved() == true) {

			cout
				<< "NOW SOLVED! Congratulations!"
				<< endl << endl;

		} else if (board.isSolved() == false) {

			cout << "not yet solved. Keep playing..." << endl;

		}


		if (stillplaying == true) {

			cout
				<< endl
				<< "Choice (1-4): ";
			cin >> choice;


			cout << endl << endl;

			if (choice == 1) {

				//Call shift right.
				//How many times would you like to shift it?
				cout << "How many times would you like to shift it Right? ";
				int timeRt = 1;
				cin >> timeRt;

				for (int i = 0; i < timeRt; i++) {
					board.shiftRight();
				}

				//cout << board;

			} else if (choice == 2) {

				//Call shift left.
				//How many times would you like to shift it?
				cout << "How many times would you like to shift it Left? ";
				int timeRt = 1;
				cin >> timeRt;

				for (int i = 0; i < timeRt; i++) {
					board.shiftLeft();
				}

				//cout << board;

			} else if (choice == 3) {

				//Call spin.
				board.spin();
				//cout << board;

			} else if (choice == 4) {
				//Will exit auto. Nothing needed here.
			}

		}//playagain?

	}


	system("PAUSE");


}


