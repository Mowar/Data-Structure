#include "graph.h"

int main(void){
	MGraph G;
	ALGraph G1;
	int choice;
	int i = 0;
	/*printf("1：邻接表的相关操作\n");
	printf("2：邻接矩阵的相关操作\n");
	printf("请选择你的操作\n");
	scanf_s("%d",&choice);
	switch(choice)
		{
	case 1:
		printf("创建有向图的邻接表\n");
		CreateALGraph(G1);
		printf("输出有向图的邻接表\n");
		PrintG(G1,2);
		printf("该邻接表的拓扑排序\n");
		TopologicalSort(G1);
		break;
	case 2:
		printf("创建无向网的邻接矩阵\n");
		CreateMGraph(G);
		printf("输出无向网的邻接矩阵\n");
		PrintMGraph(G);
		printf("输出该邻接矩阵的最小生成树\n");
		MiniSpanTree_PRIM(G,1);
		break;
		}*/
	CreateMGraph(G);
	PrintMGraph(G);
	int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	//int p[MAX_VERTEX_NUM];
	int D[MAX_VERTEX_NUM];
	//MiniSpanTree_PRIM(G,1);
	ShortestPaht_DLJ(G,0,p,D);
	//ShortestPath_DIJ(G,0,p,D);
	for(i=1;i<G.vexnum; i++)
		printf("%d ",D[i]);
	printf("\n");
	printf("1\n");
	return 1;
	}
