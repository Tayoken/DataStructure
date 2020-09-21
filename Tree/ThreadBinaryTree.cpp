#include <iostream>
#include "C.h"
#include "TBTNode.h"

/**中序线索化
* 线索化分析：需要中序遍历的框架，这里采用递归的形势，在遍历的过程中连上合适的线索即可
* 线索化规则：左线索指针指向当前结点在中序遍历序列中的前驱结点，右线索指针指向后继结点。
* 因此需要一个指针p指向当前结点，pre指向p的前驱结点，p的左线索如果存在则让其指向pre， pre的右线索如果存在则让其指向p，因为p是pre的后继结点，这样就完成了一对线索的连接
* 保持pre始终指向p的前驱结点的过程：当p将要离开一个访问过的结点时，pre指向p，当p来到一个新的结点时，pre指向的就是此时的p的前驱结点
*/

/*
* 访问结点p的函数，包含对p的操作
*/
void Visit(TBTNode* p)
{
	std::cout << p->data << std::endl;
}

/*中序线索化,p:当前结点,pre:前驱结点*/
void InThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);								//递归 左子树线索化
		if (p->lchild == NULL)
		{                                                       //建立当前结点的前驱线索
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{                                                       //建立前驱结点的后继线索
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;                                                //pre 指向p，作为p将要指向的下一个结点的前驱结点
		InThread(p->rchild, pre);                               //递归 右子树线索化
	}
}

/*
* 利用中序遍历建立中序线索二叉树
*/
void createInThread(TBTNode* root)
{
	TBTNode* pre = NULL;                                        //前驱结点指针
	if (root != NULL)
	{
		InThread(root, pre); 
		pre->rchild = NULL;                                     //非空二叉树 线索化
		pre->rtag = 1;                                          //后处理中序最后一个结点
	}
}

/*
* 遍历中序二叉树
* 中序遍历下的第一个结点
*/
TBTNode* First(TBTNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;	                                                //最左下结点
}

/*
* 求中序线索二叉树中，结点p在中序下的后继线索的算法
*/
TBTNode *Next(TBTNode *p)
{
	if (p->rtag == 0)
		return First(p->rchild);
	else
		return p->lchild;                                       //rtag==1, 直接返回后继线索
}

void Inorder(TBTNode* root)
{
	for (TBTNode* p = First(root); p != NULL; p = Next(p))
		Visit(p);                                               //Visit 是访问结点p的函数
}

/*
* 建立前序线索二叉树的算法.
* 和中序线索化的代码极为相似，最大的区别就是把连接线索的代码提前到了两递归的入口前面。符合先序遍历的框架
*/
void preThread(TBTNode* p, TBTNode*& pre)
{
	if (p!=NULL)
	{
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		/*注意，这里在递归入口处有限制条件，左右指针都不能是线索才能继续递归*/
		if (p->ltag == 0)
			preThread(p->lchild, pre);
		if (p->rtag == 0)
			preThread(p->rchild, pre);
	}
}

/*
* 在前序线索二叉树上执行前序遍历的算法
*/
void preorder(TBTNode* root)
{
	if (root != NULL)
	{
		TBTNode* p = root;
		while (p!=NULL)
		{
			while (p->ltag == 0)                                //左指针不是线索，则边访问边左移
			{
				Visit(p);
				p = p->lchild;
			}
			Visit(p);                                           //p 此时左指针必为线索，但还没有被访问，访问p
			p = p->rchild;                                      //此时p左孩子不存在，则右指针为空，若非空，则不论是否为线索都是指向后继
		}
	}
}

/*
* 后续线索二叉树线索化
* 和中序线索化极为相似，最大的区别就是把链接线索的代码放到了两递归入口的后面，符合后序遍历的框架
*/
void postThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		postThread(p->lchild, pre);                             //递归，左子树线索化
		postThread(p->rchild, pre);                             //递归，右子树线索化
		if (p->lchild == NULL)
		{
			p->lchild = pre;                                    //简历当前结点的前驱线索
			p->ltag = 1;
		}
		if (pre!=NULL&&pre->rchild==NULL)
		{
			pre->rchild = p;                                    //建立前驱结点的后继线索
			pre->rtag = 1;
		}
		pre = p;
	}
}