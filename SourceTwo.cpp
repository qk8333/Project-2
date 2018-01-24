#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include"Menu.h"
#include"Picross.h"
using namespace std;

int main(){
	
	Menu* menu = new Menu();			//This should already call out the constructor
	/*
	menu.menuSys();			//constructor should already be called in declaration
	*/
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



/*
Tarin is brainstorming down here
while menu.isPlaying()
	if start menu
		welcome to our game!
		please select a puzzle
		
	if game selected
		would you like to load a game?
		load hte user's game into memory
		
	if game being played
		print the puzzle out		
	
	input << cin
	
	if input is exit, exit
	if input is a valid move AND game being played, push move to program
	if input is help, print instructions
	if input is a menu selection AND valid menu is up, update flags

*/
