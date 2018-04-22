#include "SudokuSolver_1.h"

#define sudokuLength 9
#define sudokuSize 81


bool SudokuSolver_1::solveSudoku(DLXNode_1 *listHead, vector<int> &sudoku, vector<int> &answer) {
	transformToList(sudoku, listHead);
	DLXSolver_1 dlxSolver = DLXSolver_1();
	vector<CommonNode_1*> solution;
	dlxSolver.solveWithOneAnswer(listHead, solution, 0); 

	if (solution.size() != sudokuSize) { 
		return false;
	}

	solutionToAnswer(solution, answer); 
	return true;
}


void SudokuSolver_1::solveWithMultiAnswers(DLXNode_1 *listHead, vector<int>& sudoku, vector<vector<int>>& answers, int answerCount) {
	transformToList(sudoku, listHead);
	DLXSolver_1 dlxSolver = DLXSolver_1();
	vector<CommonNode_1*> tempSolution;
	vector<vector<CommonNode_1*>> lastSolution;
	tempSolution.reserve(sudokuSize);
	lastSolution.reserve(sudokuSize);
	dlxSolver.solveWithCertainAnswers(listHead, tempSolution, lastSolution, answerCount, 0); 

																							 
	answers.resize(answerCount);
	for (int i = 0; i < answerCount; ++i) {
		vector<int> answer;
		solutionToAnswer(lastSolution[i], answer);
		answers[i] = answer;
	}
}


void SudokuSolver_1::solutionToAnswer(vector<CommonNode_1*>& solution, vector<int>& answer) {
	answer.resize(sudokuSize);
	DLXNode_1* lastNode = NULL;
	int solutionIndex;
	int value;
	int rowIndex;

	for (unsigned int i = 0; i < sudokuSize; ++i) { 
		CommonNode_1* rowHead = getRowHead(solution[i]);
		solutionIndex = rowHead->columnIndex; 
		value = getValue(rowHead->rightNode->columnIndex); 
		answer[solutionIndex] = value;
	}
}


void SudokuSolver_1::transformToList(vector<int>& sudokuArray, DLXNode_1 *listHead) {
	
	for (unsigned int j = 0; j < sudokuArray.size(); ++j) {
		int value = sudokuArray[j];
		if (value == 0) { 
			for (int i = 0; i < sudokuLength; ++i) {
				appendOneSubscript(elementSubscriptss, j, i + 1);
			}
			continue;
		}
		else {
			appendOneSubscript(elementSubscriptss, j, value);
		}
	}


	DLXGenerator_1 dlxGenerator = DLXGenerator_1();
	vector<ColumnHead_1*> columnHeads;
	columnHeads = dlxGenerator.createColumnHeads(listHead, sudokuSize * 4);
	unsigned int i;
	for (i = 0; i < elementSubscriptss.size(); ++i) {
		dlxGenerator.appendLine(columnHeads, elementSubscriptss[i], i);
	}
}

int SudokuSolver_1::indexToRow(int index, int rowLength) {
	return index / rowLength;
}

int SudokuSolver_1::indexToColumn(int index, int columnLenghth) {
	return index % columnLenghth;
}


void SudokuSolver_1::appendOneSubscript(vector<vector<int>>& elementSubscriptss, int index, int value) {
	
	int row = indexToRow(index, sudokuLength);
	int column = indexToColumn(index, sudokuLength);
	int block = (row / 3) * 3 + column / 3;
	int rowInfo = sudokuSize + (row * sudokuLength + value - 1); 
	int columnInfo = sudokuSize * 2 + (column * sudokuLength + value - 1);
	int blockInfo = sudokuSize * 3 + (block * sudokuLength + value - 1);

	vector<int>elementSubscripts = { index, rowInfo, columnInfo, blockInfo };
	elementSubscriptss.push_back(elementSubscripts);
}


inline int SudokuSolver_1::getValue(int index) {
	return (((index - sudokuSize) % sudokuLength) + 1);
}

CommonNode_1 * SudokuSolver_1::getRowHead(CommonNode_1 * node)
{
	int columnIndex = node->columnIndex;
	if (columnIndex <= 80) {
		return node;
	}
	else if (columnIndex >= 81 && columnIndex <= 161) {
		return (CommonNode_1*)(node->leftNode);
	}
	else if (columnIndex >= 162 && columnIndex <= 242) {
		return (CommonNode_1*)(node->leftNode->leftNode);
	}
	else if (columnIndex >= 243 && columnIndex <= 323) {
		return (CommonNode_1*)(node->leftNode->leftNode->leftNode);
	}
	else {
		std::cout << "SudokuSolver::getRowHead(): Column index out of bound." << endl;
	}
	return nullptr;
}
