#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include "DS.h"

typedef BiTree QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;  //ͷָ��
	QueuePtr rear;   //βָ��
}LinkQueue;	//�����еĽṹ��

Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType &e);
Status DeQueue(LinkQueue &Q, QElemType &e);
Status IsEmptyQueue(LinkQueue &Q);
#endif // SQLIST_H_INCLUDED