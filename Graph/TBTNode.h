#pragma once
/*
* �������������
*/
typedef struct TBTNode
{
	char data;
	int ltag, rtag;									//�������
	struct TBTNode* lchild;
	struct TBTNode* rchild;
};