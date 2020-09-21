#include <iostream>
#include "BTNode.h"
#include "C.h"

void Visit(BTNode* p)
{
	std::cout << p->data << std::endl;
}

void preorder(BTNode* p)
{
	if (p != NULL)
	{
		Visit(p);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(BTNode* p)
{
	if (p != NULL)
	{
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}

void postorder(BTNode* p)
{
	if (p != NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		Visit(p);
	}
}


/*
* 下面三个算法是二叉树遍历算法的改进，将递归改为循环
*/

void preoderNonrecursion(BTNode* root)
{
	if (root != NULL)
	{
		BTNode* stack[maxSize];									//定义一个栈
		int top = -1;											//初始化栈
		BTNode* p;		   
		stack[++top] = root;                                    //根节点入栈
		while (top != -1)                                       //栈空循环退出
		{
			p = stack[top--];                                   //出栈并输出栈顶结点
			Visit(p);                                           //访问p
			if (p->rchild != NULL)                              //栈顶结点的右孩子存在 右孩子入栈
				stack[++top] = p->rchild;
			if (p->lchild != NULL)                              //栈顶结点的左孩子存在 左孩子入栈
				stack[++top] = p->lchild;
		}
	}
}


void inorderNonrecursion(BTNode* root)
{
	if (root != NULL)
	{
		BTNode* stack[maxSize];
		int top = -1;
		BTNode* p;
		p = root;
		/*
		* 下面这个循环完成中序遍历，注意出栈时出现栈空状态此时遍历可能没有结束，因为根节点的右子树还没有遍历
		*/
		while (top != -1 && p != NULL)
		{
			while (p != NULL)                                   //左孩子存在则左孩子入栈
			{
				stack[++top] = p;
				p = p->lchild;

			}
			if (top != -1)                                      //在栈不空的情况下出栈并输出栈顶结点
			{
				p = stack[top--];
				Visit(p);                                       //访问p
				p = p->rchild;                                  //p指向右子树，下一次循环开始右子树的遍历
			}
		}
	}
}



/*
* 逆后序遍历序列只不过是先序遍历过程中对左右子树遍历顺序交换所得到的结果
*/
void postorderNonrecursion(BTNode* root)
{
	if (root != NULL)
	{
		/*定义两个栈*/
		BTNode* stack1[maxSize]; int top1 = -1;
		BTNode* stack2[maxSize]; int top2 = -1;
		BTNode* p = NULL;
		stack1[++top1] = root;
		while (top1 != -1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;
			/*注意下面两个if语句和先序遍历的区别， 左右子树的入栈顺序是相反的*/
			if (p->lchild != NULL)
				stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}
		while (top2 != -1)
		{
			/*出栈顺序为后续遍历序列*/
			p = stack2[top2--];
			Visit(p);
		}
	}
}

