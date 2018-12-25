#define SQLIST_H_INCLUDED
#include "DS.h"
#define MAXQSIZE 100   //最大队列长度

typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;  //头指针
	QueuePtr rear;   //尾指针
}LinkQueue;	//链队列的结构体

//---------------链队列的操作----------------
void Linkmenu();
Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType &e);
Status DeQueue(LinkQueue &Q, QElemType &e);
Status QueueEmpty(LinkQueue &Q);