#pragma once
#include <iostream>
#include <vector>
#include "DLXNode_1.h"

using namespace std;

class DLXSolver_1
{
public:
	//�õ�һ�ֽ�
	bool solveWithOneAnswer(DLXNode_1 *listHead, vector<CommonNode_1*>& solution, int depth);

	//�õ����н�
	void solveWithAllAnswers(DLXNode_1 *listHead, vector<CommonNode_1*>& tempSolution, vector<vector<CommonNode_1*>>& lastSolution, int depth);

	//�õ�ĳһ�����Ľ�
	void solveWithCertainAnswers(DLXNode_1 *listHead, vector<CommonNode_1*> &tempSolution, vector<vector<CommonNode_1*>> &lastSolution,
		int answerCount, int depth);

	//����ĳһ��
	void cover(ColumnHead_1* columnHead);

	//��¶ĳһ��
	void uncover(ColumnHead_1* columnHead);

	//ѡ��1���ٵ�һ��
	ColumnHead_1* selectColumn(DLXNode_1* listHead);
};