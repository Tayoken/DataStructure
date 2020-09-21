#pragma once
#define maxSize 100

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	int info;
}ArcNode;

typedef struct VNode{
	char data;
	int count;//统计结点的入度，拓扑排序用到
	ArcNode* firstarc;
}VNode;

typedef struct AGraph{
	VNode adjlist[maxSize];
	int n, e;
}AGraph;