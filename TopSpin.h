#pragma once
// This is the TopSpin.h header file of the TopSpin program. 
// This program was made by Andrew.
// This program was made on 13/11/2016.
// This program was last modified on 24/11/2016

#include "CircularDoublyLinkedList.h"

#include <string>
#include <iostream>
using namespace std;

class TopSpinADT {

public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1 - 20
	virtual bool isSolved() = 0;

	//Do i need to declare this? It's not being recognized below.
	//std::ostream& operator<< (std::ostream& os, const TopSpin& ts);

};

class TopSpin : public TopSpinADT {
	
private:
	int boardSize;
	int spinnerSize;

public:
	//Default constructor
	TopSpin();

	//User defined constructor.
	TopSpin(int i_boardSize, int i_spinnerSize);
	
	//Default destructor
	~TopSpin();

	//Defnititions of functions.
	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();
	void randomize(int times);

	//Some public access functions.
	int getBoardSize() const;
	int getSpinnerSize() const;

	//Holds the values within the program - and makes it accessable. 
	CDLinkedList<int> board;
	//void printBoard(); - Just use the cout overloader...


};

//Overloads cout to print out the entire board.
inline std::ostream& operator<< (std::ostream &os, const TopSpin &ts) {

	//The purpose of this is to print the entire board.
	//Example output:

	// |--------------|
	// |  1  2  3  4  |  5  6  7  8  9 
	// |--------------|

/*

	//1st Row.
	os << "|";
	for (int x = 0; x <= ts.getSpinnerSize()+1; x++) {
		//3 for every number.
		os << "--";
		//Print out another dash if we have 2 digits.
		if (ts.board.retrieve(x) > 9) {
			os << "-";
		}

	}
	os << "-|\n";

	//2nd Row spinner.
	os << "| ";
	for (int x = 1; x <= ts.getSpinnerSize(); x++) {
		//3 for every number.
		os << ts.board.retrieve(x) << "  ";

	}

	//2nd Row rest of board.
	os << "|  ";
	for (int x = ts.getSpinnerSize() + 1; x <= ts.getBoardSize(); x++) {
		//3 for every number.
		os << ts.board.retrieve(x) << "  ";

	}
	os << "\n";


	//3rd Row.
	os << "|";
	for (int x = 0; x <= ts.getSpinnerSize() + 1; x++) {
		//3 for every number.
		os << "--";
		//Print out another dash if we have 2 digits.
		if (ts.board.retrieve(x) > 9) {
			os << "-";
		}
	}
	os << "-|\n";
	
	*/

	//1st Row.
	os << "|";
	for (int x = 0; x < ts.getSpinnerSize(); x++) {
		//4 for every number.
		os << "----";
	}
	//Start a new line
	os << "|\n";

	//2nd Row spinner.
	os << "|";
	for (int x = 1; x <= ts.getSpinnerSize(); x++) {
		
		os <<" "<< ts.board.retrieve(x);

		if (ts.board.retrieve(x) <= 9) {
			//Print one space
			os << "  ";
		} else {
			//Print two spaces
			os << " ";
		}
	}
	os << "|";


	//2nd Row rest of board.
	os << "  ";
	for (int x = ts.getSpinnerSize() + 1; x <= ts.getBoardSize(); x++) {
		//3 for every number.
		os << ts.board.retrieve(x);

		if (ts.board.retrieve(x) > 9) {
			//Print one space
			os << " ";
		}
		else {
			//Print two spaces
			os << "  ";
		}

	}
	os << "\n";


	//3rd Row.
	os << "|";
	for (int x = 0; x < ts.getSpinnerSize(); x++) {
		//4 for every number.
		os << "----";
	}
	//Start a new line
	os << "|\n";

	return os;
}


