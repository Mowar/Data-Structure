#include "DS.h"
#define MAX_VERTEX_NUM 20  //顶点最大个数
typedef enum {DG, DN, UDG, UDN} GraphKind;	//图的种类
typedef int VRType;
#define INT_MAX_T 3000
typedef int VertexType;
typedef int** PathMatrix;
typedef int* ShortPathTable;
typedef struct ArcCell{
	VRType  adj;	//VRType是定点关系类型，用1或0，表示相邻否
	int       weight;  //边的权值
	}ArcCell,AdjMatrix;

typedef struct{
		VertexType vexs[MAX_VERTEX_NUM];	
		AdjMatrix  arcs[MAX_VERTEX_NUM] [MAX_VERTEX_NUM];			//邻接矩阵
		int        vexnum, arcnum; //顶点的实际数，边的实际数
		GraphKind kind;				//图的种类标志
	}MGraph;

typedef struct{
		VertexType adjvex;	//顶点值
		VRType lowcost;		//权值
		}CloseDge;

Status CreateMGraph(MGraph &G);	//采用邻接矩阵表示法，构造图G
void PrintMGraph(MGraph G);     //输出邻接矩阵
void MiniSpanTree_PRIM(MGraph G,VertexType u);//无向图的邻接矩阵为基础实现最小生成树的PRIM算法。
void ShortestPaht_DLJ(MGraph G,int vo, int p[20][20],int *D);//有向图的邻接矩阵为基础实现Dijkstra算法输出单源点到其它顶点的最短路径。
//void ShortestPath_DIJ(MGraph G, int v0, int *P, int *D);