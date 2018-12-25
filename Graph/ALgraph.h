#include "DS.h"

#define MAX_VERTEX_NUM 20  //����������
#define INFINITY INT_MAX
typedef int VertexType;
typedef int Boolean;
typedef struct ArcNode{
	int            adjvex;
	struct ArcNode *nextarc;
	int            weight;  //�ߵ�Ȩֵ
	}ArcNode;  //����         #define VertexType int  //����Ԫ������
typedef struct VNode{  
	VertexType data;
	ArcNode *firstarc;
	}VNode, AdjList[MAX_VERTEX_NUM]; //
typedef struct{
	AdjList vertices;
	int vexnum, arcnum; //�����ʵ�������ߵ�ʵ����
	int kind;
	}ALGraph;
void menu();						//�˵�
void UDGmenu();						//����ͼ
void DGmenu();						//����ͼ
Status CreateALGraph(ALGraph &G);	//����ͼ
//Status CreateDG(ALGraph &G);
Status CreateG(ALGraph *G,int kind);	//����ͼ
void PrintG(ALGraph G, int kind);	//��ӡͼ
int ComputingDegree(ALGraph G);		//����ͼ�Ķ�
void BFSTraverse(ALGraph G);		//����ͼ�Ĺ�����ȱ���
void DFSTraverse(ALGraph G);		//����ͼ��������ȱ���

//----------------------
Status TopologicalSort(ALGraph G);	//����ͼG�����ڽӱ�洢�ṹʵ����������