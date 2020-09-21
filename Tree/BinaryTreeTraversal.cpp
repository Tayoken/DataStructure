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
* ���������㷨�Ƕ����������㷨�ĸĽ������ݹ��Ϊѭ��
*/

void preoderNonrecursion(BTNode* root)
{
	if (root != NULL)
	{
		BTNode* stack[maxSize];									//����һ��ջ
		int top = -1;											//��ʼ��ջ
		BTNode* p;		   
		stack[++top] = root;                                    //���ڵ���ջ
		while (top != -1)                                       //ջ��ѭ���˳�
		{
			p = stack[top--];                                   //��ջ�����ջ�����
			Visit(p);                                           //����p
			if (p->rchild != NULL)                              //ջ�������Һ��Ӵ��� �Һ�����ջ
				stack[++top] = p->rchild;
			if (p->lchild != NULL)                              //ջ���������Ӵ��� ������ջ
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
		* �������ѭ��������������ע���ջʱ����ջ��״̬��ʱ��������û�н�������Ϊ���ڵ����������û�б���
		*/
		while (top != -1 && p != NULL)
		{
			while (p != NULL)                                   //���Ӵ�����������ջ
			{
				stack[++top] = p;
				p = p->lchild;

			}
			if (top != -1)                                      //��ջ���յ�����³�ջ�����ջ�����
			{
				p = stack[top--];
				Visit(p);                                       //����p
				p = p->rchild;                                  //pָ������������һ��ѭ����ʼ�������ı���
			}
		}
	}
}



/*
* ������������ֻ������������������ж�������������˳�򽻻����õ��Ľ��
*/
void postorderNonrecursion(BTNode* root)
{
	if (root != NULL)
	{
		/*��������ջ*/
		BTNode* stack1[maxSize]; int top1 = -1;
		BTNode* stack2[maxSize]; int top2 = -1;
		BTNode* p = NULL;
		stack1[top1++] = p;
		while (top1 != -1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;
			/*ע����������if����������������� ������������ջ˳�����෴��*/
			if (p->lchild != NULL)
				stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}
		while (top2 != -1)
		{
			/*��ջ˳��Ϊ������������*/
			p = stack2[top2--];
			Visit(p);
		}
	}
}

