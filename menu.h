#ifndef MENU_H
#define MENU_H 1

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class menuSys	//menu class for user traversal
{
public:
	menuSys();	//standard constructor
	~menuSys();	//standard destructor
	void selectGame();	//sets which game is being played
	void selectPuzzle();	//selects a specific puzzle
	void makeMove();	//makes a move
	void userMenu();	//the user invokes this if they want to open a help menu, or exit the program during a puzzle
	void readString(string a);	//reads a string and acts accordingly
	bool isPlaying(); //checks if the user still wants to play
	bool isWin(); //checks if the game is won
	int getRow();	//passes row for Evan's class functions
	int getColums();	//passes column for Evan's class functions
private:
	bool isPlaying;	//used to track if the user is still wanting to play
	int userMenuType; 	//stores whatever the user types in userMenu
	int game;	//stores game choice
	int choice;	//used to store User choices for switch statements
	int passRow;	//used to pass the row to Evan's classes
	int passColumn;	//used to pass the column to Evan's classes
	string puzzle;	//stores puzzle name
};

menuSys::menuSys()
{
menuSys.selectGame();
menuSys.selectPuzzle();
menuSys.isPlaying=TRUE;
};
menuSys::~menuSys()
{

};

void menuSys::selectGame()
{
	int a;
	cout << "Please pick a number between 1 and 2:" << endl << "1=picross   2=rullo" << endl << "Or type 9 to exit." << endl;

	cin >> a;
	cout << endl;
	switch (a)
	{
	case '1':
		cout << "Cool! You picked Picross!" << endl;
		break;
	case '2':
		cout << "Neat! Rullo Rules!" << endl;
		break;
	case '9':
		cout << "Sorry to see you go, but have a nice day." << endl;
		isPlaying = FALSE;
		break;
	default://change this to either recurse or exit
		cout << "You miscreant! It's Nonograms for you!" << endl;
		a = 1;
		break;
	}
	game = a;
};
void menuSys::selectPuzzle()
{
	cout << "Now, please select a puzzle name: ";
	cin >> puzzle;
	cout << endl << "thanks! you will open " << puzzle << "!" << endl;	
};
void menuSys::readString(string a)
{
	int i=0;
	string buf = a;	
};
void menuSys::makeMove()
{

};
void menuSys::userMenu()
{
	cout << "Hello there. What would you like help with?" << endl;
	cout << "If you would like instructions, type 1. If you would like to exit our game, type 9. Otherwise, type 5 to return to your game." << endl;
	cin >> userMenuType;
	
	switch(userMenuType){
		case '1' :
			//print instructions for the current game type
			if (game = 1){
				cout << "These are Picross rules!" << endl;
			}
			else if (game = 2){
				cout << "These are Rullo rules!" << endl;
			}
			break;
		case '5' : 
			break;
		case '9' : 
			cout << "Sorry to see you go, but have a nice day." << endl;
			isPlaying = FALSE;
			//find some way to force exit the program. a new function?
			std::exit;
			break;
		default :
			break; //yes, this is the same as case 5
	}
};

bool menuSys::isWin()
{

};
bool menuSys::isPlaying()
{
	
};

int menuSys::getRow()
{
	return passRow;	
};
int menuSys::getColumn()
{
	return passColumn;	
};

#endif
