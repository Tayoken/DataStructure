#pragma once

#define maxSize 100
typedef struct VertexType{
	int no;
	char info;
};

typedef struct MGraph
{
	int edges[maxSize][maxSize];
	int n, e;
	VertexType vex[maxSize];
};