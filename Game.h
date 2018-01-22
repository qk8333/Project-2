//Header to hold game abstract class
#ifndef GAME_H
#define GAME_H 1
#include <string>
using namespace std;

template<typename T>
class Game
{
public:
	virtual Game() = 0;									// Default constructor creates blank game board
	virtual Game(string) = 0;							// Constructor to load file
	virtual int getNumRows() const = 0					// Getter for number of rows
	virtual int getNumCols() const = 0;					// Getter for number of columns
	virtual T getSolution(int, int) const = 0;			// Get solution from point (row, column)
	virtual T getBoard(int, int) const = 0;				// Get current board from point (row, column)
	virtual int getRowKey(int, int) const = 0;			// Get row key value from point
	virtual int getColKey(int, int) const = 0;			// Get column key value from point
	virtual int getRowKeyNum() const = 0;				// Get the length of the key
	virtual int getColKeyNum() const = 0;				// Get the height of the key
	virtual void move(int, int, int) = 0;				// Player move (row, column, (value))
	virtual bool isWin() const = 0;						// Boolean for win conditions
	virtual void createGame(T**, int, int, bool**) = 0;	// To create new game (solution, #rows, #columns, (sudoku hints))
	virtual ~Game() = 0;								// Destructor
};

#endif
