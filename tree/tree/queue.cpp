#include "queue.h"

Status InitQueue (LinkQueue &Q){
	//����ն���
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status IsEmptyQueue(LinkQueue &Q){

	if(Q.front == Q.rear) return TRUE;
	return FALSE;
}

Status EnQueue(LinkQueue &Q,QElemType &e){
	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK;
	//���򷵻�ERROR
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}