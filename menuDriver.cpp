#include <iostream>
#include <string>
#include <fstream>
#include "menu.h"
using namespace std;

void introduction(menuSys a)
{
	char basic;
	cout << "Welcome to the AOS interactive menu! Would you like to play a game? (Y/N)" << endl;
	cin >> basic;
	switch (basic)
	{
	case 'Y':
		cout << endl << "Great! What game would you like to play?" << endl;
		break;
	case 'N':
		cout << endl << ".......Then why are you here? Wierdo." << endl;
		a.~menuSys;
		break;
	default:
		cout << endl << "...Please learn common courtesy before spending my time. Good bye." << endl;
		a.~menuSys;
	}
};



int main()
{



	return 0;
};
