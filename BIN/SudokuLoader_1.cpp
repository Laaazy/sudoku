#include"Sudokuloader_1.h"
#include<sstream>
#include<stdlib.h>

#define sudokuSize 81
#define sudokuLength 9

//���ض��ļ�������װ��������
vector<vector<int>> SudokuLoader_1::loadFromFile(fstream& file)
{
	vector<vector<int>> sudokuset;
	stringstream buffer;
	string content = "";
	buffer << file.rdbuf();
	content = buffer.str();

	//����content�еĿո�ͻس�
	int i = 0;
	while (i < content.size()) 
	{
		if (content[i] == ' ' || content[i] == '\n') 
		{
			content.erase(i, 1);//ɾ����i��ʼ��1���ַ�
			continue;
		}
		i++;
	}

	//����sudoku����
	for (int j = 0, k = 0; j < content.size(); ++j)
	{
		int sudokuindex = j / sudokuSize;//��������������,����ָ��

		if (j % sudokuSize == 0) 
		{ //����һ���������ڶ�ά������β
			vector<int> newsudoku;
			newsudoku.resize(sudokuSize);//�޸�������СΪsudokusize
			k = 0;//kָ������ָ����������ͷ
			sudokuset.push_back(newsudoku);
		}

		sudokuset[sudokuindex][k++] = content[j] - '0';
	}

	return sudokuset;
}

//����ά��������sudokuset�������ļ�
void SudokuLoader_1::writeToFile(vector<vector<int>>& sudokuset, fstream& file) 
{
	int sudokucount = sudokuset.size();
	for (int i = 0; i < sudokucount; ++i)//ѭ������ÿ������
	{ 
		char content[19 * 9 + 2];
		int contentindex = 0;

		for (int j = 0, k = 0; j < sudokuSize; ++j, ++k) 
		{ 
			if (k != 0) 
			{
				content[contentindex] = ' ';
				contentindex++;
			}
			content[contentindex] = sudokuset[i][j] + '0';
			contentindex++;

			if (k == sudokuLength - 1)//һ�����
			{
				content[contentindex] = '\n'; //��ĩ��ӻس�
				contentindex++;
				k = -1;
			}
		}
		content[contentindex] = '\n'; //ÿ������ĩβ�������ӿ���
		contentindex++;

		content[contentindex] = '\0';//���ý�β��־
		file << content;//�������ļ�
	}
}