#include<iostream>

#define SudokuMax 1000000

using namespace std;

void reportError() 
{
	cout << "Program argument error" << endl;
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
		;
	}
	else if (strcmp(argv[1], "-s") == 0)//�����������
	{
		;
	}
	else
		reportError();
	return 0;
}