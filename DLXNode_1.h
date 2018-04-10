#pragma once
#include<iostream>

class DLXNode //十字链表
{
public:
	DLXNode *leftNode = NULL;//各方向指针
	DLXNode *rightNode=NULL;
	DLXNode *upNode=NULL;
	DLXNode *downNode=NULL;
	int commomIndex = -1;

	DLXNode() :leftNode(this), rightNode(this), upNode(this), downNode(this) {};

	void appendLeftNode(DLXNode *tempNode);

	void appendRightNode(DLXNode *tempNode);

	void appendUpNode(DLXNode *tempNode);

	void appendDownNode(DLXNode *tempNode);
};

class ColumnHead :public DLXNode//列头节点继承DLXNode
{
public:
	int numberOfOne = 0;

	ColumnHead(int columnIndex)//构造器
	{
		this->commomIndex = columnIndex;
	}
};


class CommonNode : public DLXNode {//普通节点继承DLXNode
public:
	int rowIndex;
	ColumnHead *columnHead = NULL;

	CommonNode(int rowIndex, ColumnHead *columnHead) : rowIndex(rowIndex), columnHead(columnHead) {}
};
