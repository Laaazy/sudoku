#include "DLXGenerator_1.h"

//����һ�п�����
vector<ColumnHead_1 *> DLXGenerator_1::createColumnHeads(DLXNode_1 *listHead, int length) 
{
	vector<ColumnHead_1*> columnHeads;
	columnHeads.resize(length);
	DLXNode_1 *lastNode = listHead;

	for (int i = 0; i < length; ++i) 
	{
		ColumnHead_1 *columnHead = new ColumnHead_1(i);//i�ǹ��캯������������ColumnHead�к�
		lastNode->appendRightNode(columnHead);
		columnHeads[i] = columnHead;//����ǰ��ͷ��������ͷ����
		lastNode = columnHead;//����lastNode
	}

	lastNode->appendRightNode(listHead);//����ѭ������
	return columnHeads;
}

//����һ��Ԫ��
void DLXGenerator_1::appendLine(vector<ColumnHead_1*> columnHeads, vector<int> elementSubscripts, int rowIndex) 
{
	CommonNode_1 *lastHorizontalNode = NULL;
	CommonNode_1 *firstHorizontalNode = NULL;

	for (int i = 0; i < elementSubscripts.size(); ++i) 
	{
		int subscript = elementSubscripts[i];
		ColumnHead_1 *columnHead = columnHeads[subscript];//�˴��в�ȷ���Ķ�
		CommonNode_1 *currentNode = new CommonNode_1(rowIndex, columnHead);//�������ڲ��ڵ㲢��ʼ���к��к�
		DLXNode_1 *lastVerticalNode = columnHead->upNode;

		//���Ӵ�ֱ�ڵ�
		lastVerticalNode->appendDownNode(currentNode);
		currentNode->appendDownNode(columnHead);

		//����ˮƽ�ڵ�
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