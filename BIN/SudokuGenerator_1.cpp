#include"SudokuGenerator_1.h"

#define sudokuSize 81

vector<vector<int>> SudokuGenerator_1::generateSudokus(int sudokuCount)
{
	vector<vector<int>> answers;

	//��������������
	vector<int> originalSudoku;
	originalSudoku.assign(sudokuSize, 0);//��81��ֵΪ0��Ԫ�ظ�ֵ��vector����
	originalSudoku[0] = 8; //���Ͻ�Ϊѧ�ź���λ%9+1

	//�������������任�õ��Ϸ������վֶ�ά����
	DLXGenerator_1 generator = DLXGenerator_1();
	DLXNode_1 *listHead = new DLXNode_1();
	SudokuSolver_1 solver = SudokuSolver_1();
	solver.solveWithMultiAnswers(listHead, originalSudoku, answers, sudokuCount);
	return answers;
}