#pragma once
typedef struct BTNode
{
	char data;//结点的data域，默认为char型
	struct BTNode* lchild;
	struct BTNode* rchild;
};