#include<iostream>
#include"SudokuLoader_1.h"
#include"SudokuGenerator_1.h"
#define SudokuMax 1000000

using namespace std;

void reportError() 
{
	cout << "Program argument error" << endl;
}

void solvePuzzle(fstream& puzzleFile) {
	
	SudokuLoader_1 loader = SudokuLoader_1();
	vector<vector<int>> sudokuSet = loader.loadFromFile(puzzleFile);
	int sudokuCount = sudokuSet.size();

	
	vector<vector<int>> answers;
	answers.resize(sudokuCount);

	for (unsigned int j = 0; j < sudokuSet.size(); ++j)
	{
		SudokuSolver_1 solver = SudokuSolver_1();
		DLXNode_1* listHead = new DLXNode_1();
		vector<int> answer;

		if (solver.solveSudoku(listHead, sudokuSet[j], answer)) 
			answers[j] = answer;
		else 
			cout << "No solution for sudoku No." << j + 1 << endl;
	}

	
	fstream solutionFile;
	solutionFile.open("sudoku.txt", ios::out);
	if (answers.size() == 0) {
		cout << "No solutions for all sudokus" << endl;
	}
	else {
		loader.writeToFile(answers, solutionFile);
	}
	solutionFile.close();
}

void createSudoku(fstream& sudokuFile, int sudokuCount)
{
	//����������ά����
	SudokuGenerator_1 generator = SudokuGenerator_1();
	vector<vector<int>> answers = generator.generateSudokus(sudokuCount);


	//��������ά�����������ļ�
	SudokuLoader_1 loader = SudokuLoader_1();
	loader.writeToFile(answers, sudokuFile);
}

int main(int argc, char *argv[])//����������������������������в�������
{
	if (argc != 3)//������������ȷ
	{
		reportError();
		return 0;
	}
	if (strcmp(argv[1], "-c") == 0 && atoi(argv[2]) > 0 && atoi(argv[2]) <= SudokuMax)//���������վ���������������Ϸ� 
	{
		fstream sudokuFile;
		sudokuFile.open("sudoku.txt", ios::out);
		createSudoku(sudokuFile, atoi(argv[2]));
		sudokuFile.close();
	}
	else if (strcmp(argv[1], "-s") == 0)//�����������
	{
		fstream puzzleFile;
		puzzleFile.open(argv[2], ios::in);
		solvePuzzle(puzzleFile);
		puzzleFile.close();
	}
	else
		reportError();
	return 0;
}