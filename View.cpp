#include "View.h"

std::vector<std::pair<int, int>> View::answers;

int main() {

	View test;

	if (!test.getPuzzle("C:\\Users\\John\\Desktop\\puzzleTest.txt"))
		return -1;
		
	test.draw(10, 10);

	system("pause");
	return 0;
}