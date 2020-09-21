#include "AGraph.h"
#include <iostream>

/*ͼ-���������� AOV��*/
int TopSort(AGraph* G)
{
	int i, j, n= 0;
	int stack[maxSize], top = -1;//���岢��ʼ��ջ
	ArcNode* p;
	/*���ѭ����ͼ�����Ϊ0�Ķ�����ջ*/
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].count == 0)
			stack[++top] = i;
	}
	/*!!key operation!!*/
	while (top != -1)
	{
		i = stack[top--];//�����ջ
		++n;//��������1
		std::cout << i << " ";//�����ǰ����
		p = G->adjlist[i].firstarc;
		/*���ѭ��ʵ���˰����д˶����ڽӵĵ����ȼ�1�����ҽ���ȱ�Ϊ0�ĵ���ջ*/
		while (p != NULL)
		{
			j = p->adjvex;
			--(G->adjlist[j].count);
			if (G->adjlist[j].count == 0)
				stack[++top] = j;
			p = p->nextarc;
		}

	}
	/*!!KEY OPERATION END!!*/
	if (n == G->n)
		return 1;
	else
		return 0;
}