#include "queue.h"

void Sqmenu()
{
    printf("\t\t\t  ѭ�����еĻ�������\n\n");
    printf("\t\t\t1.��ʼ��ѭ������\n");
    printf("\t\t\t2.ѭ�������� ��\n");
    printf("\t\t\t3.ѭ�����г���\n");
    printf("\t\t\t0.������һ��\n\n");
}

Status InitSqQueue(SqQueue &Q){
	//����һ���ն���Q
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

Status EnSqQueue(SqQueue &Q,QElemType e){
	//����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; //������
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeSqQueue(SqQueue &Q, QElemType &e){
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK;
	//���򷵻�ERROR
	if(Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}