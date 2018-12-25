#include "hash.h"

int Hash(ElemType k){
	//hash ����
	return k % 13;
	}

int EQ(ElemType a, ElemType b){
	//�ж�a��b�Ƿ���ȣ�����ȣ�return 1
	//����return 0
	if(a == b) return 1;

	return 0;
	}

void collision(ElemType k,int &p, int &c){
	//����̽����ɢ�н���ӳ�ͻ�������һ̽���ַp
	//h(i) = (H(key) + di) MOD m (i=1,2,....k)
	//m ��� di ��ʾ��ͻ�Ĵ���
	p = (Hash(k) + c) % 13;
	}

Status SearchHash(HashTable H, ElemType k, int &p, int &c){
	//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���Ϊk��Ԫ�أ������ҳɹ�����pָʾ��������
	//Ԫ���ڱ���λ�ã�������SUCCESS;������pָʾ����λ�ã�������UNSUCCESS
	//c���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο�
	p = Hash(k);	//��ù�ϣ��ַ
	while(H.elem[p] !=INT_MAX &&	//��λ�������м�¼
		!EQ(k,H.elem[p]))		//���ҹؼ��ֲ����
		collision(k,p,++c);		//�����һ̽���ַp
	if(EQ(k,H.elem[p]))
		return SUCCESS;			
	else return UNSUCCESS;		//���Ҳ��ɹ�(H.elem[p] == INT_MAX)
	//p���ص��ǲ���λ��
	}

Status InsertHash(HashTable &H,ElemType e){
	//���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�������OK������ͻ����
	//�������ؽ���ϣ��
	int c = 0;
	int p = 0;
	if(SearchHash(H,e,p,c))
		return DUPLICATE;			//����������e����ͬ�ؼ��ֵ�Ԫ��
	else if(1){						//��ͻ����cδ�ﵽ����
		H.elem[p] = e; ++H.count; return OK;}	//����e
	else
		{
		//RecreateHashTable(H);  �ؽ���ϣ��
		return UNSUCCESS;
		}
	}

Status InsertHash(LinkNode *p, ElemType e,int length){
	int index = Hash(e);
	LinkList q,temp,t;
	if(p[index].data == INT_MAX){p[index].data = e; return OK;}
	q = &(p[index]);
	while(q){
		if(q->data == e) return UNSUCCESS;
		if(q->data < e){
			temp = (LinkList) malloc(sizeof(LinkNode));
			temp->data = q->data;
			temp->next = q->next;
			q->next = temp;
			q->data = e;
			return OK;
			}
		t =  q;
		q = q->next;
		}
	t->next = (LinkList) malloc(sizeof(LinkNode));
	t->next->next = NULL;
	t->next->data = e;
	return SUCCESS;	
	}
