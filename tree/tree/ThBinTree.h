#include "DS.h"

typedef enum PointerTag {Link,Thread};

typedef int TElemType;
typedef struct BiThrNode{
	TElemType data;		//数据域
	struct BiThrNode *Lchild,*Rchild;	//左右孩子指针域
	PointerTag Ltag,Rtag;				//左右标志
	} BiThrNode, *BiThrTree;

/*-------------------基本算法---------------*/
Status CreateBiThrTree(BiThrTree &T);
Status PreOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);
Status PostOrderThreading(BiThrTree &Thrt,BiThrTree T);
Status PreOrderTraverse_Thr(BiThrTree T);
Status InOrderTraverse_Thr(BiThrTree T);
Status PostOrderTraverse_Thr(BiThrTree T);

/*------------------基本运用---------------*/


