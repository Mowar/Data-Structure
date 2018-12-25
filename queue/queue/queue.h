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

typedef struct{
	QElemType *base;	//��ʼ���Ķ�̬����洢�ռ�
	int front;	//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;	//βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
}SqQueue;	//ѭ�����еĽṹ��

//---------------�����еĲ���----------------
void Linkmenu();
Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType &e);
Status DeQueue(LinkQueue &Q, QElemType &e);

//-------------ѭ�����еĲ���---------------
void Sqmenu();
Status InitSqQueue(SqQueue &Q);
Status EnSqQueue(SqQueue &Q,QElemType);
Status DeSqQueue(SqQueue &Q, QElemType &e);