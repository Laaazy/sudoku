#include"sudokuloader_1.h"
#include<sstream>
#include<stdlib.h>

#define sudokusize 81
#define sudokulength 9

//从特定文件将数独装载入向量
vector<vector<int>> SudokuLoader::loadFromFile(fstream& file)
{
	vector<vector<int>> sudokuset;
	stringstream buffer;
	string content = "";
	buffer << file.rdbuf();
	content = buffer.str();

	//擦除content中的空格和回车
	int i = 0;
	while (i < content.size()) 
	{
		if (content[i] == ' ' || content[i] == '\n') 
		{
			content.erase(i, 1);//删除从i开始的1个字符
			continue;
		}
		i++;
	}

	//生成sudoku向量
	for (int j = 0, k = 0; j < content.size(); ++j)
	{
		int sudokuindex = j / sudokusize;//已生成数独个数,数独指针

		if (j % sudokusize == 0) 
		{ //插入一个空数独在二维数独结尾
			vector<int> newsudoku;
			newsudoku.resize(sudokusize);//修改容器大小为sudokusize
			k = 0;//k指针重新指向新数独开头
			sudokuset.push_back(newsudoku);
		}

		sudokuset[sudokuindex][k++] = content[j] - '0';
	}

	return sudokuset;
}

//将sudokuset保存至文件
void SudokuLoader::writeToFile(vector<vector<int>>& sudokuset, fstream& file) 
{
	int sudokucount = sudokuset.size();
	for (int i = 0; i < sudokucount; ++i)//循环处理每个数独
	{ 
		char content[19 * 9 + 2];
		int contentindex = 0;

		for (int j = 0, k = 0; j < sudokusize; ++j, ++k) 
		{ 
			if (k != 0) 
			{
				content[contentindex] = ' ';
				contentindex++;
			}
			content[contentindex] = sudokuset[i][j] + '0';
			contentindex++;

			if (k == sudokulength - 1)//一行完毕
			{
				content[contentindex] = '\n'; //insert return to each end of row
				contentindex++;
				k = -1;
			}
		}
		content[contentindex] = '\n'; //每个数独末尾额外增加空行
		contentindex++;

		content[contentindex] = '\0';//设置结尾标志
		file << content;//保存至文件
	}
}
