#include "Mgraph.h"
int LocateVex(MGraph G, int v){
	int i = 0;
	for(i=0; i < G.vexnum; ++ i)
		if(G.vexs[i] == v) return i;
	return ERROR;
	}

Status CreateDG(MGraph &G){return OK;}
Status CreateUDG(MGraph &G){return OK;}
Status CreateUDN(MGraph &G){
	int v1,v2,w,i,j,k;
	printf("顶点数和边数:");
	scanf_s("%d%d",&G.vexnum,&G.arcnum);
	printf("请输入顶点:\n");
	for(i=0; i < G.vexnum; ++ i) scanf_s("%d",&G.vexs[i]);	//构造定点向量
	for(i=0; i < G.vexnum; ++ i)
		for(j=0; j<G.vexnum; ++ j) {G.arcs[i][j].adj = 0;G.arcs[i][j].weight = INT_MAX_T;}
		printf("顶点对和权值:\n");
		for(k=0;k<G.arcnum; ++ k){	//构造邻接矩阵
			scanf_s("%d%d%d",&v1,&v2,&w);
			i = LocateVex(G,v1); j = LocateVex(G,v2);	//确定v1和v2在G中的位置
			G.arcs[i][j].adj = 1;
			G.arcs[i][j].weight = w;
			G.arcs[j][i] = G.arcs[i][j];
			}
		return OK;
	}
Status CreateDN(MGraph &G){
	int v1,v2,w,i,j,k;
	printf("顶点数和边数:");
	scanf_s("%d%d",&G.vexnum,&G.arcnum);
	printf("请输入顶点:");
	for(i=0; i < G.vexnum; ++ i) scanf_s("%d",&G.vexs[i]);	//构造定点向量
	for(i=0; i < G.vexnum; ++ i)
		for(j=0; j<G.vexnum; ++ j) {G.arcs[i][j].adj = 0; G.arcs[i][j].weight = INT_MAX_T;}
		printf("输入顶点对和权值:\n");
		for(k=0;k<G.arcnum; ++ k){	//构造邻接矩阵
			scanf_s("%d%d%d",&v1,&v2,&w);
			i = LocateVex(G,v1); j = LocateVex(G,v2);	//确定v1和v2在G中的位置
			G.arcs[i][j].adj = 1;
			G.arcs[i][j].weight = w;
			}
		return OK;
	}
Status CreateMGraph(MGraph &G){
	printf("采用邻接矩阵存储结构\n");
	printf("1 创建有向图G\n");
	printf("2 创建有向网G\n");
	printf("3 创建无线图G\n");
	printf("4 创建无向网G\n");
	printf("选择操作:");
	scanf_s("%d",&G.kind);
	switch(G.kind){
	case 1: return CreateDG(G);	//构造有向图G
	case 2: return CreateDN(G);	//构造有向网G
	case 3: return CreateUDG(G);	//构造无向图G
	case 4: return CreateUDN(G);	//构造无向网G
	default :  return ERROR;
		}
	}

void PrintMGraph(MGraph G){
	int i,j;
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++)
			printf("%d ",G.arcs[i][j].adj);
		printf("\n");
		}
	}

int minimum(CloseDge *closedge,int len){
	int i,index=0;
	int temp = INT_MAX;
	for(i=0; i <len; i++)
		{
		if(closedge[i].lowcost < temp && closedge[i].lowcost !=0)
			{
			temp = closedge[i].lowcost;
			index = i;
			}
		}
	return index;
	}
void MiniSpanTree_PRIM(MGraph G,VertexType u){
	//用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
	//记录从顶点集U到V-U的代价最小的边的辅助数组定义:
	int i,j,k;
	CloseDge closedge[MAX_VERTEX_NUM];
	k = LocateVex(G,u);
	for(j=0; j<G.vexnum;++j)	//辅助数组初始化
		if(j!=k)	{closedge[j].adjvex=u;closedge[j].lowcost=G.arcs[k][j].weight;}
		closedge[k].lowcost=0;
		//closedge[k].adjvex = u;
		for(i=1;i<G.vexnum;++i){
			k=minimum(closedge,G.vexnum);	//求出T的下一个结点，第k个顶点
			printf("%d %d\n",closedge[k].adjvex,G.vexs[k]);
			closedge[k].lowcost = 0;
			for(j=0;j<G.vexnum;++j)
				if(G.arcs[k][j].weight < closedge[j].lowcost)
					{closedge[j].adjvex = G.vexs[k];
			closedge[j].lowcost = G.arcs[k][j].weight;}
			}
	}

void ShortestPaht_DLJ(MGraph G,int v0, int p[20][20],int *D){
	int index = LocateVex(G,v0);
	int v=0,w=0;
	int i=0,min=0;
	int t = 0;
	int *final = (int *)malloc(sizeof(int) * G.vexnum);
	for(v=0;v<G.vexnum; ++ v){
		final[v] = FALSE; D[v]=G.arcs[index][v].weight;
		for(w=0;w<G.vexnum; ++w) p[v][w] = FALSE;	//设空路径
		if(D[v]<INT_MAX) {p[v][w] = TRUE; p[v][v] = TRUE;}
		}
	D[index] = 0; final[index] = TRUE;
	//开始主循环，每次求的V0到某个v顶点的最短路径，并加v到s集
	for(i=1; i<G.vexnum; ++i){
		min = INT_MAX_T;		//当前所知离v0顶点的最近距离
		for(w=0;w<G.vexnum; ++w){
			if(!final[w] && D[w] < min)		//w顶点在v-s中
				{
				v =w;
				min=D[w];
				}	//w顶点离v0顶点更近
			}
		final[v] = TRUE;					//离v0顶点最近的v加入s集
		for(w=0;w<G.vexnum; ++w)				//更新当前最短路径及距离
			{
			if((!final[w]) && ((min+G.arcs[v][w].weight) <D[w]))
				//(min+G.arcs[v][w].weight)>0
				{
				D[w] = min + G.arcs[v][w].weight;
				p[w][0] = p[v][0]; p[w][w]=TRUE;
				}
			}
		}
	}
//------------------------*-----------------------
/* Dijkstra算法，求有向网g的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */ 
/* P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */ 
void ShortestPath_DIJ(MGraph G, int v0, int *P, int *D)
	{
	int i, w, v, min;
	int final[20];	  /* final[w]=TRUE表示求得顶点v0至w的最短路径 */

	//初始化数据
	for (v=0; v<G.vexnum; ++v) 
		{
		final[v]=FALSE;	 /*全部顶点初始化为未知最短路径状态*/
		D[v]=G.arcs[v0][v].weight;	 /*将与v0有连线的顶点加上权值*/
		P[v]=v0;	 /*初始化路径数组p为v0*/
		}
	printf("1	初始化成功\n");	
	/*初始化，v0顶点属于S集*/
	D[v0]=0;	 /*v0至v0路径为0*/
	final[v0]=TRUE;	 /*v0至v0不需求路径*/
	printf("2	初始化成功\n");

	/*开始循环，每次求得V0到某个V顶点的最短路径，并加V到S集*/
	for (i=1;i<G.vexnum;i++)	 //其余G.vexnum-1个顶点
		{
		min = INT_MAX;
		for (w=0;w<G.vexnum;++w)
			if (!final[w] && D[w]<min)
				{ 
				v = w; 
				min = D[w];
				}  //求当前最短路经的相关信息
			printf("%d\n\n",G.vexnum);
			final [v] = TRUE;	 //离v0顶点最近的v加入集合S
			for (w=0;w<G.vexnum; ++w)     //更新当前最短路径及距离
				if (!final[w]&& (min+G.arcs[v][w].weight<D[w]))	//修改D[w]和P[w]，w属于V-S
					{
					D[w] = min + G.arcs[v][w].weight;
					P[w] = v;
					}
		}
	} 