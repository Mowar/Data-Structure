#include "graph.h"

int main(void){
	MGraph G;
	ALGraph G1;
	int choice;
	int i = 0;
	/*printf("1���ڽӱ����ز���\n");
	printf("2���ڽӾ������ز���\n");
	printf("��ѡ����Ĳ���\n");
	scanf_s("%d",&choice);
	switch(choice)
		{
	case 1:
		printf("��������ͼ���ڽӱ�\n");
		CreateALGraph(G1);
		printf("�������ͼ���ڽӱ�\n");
		PrintG(G1,2);
		printf("���ڽӱ����������\n");
		TopologicalSort(G1);
		break;
	case 2:
		printf("�������������ڽӾ���\n");
		CreateMGraph(G);
		printf("������������ڽӾ���\n");
		PrintMGraph(G);
		printf("������ڽӾ������С������\n");
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
