#include "DS.h"

#define MAX_VERTEX_NUM 20  //顶点最大个数
#define INFINITY INT_MAX
typedef int VertexType;
typedef int Boolean;
typedef struct ArcNode{
	int            adjvex;
	struct ArcNode *nextarc;
	int            weight;  //边的权值
	}ArcNode;  //表结点         #define VertexType int  //顶点元素类型
typedef struct VNode{  
	VertexType data;
	ArcNode *firstarc;
	}VNode, AdjList[MAX_VERTEX_NUM]; //
typedef struct{
	AdjList vertices;
	int vexnum, arcnum; //顶点的实际数，边的实际数
	int kind;
	}ALGraph;
void menu();						//菜单
void UDGmenu();						//无向图
void DGmenu();						//有向图
Status CreateALGraph(ALGraph &G);	//创建图
//Status CreateDG(ALGraph &G);
Status CreateG(ALGraph *G,int kind);	//创建图
void PrintG(ALGraph G, int kind);	//打印图
int ComputingDegree(ALGraph G);		//计算图的度
void BFSTraverse(ALGraph G);		//无向图的广度优先遍历
void DFSTraverse(ALGraph G);		//无向图的深度优先遍历

//----------------------
Status TopologicalSort(ALGraph G);	//有向图G采用邻接表存储结构实现拓扑序列