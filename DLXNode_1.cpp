#include<iostream>
#include"DLXNode_1.h"

void DLXNode::appendLeftNode(DLXNode *tempNode)//链接节点
{
	this->leftNode = tempNode;
	tempNode->rightNode = this;
}

void DLXNode::appendRightNode(DLXNode *tempNode)
{
	this->rightNode = tempNode;
	tempNode->leftNode = this;
}

void DLXNode::appendUpNode(DLXNode *tempNode)
{
	this->upNode = tempNode;
	tempNode->downNode = this;
}

void DLXNode::appendDownNode(DLXNode *tempNode)
{
	this->downNode = tempNode;
	tempNode->upNode = this;
}
