#include "MGraph.h"
#include <iostream>

#define INF 9999

/*ͼ-���·���㷨*/
/*1 �Ͻ�˹�����㷨*/
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxSize];
	int min, j, u, i;
	/*��ʼ��*/
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
	/*��ʼ������*/
	/*�ؼ�������ʼ*/
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
			/*���if�ж϶���u�ļ����Ƿ�����̵�j��·��������ǣ��޸�·���ͳ��ȣ�����ʲô������*/
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
			{
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}

	}
}
/*��������ʱdist[]�ŵ���v�����ඥ������·������*��path[]�ŵ���v�����������·��*/

//����Ͻ�˹�����㷨��·��
void printDijkstraPath(int path[], int a)
{
	int stack[maxSize], top = -1;
	/*���ѭ����Ҷ�ӽ�㵽���ڵ���ջ*/
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



/*2 ���������㷨*/
void Floyd(MGraph g, int Path[][maxSize], int A[][maxSize])
{
	int i, j, k;
	for (i = 0; i < g.n; i++)	
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}

	/*����������ѭ���Ǳ��㷨����Ҫ�������������kΪ�м䶥������еĶ����(i,j)���м����޸�*/
	for (k = 0; k < g.n; k++)
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
}

/*�����u��v�����·���ϵĶ�������*/
void printFloydPath(int u, int v, int path[][maxSize], int A[][maxSize)
{
	if (A[u][v] == INF)
	{
		//A[u][v] = INF��ʾû��·��
	}
	else
	{
		if(path[u][v] == -1)
		{
			//ֱ�����<u,v>
		}
		else
		{
			int mid = path[u][v];
			printFloydPath(u, mid, path, A);
			printFloydPath(mid, v, path, A);
		}
	}
}

