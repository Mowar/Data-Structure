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
	printf("�������ͱ���:");
	scanf_s("%d%d",&G.vexnum,&G.arcnum);
	printf("�����붥��:\n");
	for(i=0; i < G.vexnum; ++ i) scanf_s("%d",&G.vexs[i]);	//���춨������
	for(i=0; i < G.vexnum; ++ i)
		for(j=0; j<G.vexnum; ++ j) {G.arcs[i][j].adj = 0;G.arcs[i][j].weight = INT_MAX_T;}
		printf("����Ժ�Ȩֵ:\n");
		for(k=0;k<G.arcnum; ++ k){	//�����ڽӾ���
			scanf_s("%d%d%d",&v1,&v2,&w);
			i = LocateVex(G,v1); j = LocateVex(G,v2);	//ȷ��v1��v2��G�е�λ��
			G.arcs[i][j].adj = 1;
			G.arcs[i][j].weight = w;
			G.arcs[j][i] = G.arcs[i][j];
			}
		return OK;
	}
Status CreateDN(MGraph &G){
	int v1,v2,w,i,j,k;
	printf("�������ͱ���:");
	scanf_s("%d%d",&G.vexnum,&G.arcnum);
	printf("�����붥��:");
	for(i=0; i < G.vexnum; ++ i) scanf_s("%d",&G.vexs[i]);	//���춨������
	for(i=0; i < G.vexnum; ++ i)
		for(j=0; j<G.vexnum; ++ j) {G.arcs[i][j].adj = 0; G.arcs[i][j].weight = INT_MAX_T;}
		printf("���붥��Ժ�Ȩֵ:\n");
		for(k=0;k<G.arcnum; ++ k){	//�����ڽӾ���
			scanf_s("%d%d%d",&v1,&v2,&w);
			i = LocateVex(G,v1); j = LocateVex(G,v2);	//ȷ��v1��v2��G�е�λ��
			G.arcs[i][j].adj = 1;
			G.arcs[i][j].weight = w;
			}
		return OK;
	}
Status CreateMGraph(MGraph &G){
	printf("�����ڽӾ���洢�ṹ\n");
	printf("1 ��������ͼG\n");
	printf("2 ����������G\n");
	printf("3 ��������ͼG\n");
	printf("4 ����������G\n");
	printf("ѡ�����:");
	scanf_s("%d",&G.kind);
	switch(G.kind){
	case 1: return CreateDG(G);	//��������ͼG
	case 2: return CreateDN(G);	//����������G
	case 3: return CreateUDG(G);	//��������ͼG
	case 4: return CreateUDN(G);	//����������G
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
	//������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����
	//��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��:
	int i,j,k;
	CloseDge closedge[MAX_VERTEX_NUM];
	k = LocateVex(G,u);
	for(j=0; j<G.vexnum;++j)	//���������ʼ��
		if(j!=k)	{closedge[j].adjvex=u;closedge[j].lowcost=G.arcs[k][j].weight;}
		closedge[k].lowcost=0;
		//closedge[k].adjvex = u;
		for(i=1;i<G.vexnum;++i){
			k=minimum(closedge,G.vexnum);	//���T����һ����㣬��k������
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
		for(w=0;w<G.vexnum; ++w) p[v][w] = FALSE;	//���·��
		if(D[v]<INT_MAX) {p[v][w] = TRUE; p[v][v] = TRUE;}
		}
	D[index] = 0; final[index] = TRUE;
	//��ʼ��ѭ����ÿ�����V0��ĳ��v��������·��������v��s��
	for(i=1; i<G.vexnum; ++i){
		min = INT_MAX_T;		//��ǰ��֪��v0������������
		for(w=0;w<G.vexnum; ++w){
			if(!final[w] && D[w] < min)		//w������v-s��
				{
				v =w;
				min=D[w];
				}	//w������v0�������
			}
		final[v] = TRUE;					//��v0���������v����s��
		for(w=0;w<G.vexnum; ++w)				//���µ�ǰ���·��������
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
/* Dijkstra�㷨����������g��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */ 
/* P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */ 
void ShortestPath_DIJ(MGraph G, int v0, int *P, int *D)
	{
	int i, w, v, min;
	int final[20];	  /* final[w]=TRUE��ʾ��ö���v0��w�����·�� */

	//��ʼ������
	for (v=0; v<G.vexnum; ++v) 
		{
		final[v]=FALSE;	 /*ȫ�������ʼ��Ϊδ֪���·��״̬*/
		D[v]=G.arcs[v0][v].weight;	 /*����v0�����ߵĶ������Ȩֵ*/
		P[v]=v0;	 /*��ʼ��·������pΪv0*/
		}
	printf("1	��ʼ���ɹ�\n");	
	/*��ʼ����v0��������S��*/
	D[v0]=0;	 /*v0��v0·��Ϊ0*/
	final[v0]=TRUE;	 /*v0��v0������·��*/
	printf("2	��ʼ���ɹ�\n");

	/*��ʼѭ����ÿ�����V0��ĳ��V��������·��������V��S��*/
	for (i=1;i<G.vexnum;i++)	 //����G.vexnum-1������
		{
		min = INT_MAX;
		for (w=0;w<G.vexnum;++w)
			if (!final[w] && D[w]<min)
				{ 
				v = w; 
				min = D[w];
				}  //��ǰ���·���������Ϣ
			printf("%d\n\n",G.vexnum);
			final [v] = TRUE;	 //��v0���������v���뼯��S
			for (w=0;w<G.vexnum; ++w)     //���µ�ǰ���·��������
				if (!final[w]&& (min+G.arcs[v][w].weight<D[w]))	//�޸�D[w]��P[w]��w����V-S
					{
					D[w] = min + G.arcs[v][w].weight;
					P[w] = v;
					}
		}
	} 