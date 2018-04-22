#include "DLXGenerator_1.h"

//加入一行空链表
vector<ColumnHead_1 *> DLXGenerator_1::createColumnHeads(DLXNode_1 *listHead, int length) 
{
	vector<ColumnHead_1*> columnHeads;
	columnHeads.resize(length);
	DLXNode_1 *lastNode = listHead;

	for (int i = 0; i < length; ++i) 
	{
		ColumnHead_1 *columnHead = new ColumnHead_1(i);//i是构造函数参数，赋予ColumnHead列号
		lastNode->appendRightNode(columnHead);
		columnHeads[i] = columnHead;//将当前列头保存至列头数组
		lastNode = columnHead;//更新lastNode
	}

	lastNode->appendRightNode(listHead);//构成循环链表
	return columnHeads;
}

//加入一行元素
void DLXGenerator_1::appendLine(vector<ColumnHead_1*> columnHeads, vector<int> elementSubscripts, int rowIndex) 
{
	CommonNode_1 *lastHorizontalNode = NULL;
	CommonNode_1 *firstHorizontalNode = NULL;

	for (int i = 0; i < elementSubscripts.size(); ++i) 
	{
		int subscript = elementSubscripts[i];
		ColumnHead_1 *columnHead = columnHeads[subscript];//此处有不确定改动
		CommonNode_1 *currentNode = new CommonNode_1(rowIndex, columnHead);//构造新内部节点并初始化行号列号
		DLXNode_1 *lastVerticalNode = columnHead->upNode;

		//链接垂直节点
		lastVerticalNode->appendDownNode(currentNode);
		currentNode->appendDownNode(columnHead);

		//链接水平节点
		if (i == 0)
		{
			firstHorizontalNode = currentNode;
			lastHorizontalNode = currentNode;
		}
		else 
		{
			lastHorizontalNode->appendRightNode(currentNode);
			lastHorizontalNode = currentNode;
		}

		currentNode->columnIndex = columnHead->columnIndex;
		columnHead->numberOfOne++;
	}

	lastHorizontalNode->appendRightNode(firstHorizontalNode);
}