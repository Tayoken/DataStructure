#include "AGraph.h"
#include <iostream>

/*图-拓扑搜索， AOV网*/
int TopSort(AGraph* G)
{
	int i, j, n= 0;
	int stack[maxSize], top = -1;//定义并初始化栈
	ArcNode* p;
	/*这个循环将图中入度为0的顶点入栈*/
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].count == 0)
			stack[++top] = i;
	}
	/*!!key operation!!*/
	while (top != -1)
	{
		i = stack[top--];//顶点出栈
		++n;//计数器加1
		std::cout << i << " ";//输出当前顶点
		p = G->adjlist[i].firstarc;
		/*这个循环实现了把所有此顶点邻接的点的入度减1，并且将入度变为0的点入栈*/
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