#define SQLIST_H_INCLUDED
#include "DS.h"
#define MAXQSIZE 100   //�����г���

typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;  //ͷָ��
	QueuePtr rear;   //βָ��
}LinkQueue;	//�����еĽṹ��

//---------------�����еĲ���----------------
void Linkmenu();
Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType &e);
Status DeQueue(LinkQueue &Q, QElemType &e);
Status QueueEmpty(LinkQueue &Q);