#ifndef PICROSS_H
#define PICROSS_H 1
#include <string>
#include "Game.h"
using namespace std;

class Picross : public Game<bool>
{
public:
	Picross() : numRows(0), numCols(0), solution(nullptr), board(nullptr), rowKey(nullptr), colKey(nullptr) {}
	Picross(string);
	int getNumRows() const {return numRows;}
	int getNumCols() const {return numCols;}
	bool getSolution(int, int) const;
	bool getBoard(int, int) const;
	int getRowKey(int, int) const;
	int getColKey(int, int) const;
	int getRowKeyNum() const {return ((numRows % 2 == 1) ? (numRows + 1) / 2 : numRows / 2);}
	int getColKeyNum() const {return ((numCols % 2 == 1) ? (numCols + 1) / 2 : numCols / 2);}
	void move(int, int);
	bool isWin() const;
	void createGame(bool**, int, int, bool** locked = nullptr);
	~Picross();
private:
	int numRows, numCols;
	bool** solution;
	int** board;
	int** rowKey;
	int** colKey;
	void createKeys();
};

Picross::Picross(string filename)
{
	ifstream file;
	file.open(filename);
	if (!file.good()) Picross();
	else
	{
		file >> numRows;
		file >> numColumns;
		solution = new bool*[numRows];
		for (int row = 0; row < numRows; row++)
		{
			solution[row] = new bool[numColumns];
			for (int column = 0; column < numColumns; column++)
			{
				solution[row][column] = false;
			}
		}
		int row, col;
		while (!file.eof())
		{
			file >> row;
			file >> col;
			solution[row - 1][col - 1] = true;
		}
		file.close();
		createKeys();
	}
}

bool Picross::getSolution(int r, int c) const
{
	if (r < 0 || r >= numRows || c < 0 || c >= numCols) return false;
	else return solution[r][c];
}

bool Picross::getBoard(int r, int c) const
{
	if (r < 0 || r >= numRows || c < 0 || c >= numCols) return false;
	else return board[r][c];
}

int Picross::getRowKey(int r, int c) const
{
	if (r < 0 || r >= getRowKeyNum() || c < 0 || c >= numCols) return -1;
	else return board[r][c];
}

int Picross::getColKey(int r, int c) const
{
	if (r < 0 || r >= numRows || c < 0 || c >= getColKeyNum()) return -1;
	else return board[r][c];
}

void Picross::move(int r, int c)
{
	if (r < 0 || r >= numRows || c < 0 || c >= numCols) return;
	else board[r][c] = !board[r][c];
}

bool Picross::isWin() const
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (board[i][j] == solution[i][j]);
			else return false;
		}
	}
	return true;
}

void Picross::createGame(bool** sol, int r, int c, bool** locked = nullptr) : solution(sol), numRows(r), numCols(c)
{
	board = new bool*[getNumRows()];
	for (int i = 0; i < getNumRows(); i++)
	{
		board[i] = new bool[getNumCols()];
		for (int j = 0; j < getNumCols(); j++) board[i][j] = false;
	}
	createKeys();
}

Picross::~Picross()
{
	for (int i = 0; i < numRows; i++)
	{
		delete[] solution[i];
		delete[] rowKey[i];
		delete[] board[i];
	}
	for (int i = 0; i < getColKeyNum(); i++) delete[] colKey[i];
}

void Picross::createKeys()
{
	int** rowKey = new int*[numRows];
	for (int i = 0; i < numRows; i++)
	{
		rowKey[i] = new int[getRowKeyNum()];
		for (int j = 0; j < getRowKeyNum(); j++)
		{
			rowKey[i][j] = 0;
		}
	}
	int** colKey = new int*[getColKeyNum()];
	for (int i = 0; i < getColKeyNum(); i++)
	{
		colKey[i] = new int[numCols];
		for (int j = 0; j < numCols; j++)
		{
			colKey[i][j] = 0;
		}
	}
	for (int i = numRows - 1; i >= 0; i--)
	{
		int digit = getRowKeyNum() - 1;
		for (int j = numCols - 1; j >= 0; j--)
		{
			if (!solution[i][j] && rowKey[i][digit] > 0) digit--;
			else if (!solution[i][j]); // skip
			else rowKey[i][digit]++;
		}
	}

	for (int i = numCols - 1; i >= 0; i--)
	{
		int digit = getColKeyNum() - 1;
		for (int j = numRows - 1; j >= 0; j--)
		{
			if (!solution[j][i] && colKey[digit][i] > 0) digit--;
			else if (!solution[j][i]); // skip
			else colKey[digit][i]++;
		}
	}
}

#endif
