#include "DLXSolver_1.h"
//得到一种解
bool DLXSolver_1::solveWithOneAnswer(DLXNode_1 *listHead, vector<CommonNode_1*>& solution, int depth) 
{
	if (listHead->rightNode == listHead)//找到答案
		return true;

	//选择1最少的列
	ColumnHead_1* columnHead = selectColumn(listHead);
	cover(columnHead);

	bool solutionFound = false; 

								
	for (DLXNode_1* node = columnHead->downNode; node != columnHead; node = node->downNode) 
	{
		solution.push_back((CommonNode_1*)node); 

		for (DLXNode_1* node2 = node->rightNode; node2 != node; node2 = node2->rightNode)
			cover(((CommonNode_1*)node2)->columnHead);

		depth++;
		solutionFound = solveWithOneAnswer(listHead, solution, depth); //进入下一层递归
		depth--;

		for (DLXNode_1* node2 = node->leftNode; node2 != node; node2 = node2->leftNode) 
			uncover(((CommonNode_1*)node2)->columnHead);
		

		if (solutionFound)  //找到答案，跳出循环
			break;
	

		solution.pop_back(); 
	}
	uncover(columnHead);

	return solutionFound;
}

//得到所有答案
void DLXSolver_1::solveWithAllAnswers(DLXNode_1 *listHead, vector<CommonNode_1*>& tempSolution, vector<vector<CommonNode_1*>>& lastSolution, int depth)
{
	if (listHead->rightNode == listHead) 
	{ //找到一个解
		lastSolution.push_back(tempSolution);
		return;
	}

	ColumnHead_1* columnHead = selectColumn(listHead);
	cover(columnHead);

	for (DLXNode_1* node = columnHead->downNode; node != columnHead; node = node->downNode) 
	{
		tempSolution.push_back((CommonNode_1*)node); 

		for (DLXNode_1* node2 = node->rightNode; node2 != node; node2 = node2->rightNode)
			cover(((CommonNode_1*)node2)->columnHead);


		depth++;
		solveWithAllAnswers(listHead, tempSolution, lastSolution, depth); //进入下一层递归
		depth--;

		for (DLXNode_1* node2 = node->leftNode; node2 != node; node2 = node2->leftNode) 
			uncover(((CommonNode_1*)node2)->columnHead);


		tempSolution.pop_back(); 
	}
	uncover(columnHead);
}

//得到某一数量的解
void DLXSolver_1::solveWithCertainAnswers(DLXNode_1 *listHead, vector<CommonNode_1*>& tempSolution, vector<vector<CommonNode_1*>>& lastSolution,
	int answerCount, int depth) 
{
	if (listHead->rightNode == listHead) 
	{ //找到一个解
		lastSolution.push_back(tempSolution);
		return;
	}

	ColumnHead_1* columnHead = selectColumn(listHead);
	cover(columnHead);

	for (DLXNode_1* node = columnHead->downNode; node != columnHead; node = node->downNode) 
	{
		tempSolution.push_back((CommonNode_1*)node); 

		for (DLXNode_1* node2 = node->rightNode; node2 != node; node2 = node2->rightNode) 
			cover(((CommonNode_1*)node2)->columnHead);


		depth++;
		solveWithCertainAnswers(listHead, tempSolution, lastSolution, answerCount, depth);//进入下一层递归
		depth--;

		for (DLXNode_1* node2 = node->leftNode; node2 != node; node2 = node2->leftNode) 
			uncover(((CommonNode_1*)node2)->columnHead);
		
		if (lastSolution.size() == answerCount)  //找到符合要求数量的解，跳出循环
			break;
		
		tempSolution.pop_back(); 
	}
	uncover(columnHead);
	return;
}

//覆盖某一列
void DLXSolver_1::cover(ColumnHead_1* columnHead) 
{
	columnHead->rightNode->leftNode = columnHead->leftNode;
	columnHead->leftNode->rightNode = columnHead->rightNode;

	for (DLXNode_1* tempNode = columnHead->downNode; tempNode != columnHead; tempNode = tempNode->downNode) 
	{
		for (DLXNode_1* tempNode2 = tempNode->rightNode; tempNode2 != tempNode; tempNode2 = tempNode2->rightNode)
		{
			tempNode2->downNode->upNode = tempNode2->upNode;
			tempNode2->upNode->downNode = tempNode2->downNode;
			((CommonNode_1*)tempNode2)->columnHead->numberOfOne--;
		}
	}
}

//暴露某一列
void DLXSolver_1::uncover(ColumnHead_1* columnHead) 
{
	for (DLXNode_1* tempNode = columnHead->upNode; tempNode != columnHead; tempNode = tempNode->upNode) 
	{
		for (DLXNode_1* tempNode2 = tempNode->leftNode; tempNode2 != tempNode; tempNode2 = tempNode2->leftNode) 
		{
			((CommonNode_1*)tempNode2)->columnHead->numberOfOne++;
			tempNode2->upNode->downNode = tempNode2;
			tempNode2->downNode->upNode = tempNode2;
		}
	}

	columnHead->rightNode->leftNode = columnHead;
	columnHead->leftNode->rightNode = columnHead;
}


ColumnHead_1* DLXSolver_1::selectColumn(DLXNode_1* listHead) 
{
	int min = 100000;
	ColumnHead_1* selectedHead = NULL;

	for (DLXNode_1* node = listHead->rightNode; node != listHead; node = node->rightNode) 
	{
		ColumnHead_1* columnHead = (ColumnHead_1*)node;//下转型
		if (columnHead->numberOfOne < min) //找到1最少的列
		{
			min = columnHead->numberOfOne;
			selectedHead = columnHead;
		}
	}

	return selectedHead;
}