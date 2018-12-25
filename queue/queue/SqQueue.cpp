#include "queue.h"

void Sqmenu()
{
    printf("\t\t\t  循环队列的基本操作\n\n");
    printf("\t\t\t1.初始化循环队列\n");
    printf("\t\t\t2.循环队列入 队\n");
    printf("\t\t\t3.循环队列出队\n");
    printf("\t\t\t0.返回上一层\n\n");
}

Status InitSqQueue(SqQueue &Q){
	//构造一个空队列Q
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

Status EnSqQueue(SqQueue &Q,QElemType e){
	//插入元素e为Q的新的队尾元素
	if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; //队列满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeSqQueue(SqQueue &Q, QElemType &e){
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK;
	//否则返回ERROR
	if(Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}