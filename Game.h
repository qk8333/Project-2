#ifndef GAME_H
#define GAME_H 1

#include<fstream>
#include<string>
using namespace std;

// Space struct
// Object to hold an integer and a boolean value corresponding with a row or column
// Note: Call the desired value using the "->" operator after calling the appropriate function
// Note: Some puzzle types may not utilize certain values

struct Space
{
	int integer;
	bool boolean;
};

// Game class (abstract)
// Note: Inputted row and column values go from 0 to n-1 (anything else is out of bounds)

class Game
{
public:
	Game();                                                 // Default constructor: initializes all values to 0 or null
	Game(string) {};                                        // Constructor to load game from file (does nothing in base class)
	Game(Space**, int, int);                                // Constructor to load custom game (only initializes solution, row, and column)
	virtual int getNumRows() const = 0;                     // Getter for the number of rows in puzzle
	virtual int getNumCols() const = 0;                     // Getter for the number of columns in puzzle
	virtual int getRowKeyWidth() const = 0;                 // Getter for the number of columns in the row key (calculated on call)
	virtual int getColKeyHeight() const = 0;                // Getter for the number of tows in the column key (calculated on call)
	virtual int getRowKey(int, int) const = 0;              // Return int from the row key (-1 if out of bounds)
	virtual int getColKey(int, int) const = 0;              // Return int from the column key (-1 if out of bounds)
	virtual Space * getSolution(int, int) const = 0;	// Return Space object from solution (null if out of bounds)
	virtual Space * getBoard(int, int) const = 0;           // Return Space object from board (null if out of bounds)
	virtual bool isWin() const = 0;                         // Boolean function to hold winning conditions (put in while-loop)
	virtual void move(int, int, int) = 0;                   // Modifies the appropriate value when a certain space is invoked
	virtual void createGame(Space**, int, int) = 0;		// Overwrites current game with game of same type (resets board)
	virtual void loadGame(string) = 0;                      // Load game from a .txt file (returns blank game if file DNE)
	virtual ~Game() = 0;                                    // Destructor
protected:
	int numRows, numCols, **rowKey, **colKey;
	Space **solution, **board;
};


// Base virtual functions to be inherited regardless of game type

Game::Game() : numRows(0), numCols(0), rowKey(nullptr), colKey(nullptr), solution(nullptr), board(nullptr) {}

Game::Game(Space **sol, int row, int col) : numRows(row), numCols(col), solution(sol) {}

int Game::getNumRows() const { return numRows; }

int Game::getNumCols() const { return numCols; }

int Game::getRowKey(int row, int col) const { return (row >= getNumRows() || row < 0 || col >= getRowKeyWidth() || col < 0) ? -1 : rowKey[row][col]; }

int Game::getColKey(int row, int col) const { return (row >= getColKeyHeight() || row < 0 || col >= getNumCols() || col < 0) ? -1 : colKey[row][col]; }

Space * Game::getSolution(int row, int col) const { return (row >= getNumRows() || row < 0 || col >= getNumCols() || col < 0) ? nullptr : &solution[row][col]; }

Space * Game::getBoard(int row, int col) const { return (row >= getNumRows() || row < 0 || col >= getNumCols() || col < 0) ? nullptr : &board[row][col]; }

Game::~Game()
{
	for (int i = 0; i < numRows; i++)
	{
		delete[] rowKey[i];
		delete[] solution[i];
		delete[] board[i];
	}
	for (int i = 0; i < getColKeyHeight(); i++) delete[] colKey[i];
}

#endif

