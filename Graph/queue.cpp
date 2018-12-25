#include "queue.h"

Status InitQueue (LinkQueue &Q){
	//构造空队列
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType &e){
	//插入元素e为Q的新的队尾元素
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK;
	//否则返回ERROR
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

Status QueueEmpty(LinkQueue &Q){
	if(Q.front == Q.rear) return ERROR;
	return OK;
	}