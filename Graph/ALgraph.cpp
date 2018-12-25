#include "ALgraph.h"
#include "queue.h"
#include "stack.h"
void menu(){
	printf("\t\t�ڽӱ�洢ͼ�Ļ�������\n");
	printf("\t \t 1������ͼ�Ĳ���\n");
	printf("\t \t 2: ����ͼ�Ĳ���\n");
	printf("\t \t 0: �˳�����\n");
	printf("��������������:");
	}

void DGmenu(){
	printf("\t\t ����ͼ�Ļ�������\n");
	printf("\t \t 1����������ͼ\n");
	printf("\t \t 2: �������ͼ\n");
	printf("\t \t 3: ����ͼ�Ķ���\n");
	printf("\t \t 0: ������һ��\n");
	}

void UDGmenu(){
	printf("\t\t ����ͼ�Ļ�������\n");
	printf("\t \t 1����������ͼ\n");
	printf("\t \t 2: �������ͼ\n");
	printf("\t \t 3������ͼ��������ȱ���\n");
	printf("\t \t 4: ����ͼ�Ĺ�����ȱ���\n");
	printf("\t \t 0: ������һ��\n");
	}
/*
void CreateInverALGraph(ALGraph G1,ALGraph *G2){
	//G1���ڽӱ�G2�����ڽӱ�
	int i;
	ArcNode *p;
	//G2�ĳ�ʼ��
	G2->vexnum = G1.vexnum;
	G2->arcnum = G1.arcnum;
	for(i=0;i<G1.vexnum;i++) (*G2).vertices[i].firstarc = NULL;
	//����G1�ڽӱ��������ڽӱ�
	for(i = 0; i < G1.vexnum; i ++)
		{
			p = G1.vertices[i].firstarc;
		while(p)
			{
			G2->vertices[p->adjvex].data = G1.vertices[i].data;
			G2->vertices[p->adjvex].firstarc=q;
			p = p->nextarc;
			}
		}
		}
*/

Status CreateDG(ALGraph &G){
	int j=0,t = 0,t1=0;
	int vexnum, arcnum;	//�������ͱ������Ҷ��������δӱ��1��ʼ
		int i;
		ArcNode *p,*temp,*temp1=NULL;
		int vex1,vex2;
		printf("����������ͼ�Ķ������ͻ�����:");
		scanf_s("%d%d",&vexnum,&arcnum);
		G.vexnum = vexnum;
		G.arcnum = arcnum;
		if(vexnum > MAX_VERTEX_NUM)
			{
			printf("�����������ͼ��󶥵���������ͼʧ��");
			return ERROR;
			}
		for(i=0;i<vexnum;i++) G.vertices[i].firstarc = NULL;
		printf("�����:\n");
		//������ĵ��ڽӵ�Ϊ��ֵ
		for(i=0;i<arcnum;i++){
			temp1 = NULL;
			scanf_s("%d%d",&vex1,&vex2);
			G.vertices[vex1-1].data = vex1;
			if(vex2 > 0)
				G.vertices[vex2-1].data = vex2;
			p = (ArcNode *) malloc(sizeof(ArcNode));
			if(vex2 >=1){
				p->adjvex = vex2 -1;
				p->nextarc = NULL;
				p->weight = NULL;
				}
			temp = G.vertices[vex1-1].firstarc;
			while(temp) {temp1 = temp; temp = temp->nextarc;}
			if(temp1 ==NULL)
				G.vertices[vex1-1].firstarc = p;
			else
				temp1->nextarc = p;
			}
		return OK;
	}
Status CreateDN(ALGraph &G){ return OK;}
Status CreateUDG(ALGraph &G){
	int j=0,t = 0,t1=0;
	int vexnum, arcnum;	//�������ͱ������Ҷ��������δӱ��1��ʼ
		int i;
		ArcNode *p,*temp,*temp1=NULL;
		int vex1,vex2;
		printf("����������ͼ�Ķ������ͱ���:");
		scanf_s("%d%d",&vexnum,&arcnum);
		G.vexnum = vexnum;
		G.arcnum = arcnum;
		G.kind = 1;
		if(vexnum > MAX_VERTEX_NUM)
			{
			printf("�����������ͼ��󶥵���������ͼʧ��");
			return ERROR;
			}
		for(i=0;i<vexnum;i++) G.vertices[i].firstarc = NULL;
		printf("�����:\n");
		//������ĵ��ڽӵ�Ϊ��ֵ
		for(i=0;i<arcnum;i++){
			scanf_s("%d%d",&vex1,&vex2);
			t = vex1;t1 = vex2;
			for(j = 0; j < 2; j++){
				if(vex1 < 0) break;
				G.vertices[vex1-1].data = vex1;
				if(vex2 < 0) break;
				temp1 = NULL;
				p = (ArcNode *) malloc(sizeof(ArcNode));
				if(vex2 >=1){
					p->adjvex = vex2 -1;
					p->nextarc = NULL;
					p->weight = NULL;
					}
				temp = G.vertices[vex1-1].firstarc;
				while(temp) {temp1 = temp; temp = temp->nextarc;}
				if(temp1 ==NULL)
					G.vertices[vex1-1].firstarc = p;
				else
					temp1->nextarc = p;

				//����vex1��vex2��ֵ
				vex1 = t1; vex2 = t;
				}
			}
		return OK;
	}
Status CreateUDN(ALGraph &G){return OK;}
Status CreateALGraph(ALGraph &G){
	printf("�ڽӱ�洢�ṹ\n");
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

Status CreateG(ALGraph *G,int kind){
	int j=0,t = 0,t1=0;
	if(kind == 1)
		{
		int vexnum, arcnum;	//�������ͱ������Ҷ��������δӱ��1��ʼ
		int i;
		ArcNode *p,*temp,*temp1=NULL;
		int vex1,vex2;
		printf("����������ͼ�Ķ������ͱ���:");
		scanf_s("%d%d",&vexnum,&arcnum);
		G->vexnum = vexnum;
		G->arcnum = arcnum;
		G->kind = 1;
		if(vexnum > MAX_VERTEX_NUM)
			{
			printf("�����������ͼ��󶥵���������ͼʧ��");
			return ERROR;
			}
		for(i=0;i<vexnum;i++) (*G).vertices[i].firstarc = NULL;
		printf("�����:\n");
		//������ĵ��ڽӵ�Ϊ��ֵ
		for(i=0;i<arcnum;i++){
			scanf_s("%d%d",&vex1,&vex2);
			t = vex1;t1 = vex2;
			for(j = 0; j < 2; j++){
				if(vex1 < 0) break;
				(*G).vertices[vex1-1].data = vex1;
				if(vex2 < 0) break;
				temp1 = NULL;
				p = (ArcNode *) malloc(sizeof(ArcNode));
				if(vex2 >=1){
					p->adjvex = vex2 -1;
					p->nextarc = NULL;
					p->weight = NULL;
					}
				temp = (*G).vertices[vex1-1].firstarc;
				while(temp) {temp1 = temp; temp = temp->nextarc;}
				if(temp1 ==NULL)
					(*G).vertices[vex1-1].firstarc = p;
				else
					temp1->nextarc = p;

				//����vex1��vex2��ֵ
				vex1 = t1; vex2 = t;
				}
			}
		return OK;
		}
	if(kind == 2)
		{
		int vexnum, arcnum;	//�������ͱ������Ҷ��������δӱ��1��ʼ
		int i;
		ArcNode *p,*temp,*temp1=NULL;
		int vex1,vex2;
		printf("����������ͼ�Ķ������ͻ�����:");
		scanf_s("%d%d",&vexnum,&arcnum);
		G->vexnum = vexnum;
		G->arcnum = arcnum;
		if(vexnum > MAX_VERTEX_NUM)
			{
			printf("�����������ͼ��󶥵���������ͼʧ��");
			return ERROR;
			}
		for(i=0;i<vexnum;i++) (*G).vertices[i].firstarc = NULL;
		printf("�����:\n");
		//������ĵ��ڽӵ�Ϊ��ֵ
		for(i=0;i<arcnum;i++){
			temp1 = NULL;
			scanf_s("%d%d",&vex1,&vex2);
			(*G).vertices[vex1-1].data = vex1;
			if(vex2 > 0)
				(*G).vertices[vex2-1].data = vex2;
			p = (ArcNode *) malloc(sizeof(ArcNode));
			if(vex2 >=1){
				p->adjvex = vex2 -1;
				p->nextarc = NULL;
				p->weight = NULL;
				}
			temp = (*G).vertices[vex1-1].firstarc;
			while(temp) {temp1 = temp; temp = temp->nextarc;}
			if(temp1 ==NULL)
				(*G).vertices[vex1-1].firstarc = p;
			else
				temp1->nextarc = p;
			}
		return OK;
		}
	return OK;
	}
int FirstAdjVex(ALGraph G, int v){
	if(G.vertices[v].firstarc == NULL)	return -1;
	return G.vertices[v].firstarc->adjvex;
	}

int NextAdjVex(ALGraph G, int v, int w){
	ArcNode *p = G.vertices[v].firstarc;
	while(p){
		if(p->adjvex == w)
			break;
		p = p->nextarc;
		}
	if(p == NULL || p->nextarc == NULL) return -1;

	return p->nextarc->adjvex;
	}

void PrintG(ALGraph G, int kind){
	int vexnum=G.vexnum;
	int i;
	ArcNode *p;
	if(kind == 1)
		printf("ͼ�Ķ�����Ϊ%d�ͱ���Ϊ%d\n",G.vexnum,G.arcnum);
	else
		printf("ͼ�Ķ�����Ϊ%d�ͻ�����Ϊ%d\n",G.vexnum,G.arcnum);
	printf("\t\t\t\t������ڽӵ�\n");
	for(i = 0; i< vexnum; i++){
		printf("����%d �ڽӵ�:",G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while(p)
			{
			printf("%d ", p->adjvex + 1);
			p = p->nextarc;
			}
		printf("\n");
		}
	}

int ComputingDegree(ALGraph G){
	int i,j;
	int sum =0;
	ArcNode *p;
	for(i = 0; i<G.vexnum; i++){
		sum = 0;
		p = G.vertices[i].firstarc;
		while(p)
			{
			sum +=1;
			p = p->nextarc;
			}
		for(j=0; j < G.vexnum; j++){ 
			if(j == i) continue;
			p = G.vertices[j].firstarc;
			while(p)
			{
				if(p->adjvex == i)
					sum +=1;
				p = p->nextarc;
			}
			}
		printf("����:%d,����:%d\n",G.vertices[i].data,sum);
		}
	return sum;
	}

//ͼ�Ĺ������
void BFSTraverse(ALGraph G){
	int v,w,u;
	Boolean visited1[20];
	LinkQueue Q;
	for(v=0; v<G.vexnum; ++v) visited1[v] = FALSE;
	InitQueue(Q);
	for(v = 0; v < G.vexnum; ++v)
		if(!visited1[v]){
			visited1[v]=TRUE;
			printf("%d ",G.vertices[v].data);
			EnQueue(Q,v);
			while(QueueEmpty(Q)){
				DeQueue(Q,u);
				for(w = FirstAdjVex(G,u); w >=0; w=NextAdjVex(G,u,w))
					if(!visited1[w]){
						visited1[w]=TRUE;
						printf("%d ",G.vertices[w].data);
						EnQueue(Q,w);
						}
				}
			}
	}


Boolean visited[MAX_VERTEX_NUM];
void DFS(ALGraph G, int v){
	int w = -1;
	visited[v] = TRUE;
	printf("%d ",G.vertices[v].data);
	for(w = FirstAdjVex(G,v); w >=0; w = NextAdjVex(G,v,w))
		if(!visited[w]) DFS(G,w);
	}
//����ͼ��������ȱ���
void DFSTraverse(ALGraph G){
	int v;
	for(v = 0; v<G.vexnum; ++v) visited[v] = FALSE;
	for(v = 0; v<G.vexnum; ++v)
		if(!visited[v]) DFS(G,v);
	}

//----------------------------------
void FindInDegree(ALGraph G,int *indegree){
	int i,j;
	int sum =0;
	ArcNode *p;
	for(i = 0; i<G.vexnum; i++){
		sum = 0;
		p = G.vertices[i].firstarc;
		for(j=0; j < G.vexnum; j++){ 
			if(j == i) continue;
			p = G.vertices[j].firstarc;
			while(p)
				{
				if(p->adjvex == i)
					sum +=1;
				p = p->nextarc;
				}
			}
		indegree[i] = sum;
		}
	}

Status TopologicalSort(ALGraph G){
	//����ͼG�����ڽӱ�洢�ṹ
	//��G�޻�·�������G�Ķ����һ���������в�����OK������ERROR
	int i,j,count,k;
	Elemtype elem=0;
	int * indegree;
	indegree = (int *)malloc(sizeof(int) * MAX_VERTEX_NUM);
	LinkStack S;
	ArcNode *p;
	FindInDegree(G,indegree);
	InitSqStack(&S);
	for(i=0;i<G.vexnum; ++i)	//������ȶ���ջs
		if(!indegree[i]) PushSq(&S,i);	//���Ϊ0�߽�ջ
	count = 0;
	while(!IsEmpty_LinkStack(S)){
		PopSq(&S,&i);printf("%d->",G.vertices[i].data); ++count;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k = p->adjvex;
			if(!(--indegree[k])) PushSq(&S,k);
			}
		}
	printf("\n");
	if(count < G.vexnum) return ERROR;
	else	return OK;
	}