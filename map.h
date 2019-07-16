#ifndef _MAP_H_ 
#define _MAP_H_

#include "tools.h"
#define MAX 100
#define INF 65535

typedef struct graph
{
    char vexs[MAX][MAX];  // ���㼯��
    int vexnum;           // ������
    float matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;

Graph* createGraph();
int dijkstra(Graph G, int vs);
void displayMapInfo(Graph* G); 

#endif 
