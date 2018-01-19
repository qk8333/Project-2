#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include"menu.h"
#include"nonogram.h"
using namespace std;

int main(){
	
	menu menu;			//declare out menu
	menu.menuSys();			//call the constructor
	while(menu.isPlaying()){	//so long as the user wants to play our game we stay here
		//now we are at level one, asking the user what they would like to do to start
		//besides exit, their option is to select a game
		
		//now we are at level two
		//besides exit, their option is to select a puzzle file
		//they may specify a puzzle file, or default to a default puzzle
		
		//now we are at level three: playing the game
		//their options are to make a move, or open a userMenu
		
		//userMenu level
		//their options are to exit the game, or request help
		//if possible we can add a function later to return to clear the puzzle and level one
 	}
	return 0;
}
