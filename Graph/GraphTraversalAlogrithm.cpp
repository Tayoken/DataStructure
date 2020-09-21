#include <iostream>
#include "AGraph.h"
#define maxSize 100
using namespace std;

int visit[maxSize];

/*图-深度优先搜索遍历+广度优先搜索遍历*/
void DFS(AGraph* G, int v) {
	ArcNode* p;
	visit[v] = 1;
	//Visit(v);
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visit[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

//visit 数组初始化为0
void BFS(AGraph* G, int v, int visit[maxSize]) {
	ArcNode* p;
	int que[maxSize], front = 0, rear = 0;
	int j;
	//Visit(v);
	visit[v] = 1;
	rear = (rear + 1) % maxSize;
	que[rear] = v;
	while (front != rear) {
		front = (front + 1) % maxSize;
		j = que[front];
		p = G->adjlist[j].firstarc;
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {
				//Visit(p->adjvex);
				visit[p->adjvex] = 1;
				rear = (rear)+1 % maxSize;
				que[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}

