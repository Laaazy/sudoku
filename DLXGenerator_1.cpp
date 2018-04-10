#include "DLXGenerator_1.h"

//加入一行空链表
vector<ColumnHead_1 *> DLXGenerator_1::createColumnHeads(DLXNode_1 *listHead, int length) 
{
	vector<ColumnHead_1*> columnHeads;
	columnHeads.resize(length);
	DLXNode_1 *lastNode = listHead;

	for (int i = 0; i < length; ++i) 
	{
		ColumnHead_1 *columnHead = new ColumnHead_1(i);
		lastNode->appendRightNode(columnHead);
		columnHeads[i] = columnHead;
		lastNode = columnHead;
	}

	lastNode->appendRightNode(listHead);
	return columnHeads;
}

//加入一行元素
void DLXGenerator_1::appendLine(vector<ColumnHead_1*> columnHeads, vector<int> elementSubscripts, int rowIndex) {
	CommonNode_1 *lastHorizontalNode = NULL;
	CommonNode_1 *firstHorizontalNode = NULL;

	for (unsigned int i = 0; i < elementSubscripts.size(); ++i) {
		int subscript = elementSubscripts[i];
		ColumnHead_1 *columnHead = columnHeads[subscript];
		CommonNode_1 *currentNode = new CommonNode_1(rowIndex, columnHead);
		DLXNode_1 *lastVerticalNode = columnHead->upNode;

		//Link vertical nodes
		lastVerticalNode->appendDownNode(currentNode);
		currentNode->appendDownNode(columnHead);

		//Link horizontal nodes
		if (i == 0) {
			firstHorizontalNode = currentNode;
			lastHorizontalNode = currentNode;
		}
		else {
			lastHorizontalNode->appendRightNode(currentNode);
			lastHorizontalNode = currentNode;
		}

		currentNode->columnIndex = columnHead->columnIndex;
		columnHead->numberOfOne++;
	}

	lastHorizontalNode->appendRightNode(firstHorizontalNode);
}
