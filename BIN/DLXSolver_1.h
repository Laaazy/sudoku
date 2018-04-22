#pragma once
#include <iostream>
#include <vector>
#include "DLXNode_1.h"

using namespace std;

class DLXSolver_1
{
public:
	//得到一种解
	bool solveWithOneAnswer(DLXNode_1 *listHead, vector<CommonNode_1*>& solution, int depth);

	//得到所有解
	void solveWithAllAnswers(DLXNode_1 *listHead, vector<CommonNode_1*>& tempSolution, vector<vector<CommonNode_1*>>& lastSolution, int depth);

	//得到某一数量的解
	void solveWithCertainAnswers(DLXNode_1 *listHead, vector<CommonNode_1*> &tempSolution, vector<vector<CommonNode_1*>> &lastSolution,
		int answerCount, int depth);

	//覆盖某一列
	void cover(ColumnHead_1* columnHead);

	//暴露某一列
	void uncover(ColumnHead_1* columnHead);

	//选择1最少的一列
	ColumnHead_1* selectColumn(DLXNode_1* listHead);
};