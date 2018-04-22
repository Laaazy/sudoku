//#pragma once
//#include <iostream>
//
////DLXNode, the one with horizontal and vertical loop links
//class DLXNode {//十字循环链表
//public:
//	DLXNode* leftNode = NULL;//四个方向的指针
//	DLXNode* rightNode = NULL;
//	DLXNode* upNode = NULL;
//	DLXNode* downNode = NULL;
//	int columnIndex = -1;
//
//	DLXNode() : leftNode(this),rightNode(this), upNode(this), downNode(this) {}//构造函数
//
//	void appendLeftNode(DLXNode* tempNode);//链接节点
//
//	void appendRightNode(DLXNode* tempNode);
//
//	void appendUpNode(DLXNode* tempNode);
//
//	void appendDownNode(DLXNode* tempNode);
//};
//
////Column head node 列头结点
//class ColumnHead : public DLXNode {
//public:
//	int numberOfOne = 0;
//
//	ColumnHead(int columnIndex) {//构造器
//		this->columnIndex = columnIndex;
//	}
//};
//
////Common node inside lists
//class CommonNode : public DLXNode {//class 派生类名 : 继承方式 基类名 
//public://派生类的成员
//	int rowIndex;//行数
//	ColumnHead* columnHead = NULL;
//
//	CommonNode(int rowIndex, ColumnHead *columnHead) : rowIndex(rowIndex), columnHead(columnHead) {}//构造函数，初始化各节点的rowIndex,columnHead
//};