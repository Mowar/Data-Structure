#include "list.h"

void Linkmenu()
	{
	printf("\t\t\t   �������������\n\n");
	printf("\t\t\t1.��  ��  ��  ��  ��\n");
	printf("\t\t\t2.��  ��  ��  ��  ��\n");
	printf("\t\t\t3.��  ��  �� �� �� ��\n");
	printf("\t\t\t4.��  ��  ��  ��\n");
	printf("\t\t\t5.ɾ  ��  ż �� �� ��\n");
	printf("\t\t\t6.�� �� ֵ �� �� �� �� ��\n");
	printf("\t\t\t7.��  �� �� �� ��  ��  �� ��\n");
	printf("\t\t\t8.��  �� �� �� ��  ��  �� ��\n");
	printf("\t\t\t9.��  ��  ��  ��\n");
	printf("\t\t\t0.��          ��\n\n");
	}

/*��ʼ���ձ�*/
Status Init_Linklist(LinkList &L)
	{
	L=(LinkList)malloc(sizeof(node));
	if(!L) return ERROR;
	L->next=NULL;
	return OK;
	}

/*β�巨����������*/
Status Creat_Linklist(LinkList &L)
	{
	int x;
	LinkList p,rear;
	Init_Linklist(L);
	rear = L;
	printf("����-1��ʾ�������\n");
	while(scanf_s("%d",&x),x != -1)
		{
		p = (LinkList)malloc(sizeof(node));
		if(!p) return ERROR;
		p->data = x;
		rear->next = p;
		rear = p;
		}
	rear->next = NULL;
	return OK;
	}

/*���������*/
void Disp_Linklist(LinkList L)
	{
	LinkList p;
	p = L->next;
	while(p)
		{
		printf("%d ", p->data);
		p = p->next;
		}
	printf("\n");
	}

/*���㵥������*/
int length_Linklist(LinkList L)
	{
	int count = 0;   /*count��ʾ��������*/
	LinkList p;
	p = L->next;
	while(p){
		count += 1;
		p = p->next;
		}
	return count;
	}

/*����������*/
void Reverse_Linklist(LinkList L)
	{
	LinkList p, q,temp,temp1;

	//��һ�ַ���
	/*p = L->next;
	L->next = NULL;
	while(p){
	temp = (LinkList)malloc(sizeof(node));
	temp->data = p->data;
	q = L->next;
	L->next = temp;
	temp->next = q;
	temp1 = p->next;
	free(p);
	p = temp1;
	}
	*/

	// �ڶ��ַ���
	if(!L->next || !L->next->next) return ; //û����Ԫ�ڵ����ֻ��һ���ڵ�Ԫ��
	p = L->next->next;
	L->next->next=NULL;
	while(p){
		q = L->next;
		temp = p;
		L->next = temp;
		p =p->next;
		temp->next = q;
		}

	}

/*ɾ��ֵΪż���Ľ��*/
void DelEven_Linklist(LinkList L)
	{
	/*
	 *�������
	 * q=p->next
	 * p->next = q->next
	 * free(q)
	 */
	LinkList p, q;
	p = L->next;
	q = L;
	while(p){
		if(abs(p->data) %2 == 0 ){ q->next = p->next; free(p);p=q->next;}
		else {q=q->next;p=p->next;}
		}

	}

/*�����������в���Ԫ�أ�������Ȼ���򣬲���ɹ�����OK������ʧ�ܷ���ERROR*/
Status Insert_Linklist(LinkList L, int x)
	{
	LinkList p,q;
	p = L;
	q = (LinkList)malloc(sizeof(node));
	if(!q) return ERROR;
	q->data = x;
	q->next = NULL;
	while(p->next){
		//�ٶ���������������
		if(p->next->data >= x){
			q->next = p->next;
			p->next = q;
			return OK;
			}
		p = p->next;
		}
	if(!q->next) p->next = q;
	return OK;
	}

/*�����ǵݼ��������������ɹ�����OK������ʧ�ܷ���ERROR*/
Status CreatOrder_Linklist(LinkList &L)
	{
	int x;
	Init_Linklist(L);
	printf("����-1��ʾ�������\n");
	while(scanf_s("%d",&x),x != -1)Insert_Linklist(L,x);
	return OK;
	}

/*�����ǵݼ���������La��Lb�ϲ���һ���ǵ�����������Lc*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
	{
	Init_Linklist(Lc);
	LinkList p,q;
	p = La->next;
	q = Lb->next;
	// ʹLc�������
	while(p){
		Insert_Linklist(Lc,p->data);
		p = p->next;
		}
	while(q){
		Insert_Linklist(Lc,q->data);
		q = q->next;
		}
	//�ǵ���
	Reverse_Linklist(Lc);
	}

/*�����ǵݼ���������La��Lb�ϲ���һ���ǵݼ���������Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
	{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	pc = Lc = La;
	while(pa && pb)
		{
		if(pa->data <= pb->data)
			{
			pc->next = pa; pc = pa; pa = pa->next;
			}
		else
			{
			pc->next = pb; pc = pb; pb = pb->next;
			}
		}
	pc->next = pa ? pa : pb;
	free(Lb);
	}

/*����La��ֵ�ֽ����������Laȫ��Ϊ������Lbȫ��Ϊż��*/
void Split_Linklist(LinkList La, LinkList &Lb)
	{
	LinkList p, q;
	Init_Linklist(Lb);
	p = La->next;
	q = La;
	while(p){
		if(abs(p->data) %2 == 0 ){ q->next = p->next; Insert_Linklist(Lb,p->data);free(p);p=q->next;}
		else {q=q->next;p=p->next;}
		}
	}
