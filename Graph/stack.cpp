#include "stack.h"

//Á´Õ»³õÊ¼»¯
Status InitSqStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)return ERROR;
	S->top->next = NULL;
	S->count = 0;
	return OK;
}

//Á´Õ»ÈëÕ»
Status PushSq(LinkStack *S, int n)
{
		LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
		if(!s)return ERROR;
		s->data = n;
		s->next = S->top->next;
		S->top->next = s;
		S->count++;
	return OK;

}

Status IsEmpty_LinkStack(LinkStack S)
{
	if(S.top->next == NULL){return TRUE;}
	else{return FALSE;}
}

//Á´Õ»³öÕ»
Status PopSq(LinkStack *S, Elemtype *e)
{
	LinkStackPtr p;
	if(IsEmpty_LinkStack(*S))
	{
		return ERROR;
	}
	p = S->top->next;
	*e = p->data;
	S->top->next = p->next;
	free(p);
	S->count--;
	return OK;

}