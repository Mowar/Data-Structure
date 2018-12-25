#include "hash.h"

void menu(){
	printf("\t\t\t哈希表的基本操作\n");
	printf("\t\t 1: 输出原始数据\n");
	printf("\t\t 2: 线性冲突法创建HashTable及输出该HashTable\n");
	printf("\t\t 3: 链地址法创建HashTable及输出该HashTable\n");
	printf("\t\t 4: 输出两种方式创建的平均查找长度\n");
	printf("\t\t 0: 退出程序\n");
	printf("请选择你的操作:");
	}

void printTable(ElemType *p,int length){
	int i = 0;
	for(i = 0; i < length; i++){
		printf("%d ",p[i]);
		}
	printf("\n");
	}
void Disp_Linklist(LinkList L)
	{
	LinkList p;
	p = L;
	while(p)
		{
		if(p->data !=INT_MAX)printf("%d ", p->data);
		p = p->next;
		}
	printf("\n");
	}

double mean_length(HashTable H){
	double a = H.count * 1.0 / H.sizeindex;
	return (1.0 / 2) *( 1.0 + 1 / (1.0 - a));
	}

double mean_length(LinkNode *p, int size){
	int i = 0;
	int record = 0;
	double a = 0.0;
	LinkList q;
	for(i = 0; i < size; i++)
		{
		q = &p[i];
		while(q) {if(q->data !=INT_MAX) record = record + 1;  q = q->next;}
		}
	a = record * 1.0 / size;
	return 1.0 + a / 2;
	}

void Disp_HashTable(HashTable H){
	int i = 0;
	for(i = 0; i < 13;i++)
		if(H.elem[i] !=INT_MAX)
			printf("存储位置:%d 元素:%d\n",i,H.elem[i]);
	}

int main(void){
	ElemType hashsize[] = {19,14,23,1,68,20,84,27,55,11,10,79};
	int m = 13;  //哈希表的长度
	int length = 12; //原始数据的个数
	HashTable H;
	int choice;
	LinkNode * p = (LinkNode *) malloc(sizeof(LinkNode) * m);
	H.elem = (ElemType *) malloc(sizeof(ElemType) * m);
	H.sizeindex = m;
	H.count = 0;
	int i = 0;
	for(i = 0; i < m; i++) H.elem[i] = INT_MAX;
	for(i = 0; i < m; i++) {p[i].data = INT_MAX; p[i].next = NULL;}
	while(1){
		menu();
		scanf_s("%d",&choice);
		switch(choice){
		case 1:
			printf("原始数据\n");
			printTable(hashsize,length);
			break;
		case 2:
			//采用线性探测法创建HashTable
			for(i = 0; i< length;i++) InsertHash(H,hashsize[i]);
			Disp_HashTable(H);
			break;
		case 3:
			//采用链地址法创建HashTable
			for(i = 0; i< length; i++) InsertHash(p,hashsize[i],m);
			//输出链地址法创建的HashTable
			for(i = 0; i< m; i++){printf("存储位置:%d",i);printf("存储的元素为:");Disp_Linklist(&p[i]);}
			break;
		case 4:
			printf("线性冲突法的平均查找长度:%f\n",mean_length(H));
			printf("链地址法的平均查找长度:%f\n",mean_length(p,m));
			break;
		case 0:
			return 0;
		default :
			printf("输入错误，请输入选择\n");
			}
		}
	return 0;
	}