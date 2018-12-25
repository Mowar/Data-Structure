#include "hash.h"

void menu(){
	printf("\t\t\t��ϣ��Ļ�������\n");
	printf("\t\t 1: ���ԭʼ����\n");
	printf("\t\t 2: ���Գ�ͻ������HashTable�������HashTable\n");
	printf("\t\t 3: ����ַ������HashTable�������HashTable\n");
	printf("\t\t 4: ������ַ�ʽ������ƽ�����ҳ���\n");
	printf("\t\t 0: �˳�����\n");
	printf("��ѡ����Ĳ���:");
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
			printf("�洢λ��:%d Ԫ��:%d\n",i,H.elem[i]);
	}

int main(void){
	ElemType hashsize[] = {19,14,23,1,68,20,84,27,55,11,10,79};
	int m = 13;  //��ϣ��ĳ���
	int length = 12; //ԭʼ���ݵĸ���
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
			printf("ԭʼ����\n");
			printTable(hashsize,length);
			break;
		case 2:
			//��������̽�ⷨ����HashTable
			for(i = 0; i< length;i++) InsertHash(H,hashsize[i]);
			Disp_HashTable(H);
			break;
		case 3:
			//��������ַ������HashTable
			for(i = 0; i< length; i++) InsertHash(p,hashsize[i],m);
			//�������ַ��������HashTable
			for(i = 0; i< m; i++){printf("�洢λ��:%d",i);printf("�洢��Ԫ��Ϊ:");Disp_Linklist(&p[i]);}
			break;
		case 4:
			printf("���Գ�ͻ����ƽ�����ҳ���:%f\n",mean_length(H));
			printf("����ַ����ƽ�����ҳ���:%f\n",mean_length(p,m));
			break;
		case 0:
			return 0;
		default :
			printf("�������������ѡ��\n");
			}
		}
	return 0;
	}