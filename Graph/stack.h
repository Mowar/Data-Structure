#define SQLIST_H_INCLUDED

#include "DS.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Elemtype;

typedef struct StackNode
{
   Elemtype data;		//�ڵ�������
   struct StackNode *next;   //�ڵ�ָ����
}StackNode,*LinkStackPtr;   //�ڵ�ָ��

typedef struct LinkStack
{ 
   LinkStackPtr top;  //ջ��ָ��
   int count;            //ջ��Ԫ�ظ���
}LinkStack;

Status IsEmpty_LinkStack(LinkStack S);
Status InitSqStack(LinkStack *s);
Status PushSq(LinkStack *s, int n);
Status PopSq(LinkStack *s, Elemtype *e);
