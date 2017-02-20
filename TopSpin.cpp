// This is the TopSpin.cpp class file of the TopSpin program. 
// This program was made by Andrew.
// This program was made on 13/11/2016.
// This program was last modified on 24/11/2016

#include <iostream>
using namespace std;


#include "TopSpin.h"
#include "CircularDoublyLinkedList.h"

#include <stdlib.h>
#include <time.h>

//Default constructor
TopSpin::TopSpin() {

	//Default values.
	int i_boardSize = 20;
	int i_spinnerSize = 5;

	//Check the board and spinner size.
	if (i_boardSize < i_spinnerSize || i_boardSize == 0) {
		//Set everything to default values.
		i_boardSize = 20;
		i_spinnerSize = 5;
	}

	//Define the board with the set values. 
	for (int b = 1; b <= i_boardSize; b++) {
		board.addHead(b);
	}

	//Save the values for later reference.
	boardSize = i_boardSize;
	spinnerSize = i_spinnerSize;

}

//User defined values constructor.
TopSpin::TopSpin(int i_boardSize, int i_spinnerSize) {

	//Check the board and spinner size.
	if (i_boardSize < i_spinnerSize || i_boardSize == 0) {
		//Set everything to default values.
		i_boardSize = 20;
		i_spinnerSize = 4;
	}

	//Define the board with the set values. 
	board.addHead(1);
	for (int b = 2; b <= i_boardSize; b++) {
		board.addTail(b);
	}

	//Save the values for later reference.
	boardSize = i_boardSize;
	spinnerSize = i_spinnerSize;

}

//Default destructor
TopSpin::~TopSpin() {

	//Does nothing...

}

//Will shift everything left by one.
void TopSpin :: shiftLeft() {

	//Shif the left board using CDLL's shift function.
	board.shift(0);

}

//Will shif everything right by one. 
void TopSpin :: shiftRight() {

	//Shif the right board using CDLL's shift function.
	board.shift(1);

}

//Will spin the section of the board.
void TopSpin :: spin() {

	//We have already checked to make sure that the board is the right size compared to the spinner.
	//Simple copy and reverse procedure, or swap function. Lets start from the 1st postition of the linked list. 

	for (int i = 1; i <= spinnerSize/2; i++) {

		//Swap them.
		int a = board.retrieve(i);
		int b = board.retrieve(spinnerSize+1-i);
		board.replace(spinnerSize+1-i, a);
		board.replace(i, b);

	}


}

//Will check to see of the board is solved?
bool TopSpin :: isSolved() {

	/*
	//To make this ease, the linked list will move forwards or backwards.

	//Get the current value of the LL @ i=1; Like counter = 3;
	//The roll counter will be whatever the value the node has @ i = 1;
	int rollCounter = board.retrieve(1);
	for (int i = rollCounter; i <= boardSize; i++) {

		if (i != board.retrieve(i)) {
			return false;
		}

		if (rollCounter == boardSize) {
			for (int j = 1; j < rollCounter; j++) {
				if (j != board.retrieve(j)) {
					return false;
				}
			}
		}
		return true;
	}
	*/

	//Now looks for any order of the numbers.
	//We have to find 1 in the list...
		//Then loop through the list and make sure each element is in order.
		
	int check = 0;

	//Try to find the first element. Once found, save index.
	for (int i = 1; i <= boardSize; i++) {
		//look for first element. 
		if (board.retrieve(i) == 1)
			check = i;
	}

	//Now check the variables going around to see if one is greater than the other.
	for (int x = check; x < check+boardSize-1; x++) {
		int a = board.retrieve(x);
		int b = board.retrieve(x+1);

		if (a>b) {
			return false;
		}

	}

	return true;

}

//Will provide public access to the size of board.
int TopSpin :: getBoardSize() const {

	return boardSize;

}

//Will provide public asccess to the size of the spinner.
int TopSpin :: getSpinnerSize() const {

	return spinnerSize;


}

//Will randomize the board.
void TopSpin :: randomize(int times) {

	//Seed the random function.
	srand(time(NULL));

	while (times != 0) {

		//Generate a random number between 1 and max boardsize.
		int randNum = rand() % getBoardSize() + 1;

		//Commenting out - It's a cool feature, but not what the program wants.
		/*
		//If the random number is even, shift right.
		if (randNum % 2 == 0) {

			for (int i = 0; i < randNum; i++) {
				shiftRight();
			}

		//If the random number is odd, shift left.
		} else if (randNum % 2 != 0) {
			
			
			for (int i = 0; i < randNum; i++) {
				shiftLeft();
			}

		}
		*/

		//Shift the numbers left depending on the random number.
		for (int i = 0; i < randNum; i++) {
			shiftLeft();
		}


		times--;

		//First do the shift. Then followed by the spin...
		spin();

	}


}

