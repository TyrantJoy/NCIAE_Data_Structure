#include "map.h"

Graph* createGraph()
{
	int vlen = 0;
	FILE *mapNameInfo, *mapDataInfo;
	char vexs[MAX][MAX];
	float matrix[MAX][MAX];
	if ((mapNameInfo = fopen("mapNameInfo.txt","r")) == NULL)
		return 0;
	if ((mapDataInfo = fopen("mapDataInfo.txt", "r")) == NULL)
		return 0;
	while(!feof(mapNameInfo)){
		fscanf(mapNameInfo, "%s\n", vexs[vlen]);
		fscanf(mapDataInfo, "%f %f %f %f %f %f %f %f %f %f \
							 %f %f %f %f %f %f %f %f %f %f\n",
					&matrix[vlen][0], &matrix[vlen][1], &matrix[vlen][2], &matrix[vlen][3],
					&matrix[vlen][4], &matrix[vlen][5], &matrix[vlen][6], &matrix[vlen][7],
					&matrix[vlen][8], &matrix[vlen][9], &matrix[vlen][10], &matrix[vlen][11],
					&matrix[vlen][12], &matrix[vlen][13], &matrix[vlen][14], &matrix[vlen][15],
					&matrix[vlen][16], &matrix[vlen][17], &matrix[vlen][18], &matrix[vlen][19]);
		vlen++;
	}
	fclose(mapNameInfo);
	fclose(mapDataInfo); 
    int i, j;
    Graph* pG;
    
    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL )
        return NULL;
    memset(pG, 0, sizeof(Graph));

    pG->vexnum = vlen;

    for (i = 0; i < pG->vexnum; i++)
        strcpy(pG->vexs[i], vexs[i]);

    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            pG->matrix[i][j] = matrix[i][j];            
    return pG;
}

int dijkstra(Graph G, int vs)
{
    int i,j,k;
    float min;
    float tmp;
    int flag[MAX];      
    int prev[MAX] = {0};
    float dist[MAX] = {0};
  
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              
        prev[i] = vs;              
        dist[i] = G.matrix[vs][i];
    }

    flag[vs] = 1;
    dist[vs] = 0; 

    for (i = 1; i < G.vexnum; i++)
    {
        min = INF;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        flag[k] = 1;

        for (j = 0; j < G.vexnum; j++)
        {
            tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j]));
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
	
    printf("由 %s 为起点的运动路线如下所示: \n", G.vexs[vs]);

	int num,a[20];
	for(i=0;i<G.vexnum;i++){
		j = i;
		num = 0;
		while(1){
			a[num] = prev[j];
			num++;
			if(prev[j] == vs)
				break;
			else
				j = prev[j];
		}
		invertArray(a, num);
		for(j=0;j<num;j++)
			printf("%s-->",G.vexs[a[j]]);
		printf("%s 共计 %.2f km\n", G.vexs[i], dist[i]);
	}
	 
}

void displayMapInfo(Graph* G){
	for(int i = 0; i < G->vexnum; i++){
		if(i % 2 == 1){
			printf("%d. %-15s\t%d. %-15s\n", i, G->vexs[i-1], i+1, G->vexs[i]);
		}
	}
}


