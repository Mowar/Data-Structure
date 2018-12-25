#include "DS.h"
#define MAX_VERTEX_NUM 20  //����������
typedef enum {DG, DN, UDG, UDN} GraphKind;	//ͼ������
typedef int VRType;
#define INT_MAX_T 3000
typedef int VertexType;
typedef int** PathMatrix;
typedef int* ShortPathTable;
typedef struct ArcCell{
	VRType  adj;	//VRType�Ƕ����ϵ���ͣ���1��0����ʾ���ڷ�
	int       weight;  //�ߵ�Ȩֵ
	}ArcCell,AdjMatrix;

typedef struct{
		VertexType vexs[MAX_VERTEX_NUM];	
		AdjMatrix  arcs[MAX_VERTEX_NUM] [MAX_VERTEX_NUM];			//�ڽӾ���
		int        vexnum, arcnum; //�����ʵ�������ߵ�ʵ����
		GraphKind kind;				//ͼ�������־
	}MGraph;

typedef struct{
		VertexType adjvex;	//����ֵ
		VRType lowcost;		//Ȩֵ
		}CloseDge;

Status CreateMGraph(MGraph &G);	//�����ڽӾ����ʾ��������ͼG
void PrintMGraph(MGraph G);     //����ڽӾ���
void MiniSpanTree_PRIM(MGraph G,VertexType u);//����ͼ���ڽӾ���Ϊ����ʵ����С��������PRIM�㷨��
void ShortestPaht_DLJ(MGraph G,int vo, int p[20][20],int *D);//����ͼ���ڽӾ���Ϊ����ʵ��Dijkstra�㷨�����Դ�㵽������������·����
//void ShortestPath_DIJ(MGraph G, int v0, int *P, int *D);