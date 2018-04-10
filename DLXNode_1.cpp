#include<iostream>
#include"DLXNode_1.h"

void DLXNode_1::appendLeftNode(DLXNode_1 *tempNode)//链接节点
{
	this->leftNode = tempNode;
	tempNode->rightNode = this;
}

void DLXNode_1::appendRightNode(DLXNode_1 *tempNode)
{
	this->rightNode = tempNode;
	tempNode->leftNode = this;
}

void DLXNode_1::appendUpNode(DLXNode_1 *tempNode)
{
	this->upNode = tempNode;
	tempNode->downNode = this;
}

void DLXNode_1::appendDownNode(DLXNode_1 *tempNode)
{
	this->downNode = tempNode;
	tempNode->upNode = this;
}
