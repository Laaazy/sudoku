//#pragma once
//#include <iostream>
//
////DLXNode, the one with horizontal and vertical loop links
//class DLXNode {//ʮ��ѭ������
//public:
//	DLXNode* leftNode = NULL;//�ĸ������ָ��
//	DLXNode* rightNode = NULL;
//	DLXNode* upNode = NULL;
//	DLXNode* downNode = NULL;
//	int columnIndex = -1;
//
//	DLXNode() : leftNode(this),rightNode(this), upNode(this), downNode(this) {}//���캯��
//
//	void appendLeftNode(DLXNode* tempNode);//���ӽڵ�
//
//	void appendRightNode(DLXNode* tempNode);
//
//	void appendUpNode(DLXNode* tempNode);
//
//	void appendDownNode(DLXNode* tempNode);
//};
//
////Column head node ��ͷ���
//class ColumnHead : public DLXNode {
//public:
//	int numberOfOne = 0;
//
//	ColumnHead(int columnIndex) {//������
//		this->columnIndex = columnIndex;
//	}
//};
//
////Common node inside lists
//class CommonNode : public DLXNode {//class �������� : �̳з�ʽ ������ 
//public://������ĳ�Ա
//	int rowIndex;//����
//	ColumnHead* columnHead = NULL;
//
//	CommonNode(int rowIndex, ColumnHead *columnHead) : rowIndex(rowIndex), columnHead(columnHead) {}//���캯������ʼ�����ڵ��rowIndex,columnHead
//};