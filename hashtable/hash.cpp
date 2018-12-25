#include "hash.h"

int Hash(ElemType k){
	//hash 函数
	return k % 13;
	}

int EQ(ElemType a, ElemType b){
	//判断a与b是否相等，若相等，return 1
	//否则return 0
	if(a == b) return 1;

	return 0;
	}

void collision(ElemType k,int &p, int &c){
	//线性探测再散列解决从冲突，求得下一探查地址p
	//h(i) = (H(key) + di) MOD m (i=1,2,....k)
	//m 表表长 di 表示冲突的次数
	p = (Hash(k) + c) % 13;
	}

Status SearchHash(HashTable H, ElemType k, int &p, int &c){
	//在开放定址哈希表H中查找关键码为k的元素，若查找成功，以p指示待查数据
	//元素在表中位置，并返回SUCCESS;否则，以p指示插入位置，并返回UNSUCCESS
	//c用以计冲突次数，其初值置零，供建表插入时参考
	p = Hash(k);	//求得哈希地址
	while(H.elem[p] !=INT_MAX &&	//该位置中填有记录
		!EQ(k,H.elem[p]))		//并且关键字不相等
		collision(k,p,++c);		//求得下一探测地址p
	if(EQ(k,H.elem[p]))
		return SUCCESS;			
	else return UNSUCCESS;		//查找不成功(H.elem[p] == INT_MAX)
	//p返回的是插入位置
	}

Status InsertHash(HashTable &H,ElemType e){
	//查找不成功时插入数据元素e到开放定址哈希表H中，并返回OK，若冲突次数
	//过大，则重建哈希表
	int c = 0;
	int p = 0;
	if(SearchHash(H,e,p,c))
		return DUPLICATE;			//表中已有与e有相同关键字的元素
	else if(1){						//冲突次数c未达到上限
		H.elem[p] = e; ++H.count; return OK;}	//插入e
	else
		{
		//RecreateHashTable(H);  重建哈希表
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
