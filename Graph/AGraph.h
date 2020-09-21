#pragma once
#define maxSize 100

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	int info;
}ArcNode;

typedef struct VNode{
	char data;
	int count;//ͳ�ƽ�����ȣ����������õ�
	ArcNode* firstarc;
}VNode;

typedef struct AGraph{
	VNode adjlist[maxSize];
	int n, e;
}AGraph;