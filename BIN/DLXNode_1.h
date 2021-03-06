#pragma once
#include<iostream>

class DLXNode_1 //十字链表
{
public:
	DLXNode_1 *leftNode = NULL;//各方向指针
	DLXNode_1 *rightNode=NULL;
	DLXNode_1 *upNode=NULL;
	DLXNode_1 *downNode=NULL;
	int columnIndex = -1;

	DLXNode_1() :leftNode(this), rightNode(this), upNode(this), downNode(this) {};

	void appendLeftNode(DLXNode_1 *tempNode);

	void appendRightNode(DLXNode_1 *tempNode);

	void appendUpNode(DLXNode_1 *tempNode);

	void appendDownNode(DLXNode_1 *tempNode);
};

class ColumnHead_1 :public DLXNode_1//列头节点继承DLXNode
{
public:
	int numberOfOne = 0;

	ColumnHead_1(int columnIndex)//构造器
	{
		this->columnIndex = columnIndex;
	}
};


class CommonNode_1: public DLXNode_1 {//普通节点继承DLXNode
public:
	int rowIndex;
	ColumnHead_1 *columnHead = NULL;

	CommonNode_1(int rowIndex, ColumnHead_1 *columnHead) : rowIndex(rowIndex), columnHead(columnHead) {}
};