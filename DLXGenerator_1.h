#pragma once
#include"DLXNode_1.h"
#include<vector>

using namespace std;

class DLXGenerator_1
{
	vector<ColumnHead_1*> createColumnHeads(DLXNode_1* listHead, int length);

	void appendLine(vector<ColumnHead_1*> columnHeads, vector<int> elementSubscripts, int rowIndex);
};
