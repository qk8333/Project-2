#ifndef PICROSS_H
#define PICROSS_H 1

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

#include "Game.h"

class Picross : public Game
{
public:
	Picross() : Game() {}
	Picross(string);
	Picross(Space**, int, int);
	virtual int getNumRows() const { return Game::getNumRows(); }
	virtual int getNumCols() const { return Game::getNumCols(); }
	virtual int getRowKeyWidth() const { return ((numCols % 2 == 1) ? (numCols + 1) / 2 : numCols / 2); }
	virtual int getColKeyHeight() const { return ((numRows % 2 == 1) ? (numRows + 1) / 2 : numRows / 2); }
	virtual int getRowKey(int row, int col) const { return Game::getRowKey(row, col); }
	virtual int getColKey(int row, int col) const { return Game::getColKey(row, col); }
	virtual Space * getSolution(int row, int col) const { return Game::getSolution(row, col); }
	virtual Space * getBoard(int row, int col) const { return Game::getBoard(row, col); }
	virtual bool isWin() const;
	virtual void move(int row, int col);
	virtual void createGame(Space**, int, int);
	virtual void loadGame(string);
	virtual ~Picross() { Game::~Game(); }
private:
	void createKeys();
};

Picross::Picross(string filename)
{
	ifstream file;
	file.open(filename);
	if (!file.good()) numRows = 0, numCols = 0, solution = nullptr, board = nullptr, rowKey = nullptr, colKey = nullptr;
	else
	{
		file >> numRows;
		file >> numCols;
		board = new Space*[getNumRows()];
		solution = new Space*[getNumRows()];
		for (int row = 0; row < getNumRows(); row++)
		{
			board[row] = new Space[getNumCols()];
			solution[row] = new Space[getNumCols()];
			for (int col = 0; col < getNumCols(); col++)
			{
				board[row][col].integer = 0;
				board[row][col].boolean = false;
				solution[row][col].integer = 0;
				solution[row][col].boolean = false;
			}
		}
		int row, col;
		while (!file.eof())
		{
			file >> row;
			file >> col;
			solution[row][col].boolean = true;
		}
		createKeys();
	}
	file.close();
}

Picross::Picross(Space **sol, int row, int col) : Game(sol, row, col)
{
	board = new Space*[getNumRows()];
	for (int i = 0; i < getNumRows(); i++)
	{
		board[i] = new Space[getNumCols()];
		for (int j = 0; j < getNumCols(); j++)
		{
			board[i][j].integer = 0;
			board[i][j].boolean = false;
		}
	}
	createKeys();
}

bool Picross::isWin() const
{
	for (int row = 0; row < getNumRows(); row++)
	{
		for (int col = 0; col < getNumCols(); col++)
		{
			if (board[row][col].boolean != solution[row][col].boolean) return false; else;
		}
	}
	return true;
}

void Picross::move(int row, int col)
{
	if (row < 0 || row >= getNumRows() || col < 0 || col >= getNumCols()) return;
	else board[row][col].boolean = !board[row][col].boolean;
}

void Picross::createGame(Space** sol, int row, int col)
{
	for (int i = 0; i < numRows; i++)
	{
		delete[] rowKey[i];
		delete[] solution[i];
		delete[] board[i];
	}
	for (int i = 0; i < getColKeyHeight(); i++) delete[] colKey[i];
	solution = sol, numRows = row, numCols = col;
	board = new Space*[getNumRows()];
	for (int i = 0; i < getNumRows(); i++)
	{
		board[i] = new Space[getNumCols()];
		for (int j = 0; j < getNumCols(); j++)
		{
			board[i][j].integer = 0;
			board[i][j].boolean = false;
		}
	}
	createKeys();
}

void Picross::loadGame(string filename)
{
	ifstream file;
	file.open(filename);
	if (!file.good()) return;
	else
	{
		file >> numRows;
		file >> numCols;
		board = new Space*[getNumRows()];
		solution = new Space*[getNumRows()];
		for (int row = 0; row < getNumRows(); row++)
		{
			board[row] = new Space[getNumCols()];
			solution[row] = new Space[getNumCols()];
			for (int col = 0; col < getNumCols(); col++)
			{
				board[row][col].integer = 0;
				board[row][col].boolean = false;
				solution[row][col].integer = 0;
				solution[row][col].boolean = false;
			}
		}
		int row, col;
		while (!file.eof())
		{
			file >> row;
			file >> col;
			solution[row][col].boolean = true;
		}
		createKeys();
		file.close();
	}
}

void Picross::createKeys()
{
	rowKey = new int*[getNumRows()];
	for (int i = 0; i < getNumRows(); i++)
	{
		rowKey[i] = new int[getRowKeyWidth()];
		for (int j = 0; j < getRowKeyWidth(); j++) rowKey[i][j] = 0;
	}
	colKey = new int*[getColKeyHeight()];
	for (int i = 0; i < getColKeyHeight(); i++)
	{
		colKey[i] = new int[getNumCols()];
		for (int j = 0; j < getNumCols(); j++) colKey[i][j] = 0;
	}
	for (int i = getNumRows() - 1; i >= 0; i--)
	{
		int temp = getRowKeyWidth() - 1;
		for (int j = getNumCols() - 1; j >= 0; j--)
		{
			if (!solution[i][j].boolean && rowKey[i][temp] > 0) temp--;
			else if (!solution[i][j].boolean);
			else rowKey[i][temp]++;
		}
	}
	for (int i = getNumCols() - 1; i >= 0; i--)
	{
		int temp = getColKeyHeight() - 1;
		for (int j = getNumRows() - 1; j >= 0; j--)
		{
			if (!solution[j][i].boolean && colKey[temp][i] > 0) temp--;
			else if (!solution[j][i].boolean);
			else colKey[temp][i]++;
		}
	}
}

#endif
