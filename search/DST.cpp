#include "DST.h"

int EQ(ElemType a, ElemType b){
	//判断a与b是否相等，若相等，return 1
	//否则return 0
	if(a == b) return 1;

	return 0;
	}

int LT(ElemType a,ElemType b){
	//若 a < b; return 1
	//否则 return 0
	if(a < b) return 1;

	return 0;
	}

Status DeleteBst(BiTree &T,ElemType e);
BiTree SearchBST(BiTree T, ElemType e){
	//在根指针T所指二叉排序树中递归地查找某关键字等于e 的数据元素，
	//若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
	if((!T) || EQ(e,T->data)) return (T);	//查找结束
	else if(LT(e,T->data)) return SearchBST(T->lchild,e);  //在左子树中继续查找
	else return SearchBST(T->rchild,e);						//在右子树中继续查找
	}

Status SearchBST(BiTree T,ElemType e, BiTree f,BiTree &p){
	//在根指针T所指向二叉排序树中递归地查找其关键字等于e的数据元素，若查找成功，
	//则指针p指向该数据元素节点，并返回TRUE，否则指针p指向查找路径上访问的最后
	//一个结点并返回FALSE,指针f指向T的双亲，器初始调用为NULL----根结点的双亲为NULL
	if(!T) {p=f; return FALSE;}									//查找不成功
	else if (EQ(e,T->data)) {p=T; return TRUE;}					//查找结束
	else if(LT(e,T->data)) return SearchBST(T->lchild,e,T,p);  //在左子树中继续查找
	else return SearchBST(T->rchild,e,T,p);						//在右子树中继续查找
	}

Status InsertBST(BiTree &T,ElemType e){
	//当二叉排序树T，中不存在关键字等于e的数据元素时，插入e并返回TRUE
	//否则返回FALSE
	BiTree p,s;
	if(!SearchBST(T,e,NULL,p)){				//查找不成功
		s = (BiTree) malloc(sizeof(BiTNode));
		s->data = e; s->lchild = s->rchild = NULL;
		if(!p) T=s;			//被插接点*s为新的根结点
		else if (LT(e,p->data)) p->lchild = s; //被插接点*s为左孩子
		else p->rchild = s;
		return TRUE;
		}
	else
		return FALSE;
	}

Status Delete(BiTree &p){
	//从二叉排序树中删除结点p，并重接它的左或右子树
	BiTree q,s;
	if(!p->rchild) { //右子树空则需要重接它的左子树
		q = p; p=p->lchild; free(q);
		}
	else if(!p->lchild) { //左子树空则需要重接它的右子树
		q=p; p=p->rchild; free(q);
		}
	else{//左右子树均不空
		q=p; s=p->lchild;
		while(s->rchild){q=s;s=s->rchild;} //转左，然后向右到尽头----直接前驱
		p->data = s->data;	//s指向被删除结点的"前驱"
		if(q!=p) q->rchild = s->lchild;	//重接*q的右子树
		else q->lchild = s->lchild;		//重接*q的左子树
		delete s;
		}
	return TRUE;
	}

Status DeleteBST(BiTree &T, ElemType e){
	//若二叉排序树T中存在关键字e的数据元素时，则删除该数据元素结点
	//并返回TRUE，否则返回FALSE
	if(!T) return FALSE;
	else {
		if(EQ(e,T->data)) return Delete(T);	//找到关键字等于e的元素，并删除
		else if(LT(e,T->data)) return DeleteBST(T->lchild,e);
		else return DeleteBST(T->rchild, e);
		}
	}