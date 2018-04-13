#include "DLXGenerator_1.h"
#include "DLXSolver_1.h"
#include <vector>

#pragma once

using namespace std;

class SudokuSolver_1 {
public:
	vector<vector<int>> elementSubscriptss; 

											
	void transformToList(vector<int>& sudokuArray, DLXNode_1 *listHead);

	
	bool solveSudoku(DLXNode_1 *listHead, vector<int>& sudoku, vector<int> &answer);

	
	void solveWithMultiAnswers(DLXNode_1* listHead, vector<int>& sudoku, vector<vector<int>>& answers, int answerCount);


	void solutionToAnswer(vector<CommonNode_1*>& solution, vector<int>& answer);

	int indexToRow(int index, int rowLength);

	int indexToColumn(int index, int columnLenghth);

	void appendOneSubscript(vector<vector<int>>& subscriptss, int index, int value);

	int getValue(int index);

	CommonNode_1* getRowHead(CommonNode_1* node);
};
