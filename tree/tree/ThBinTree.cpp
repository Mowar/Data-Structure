#include "ThBinTree.h"

Status CreateBiThrTree(BiThrTree &T){
	/*
	*      以二叉线索链表创建线索二叉树-------算法描述如下:
	*  输入结点元素，判断结点元素是否是空树标识，若是，执行空操作；
	* 否则依次执行下列操作:
	*     (1) 创建该结点元素
	*     (2) 按照该方法创建该结点的左子树:T->Lchild，即递归调用该函数
	*     (3) 按照该方法创建该结点的右子树:T->Rchild，即递归调用该函数
	*/
	char ch = getchar();
	if(ch ==' ') T=NULL;
	else{
		//生成根节点
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
		T->data = ch;

		//构造左子树
		CreateBiThrTree(T->Lchild);

		//构造右子树
		CreateBiThrTree(T->Rchild);
		}
	return OK;
	}

void PreThreading(BiThrTree p, BiThrTree &pre){
	/*
	 *         先序结点p线索化-------算法描述如下
	 *   对于每个结点p,有:
	 *      (1)判断结点是否为空，若为空，则返回
	 *      (2)当前结点线索化。当左孩子为空的时候，则左孩子指向前
	 *	驱；当前驱的右孩子为空时，前驱的右孩子指向当前结点p。
	 *		(3)左孩子线索化；
	 *      (4)右孩子线索化。
	 */
	if(p){
		//前驱线索
		if(!p->Lchild){p->Ltag=Thread;p->Lchild=pre;}
		//后继线索
		if(!pre->Rchild){pre->Rtag=Thread;pre->Rchild=p;}
		pre = p;

		//左子树线索化
		PreThreading(p->Lchild,pre);

		//右子树线索化
		PreThreading(p->Rchild,pre);
		}
	}
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T){

	}

void InThreading(BiThrTree p, BiThrTree &pre);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

void PostThreading(BiThrTree p, BiThrTree &pre);
Status PostOrderThreading(BiThrTree &Thrt,BiThrTree T);

Status PreOrderTraverse_Thr(BiThrTree T);
Status InOrderTraverse_Thr(BiThrTree T);
Status PostOrderTraverse_Thr(BiThrTree T);