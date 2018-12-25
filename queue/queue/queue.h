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

typedef struct{
	QElemType *base;	//初始化的动态分配存储空间
	int front;	//头指针，若队列不空，指向队列头元素
	int rear;	//尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;	//循环队列的结构体

//---------------链队列的操作----------------
void Linkmenu();
Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,QElemType &e);
Status DeQueue(LinkQueue &Q, QElemType &e);

//-------------循环队列的操作---------------
void Sqmenu();
Status InitSqQueue(SqQueue &Q);
Status EnSqQueue(SqQueue &Q,QElemType);
Status DeSqQueue(SqQueue &Q, QElemType &e);