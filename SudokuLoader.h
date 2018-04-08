#pragma once
#include "math.h"
#include <fstream>
#include <vector>

using namespace std;

class SudokuLoader
{
public:
	vector<vector<int>> loadFromFile(fstream& file);
	void writeToFile(vector<vector<int>>& sudokuSet, fstream& file);
};
