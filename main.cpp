#include<iostream>
#include"SudokuLoader_1.h"
#define SudokuMax 1000000

using namespace std;

void reportError() 
{
	cout << "Program argument error" << endl;
}

void createSudoku(fstream& sudokuFile, int sudokuCount)
{
	//生成数独
	

	//将数独保存至文件
	SudokuLoader loader = SudokuLoader();
	loader.writeToFile();
}

int main(int argc, char *argv[])//命令行启动程序参数个数，命令行参数数组
{
	if (argc != 3)//参数个数不正确
	{
		reportError();
		return 0;
	}
	if (strcmp(argv[1], "-c") == 0 && atoi(argv[2]) > 0 && atoi(argv[2]) <= SudokuMax)//生成数独终局命令，且生成数量合法 
	{
		fstream sudokuFile;
		sudokuFile.open("sudoku.txt", ios::out);
		createSudoku(sudokuFile, atoi(argv[2]));
		sudokuFile.close();
	}
	else if (strcmp(argv[1], "-s") == 0)//求解数独命令
	{
		;
	}
	else
		reportError();
	return 0;
}
