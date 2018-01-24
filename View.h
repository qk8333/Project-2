#pragma once
#include <windows.h> //Interact with Windows OS. For mouse events.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple> //For std::tie

enum GameState { PLAY, END }; //For polling loop or other spinlock structure.

class View {
	//Dimensions of the grid itself.
	int width;
	int height;
	//Vector for the actual grid of the game board itself.
	const std::vector<std::pair<int,int>> grid;
	//List of actual solutions for the particular puzzle.
	static std::vector<std::pair<int, int>> answers;
	//For the individual user input for a given coordinate point.
	std::pair<int, int> value;

	//Allocate answer buffer
	void fillAnswers(std::pair<int, int> &answer);

	//Grid helper
	std::pair<int,int> makeTile(const std::pair<int,int>& tile);
public:
	void draw(int width, int height); //Make grid
	bool getPuzzle(const std::string file); //Open file for puzzle solution
};

std::pair<int,int> makeTile(const std::pair<int, int>& tile) {
	return std::tie<tile.first, tile.second>;
}

void View::draw(int width, int height) {
	int i = 0;
	int j = 0;

	

	for (auto& it : grid) {
		if (i == width)
			std::cout << std::endl;

	}
}
//Helper function to fill the answer vector.
void View::fillAnswers(std::pair<int, int> &answer) {
	answers.push_back(answer);
}

bool View::getPuzzle(const std::string file) {
	std::ifstream solutionFile(file);

	std::vector<std::pair<int, int>> grid;

	//File does not exist or cannot be opened.
	if (!solutionFile)
		return false;

	int i, j; //Iterators to capture int values in file.
	std::pair<int, int> answer; //<-- Individual pair value.
	
	while (solutionFile >> i >> j) {
		answer.first = i;
		answer.second = j;

		std::cout << "i is: " << answer.first << "\n";
		std::cout << "j is: " << answer.second << "\n";

		fillAnswers(answer);

		std::cout << answers.size() << std::endl;
	}

	solutionFile.close();
	return true;
}