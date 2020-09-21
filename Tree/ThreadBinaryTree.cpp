#include <iostream>
#include "C.h"
#include "TBTNode.h"

/**����������
* ��������������Ҫ��������Ŀ�ܣ�������õݹ�����ƣ��ڱ����Ĺ��������Ϻ��ʵ���������
* ����������������ָ��ָ��ǰ�����������������е�ǰ����㣬������ָ��ָ���̽�㡣
* �����Ҫһ��ָ��pָ��ǰ��㣬preָ��p��ǰ����㣬p���������������������ָ��pre�� pre���������������������ָ��p����Ϊp��pre�ĺ�̽�㣬�����������һ������������
* ����preʼ��ָ��p��ǰ�����Ĺ��̣���p��Ҫ�뿪һ�����ʹ��Ľ��ʱ��preָ��p����p����һ���µĽ��ʱ��preָ��ľ��Ǵ�ʱ��p��ǰ�����
*/

/*
* ���ʽ��p�ĺ�����������p�Ĳ���
*/
void Visit(TBTNode* p)
{
	std::cout << p->data << std::endl;
}

/*����������,p:��ǰ���,pre:ǰ�����*/
void InThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);								//�ݹ� ������������
		if (p->lchild == NULL)
		{                                                       //������ǰ����ǰ������
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{                                                       //����ǰ�����ĺ������
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;                                                //pre ָ��p����Ϊp��Ҫָ�����һ������ǰ�����
		InThread(p->rchild, pre);                               //�ݹ� ������������
	}
}

/*
* �����������������������������
*/
void createInThread(TBTNode* root)
{
	TBTNode* pre = NULL;                                        //ǰ�����ָ��
	if (root != NULL)
	{
		InThread(root, pre); 
		pre->rchild = NULL;                                     //�ǿն����� ������
		pre->rtag = 1;                                          //�����������һ�����
	}
}

/*
* �������������
* ��������µĵ�һ�����
*/
TBTNode* First(TBTNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;	                                                //�����½��
}

/*
* �����������������У����p�������µĺ���������㷨
*/
TBTNode *Next(TBTNode *p)
{
	if (p->rtag == 0)
		return First(p->rchild);
	else
		return p->lchild;                                       //rtag==1, ֱ�ӷ��غ������
}

void Inorder(TBTNode* root)
{
	for (TBTNode* p = First(root); p != NULL; p = Next(p))
		Visit(p);                                               //Visit �Ƿ��ʽ��p�ĺ���
}

/*
* ����ǰ���������������㷨.
* �������������Ĵ��뼫Ϊ���ƣ�����������ǰ����������Ĵ�����ǰ�������ݹ�����ǰ�档������������Ŀ��
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
		/*ע�⣬�����ڵݹ���ڴ�����������������ָ�붼�������������ܼ����ݹ�*/
		if (p->ltag == 0)
			preThread(p->lchild, pre);
		if (p->rtag == 0)
			preThread(p->rchild, pre);
	}
}

/*
* ��ǰ��������������ִ��ǰ��������㷨
*/
void preorder(TBTNode* root)
{
	if (root != NULL)
	{
		TBTNode* p = root;
		while (p!=NULL)
		{
			while (p->ltag == 0)                                //��ָ�벻����������߷��ʱ�����
			{
				Visit(p);
				p = p->lchild;
			}
			Visit(p);                                           //p ��ʱ��ָ���Ϊ����������û�б����ʣ�����p
			p = p->rchild;                                      //��ʱp���Ӳ����ڣ�����ָ��Ϊ�գ����ǿգ������Ƿ�Ϊ��������ָ����
		}
	}
}