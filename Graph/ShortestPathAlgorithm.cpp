#include "MGraph.h"
#include <iostream>

#define INF 9999

/*图-最短路径算法*/
/*1 迪杰斯特拉算法*/
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxSize];
	int min, j, u, i;
	/*初始化*/
	for (i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	set[v] = 1;
	path[v] = -1;
	/*初始化结束*/
	/*关键操作开始*/
	for (i = 0; i < g.n; i++)
	{
		min = INF;
		for(j=0;j<g.n;j++)
			if (set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		set[u] = 1;
		for (j = 0; j < g.n; j++)
		{
			/*这个if判断顶点u的加入是否会缩短到j的路径，如果是，修改路径和长度，否则什么都不做*/
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
			{
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}

	}
}
/*函数结束时dist[]放的是v到其余顶点的最短路径长度*，path[]放的是v到其余点的最短路径*/

//输出迪杰斯特拉算法的路径
void printDijkstraPath(int path[], int a)
{
	int stack[maxSize], top = -1;
	/*这个循环由叶子结点到根节点入栈*/
	while (path[a] != -1)
	{
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1)
	{
		std::cout << stack[top--] << ' ';
	}
	std::cout << std::endl;
}



/*2 弗洛伊德算法*/
void Floyd(MGraph g, int Path[][maxSize], int A[][maxSize])
{
	int i, j, k;
	for (i = 0; i < g.n; i++)	
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}

	/*下面这三层循环是本算法的主要操作，完成了以k为中间顶点对所有的顶点对(i,j)进行检测和修改*/
	for (k = 0; k < g.n; k++)
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
}

/*输出从u到v的最短路径上的顶点序列*/
void printFloydPath(int u, int v, int path[][maxSize], int A[][maxSize])
{
	if (A[u][v] == INF)
	{
		//A[u][v] = INF表示没有路径
	}
	else
	{
		if(path[u][v] == -1)
		{
			//直接输出<u,v>
		}
		else
		{
			int mid = path[u][v];
			printFloydPath(u, mid, path, A);
			printFloydPath(mid, v, path, A);
		}
	}
}

