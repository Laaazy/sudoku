//#include "SudokuGenerator.h"
//
//#define sudokuSize 81
//
//vector<vector<int>> SudokuGenerator::generateSudokus(int sudokuCount) {
//	vector<vector<int>> answers;
//
//	//Create an sudoku with all zero except the first block
//	vector<int> originalSudoku;
//	originalSudoku.assign(sudokuSize, 0);//将81个值为0的元素赋值给vector向量
//	originalSudoku[0] = 5; //The first one must be 5
//
//						   //Solve the zero sudoku to get sudoku outcomes
//	DLXGenerator generator = DLXGenerator();
//	DLXNode* listHead = new DLXNode();
//	SudokuSolver solver = SudokuSolver();
//	solver.solveWithMultiAnswers(listHead, originalSudoku, answers, sudokuCount);
//	return answers;
//}