#pragma once
/*
* 线索二叉树结点
*/
typedef struct TBTNode
{
	char data;
	int ltag, rtag;									//线索标记
	struct TBTNode* lchild;
	struct TBTNode* rchild;
};