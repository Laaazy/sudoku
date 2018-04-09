#pragma once
#include<vector>
#include "DLXGenerator_1.h"
#include "SudokuSolver_1.h"

using namespace std;

class SudokuGenerator_1
{
public:
	vector<vector<int>> generateSudokus(int sudokuCount);
};
