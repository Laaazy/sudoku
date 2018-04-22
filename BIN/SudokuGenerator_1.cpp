#include"SudokuGenerator_1.h"

#define sudokuSize 81

vector<vector<int>> SudokuGenerator_1::generateSudokus(int sudokuCount)
{
	vector<vector<int>> answers;

	//生成零数独向量
	vector<int> originalSudoku;
	originalSudoku.assign(sudokuSize, 0);//将81个值为0的元素赋值给vector向量
	originalSudoku[0] = 8; //左上角为学号后两位%9+1

	//将零数独经过变换得到合法数独终局二维向量
	DLXGenerator_1 generator = DLXGenerator_1();
	DLXNode_1 *listHead = new DLXNode_1();
	SudokuSolver_1 solver = SudokuSolver_1();
	solver.solveWithMultiAnswers(listHead, originalSudoku, answers, sudokuCount);
	return answers;
}