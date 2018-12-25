#include "BinaryTree.h"
#include "queue.h"
#include "stack.h"

/*------------------------------二叉树的基本算法----------------------------*/
Status CreateBiTree(BiTree &T){
	/*
	*      以二叉链表创建二叉树-------算法描述如下:
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
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch;

		//构造左子树
		CreateBiTree(T->lchild);

		//构造右子树
		CreateBiTree(T->rchild);
		}
	return OK;
	}

void preOrder(BiTree T){
	/*
	*    先序遍历二叉树---------算法描述如下:
	* 若二叉树为空，执行空操作，否则依次执行以下的3个操作:
	*    (1) 输出该结点的值
	*    (2) 按照先序遍历该结点的左子树
	*    (3) 按照先序遍历该结点的右子树
	*/
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
		}
	}

void midOrder(BiTree T){
	/*
	*      中序遍历二叉树---------算法描述如下:
	*  判断当前结点是否为空，若空，执行空操作，否则依次执行以下3个操作:
	*      (1) 按照中序遍历当前结点的左子树
	*		(2) 输出当前结点元素的值
	*      (3) 按照中序遍历当前结点的右子树
	*/
	if(T){
		midOrder(T->lchild);
		printf("%c",T->data);
		midOrder(T->rchild);
		}
	}

void posOrder(BiTree T){
	/*
	*     后序遍历二叉树---------算法描述如下:
	*  判断当前结点是否为，若空，执行空操作，否则依次执行以下的3个操作:
	*        (1)按照后序遍历当前结点的左子树
	*        (2)按照后序遍历当前结点的右子树
	*        (3)输出当前结点元素的值
	*/
	if(T){
		posOrder(T->lchild);
		posOrder(T->rchild);
		printf("%c",T->data);
		}
	}

Status preTraverse(BiTree T){
	/*
	*        非递归先序遍历二叉树----------算法描述如下:	
	*  根据先序遍历访问的顺序，优先访问根结点，然后再分别访问左孩子和右孩
	* 子。即对于任一结点，其可看做是根结点，因此可以直接访问，访问完之后，
	* 若其左孩子不为空，按相同规则访问它的左子树；当访问其左子树时，再访问
	* 它的右子树。因此其处理过程如下：
	*   对于任一结点P：
	*     (1)访问结点P，并将结点P入栈;
	*     (2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作,
	*  并将栈顶结点的右孩子置为当前的结点P，循环至1;若不为空，则将P的左孩子
	*  置为当前的结点P;
	*     (3)直到P为NULL并且栈为空，则遍历结束。
	*/
	LinkStack S;
	BiTree p = T;
	InitStack(&S);
	while(p!=NULL||!StackEmpty(S))
		{
		while(p!=NULL)
			{
			printf("%c",p->data);
			Push(&S,p);
			p=p->lchild;
			}
		if(!StackEmpty(S))
			{
			Pop(&S,&p);
			p=p->rchild;
			}
		}

	return OK;
	}

Status midTraverse(BiTree T){
	/*
	*     非递归中序遍历二叉树---------------算法描述如下
	*   根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又
	* 可以看做一根结点，然后继续访问其左孩子结点，直到遇到左孩子结点为空的
	* 结点才进行访问，然后按相同的规则访问其右子树。因此其处理过程如下：
	* 对于任一结点P
	*    (1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前
	*  结点P再进行相同的处理；
	*    (2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后
	*  将当前的P置为栈顶结点的右孩子；
	*    3)直到P为NULL并且栈为空则遍历结束
	*/
	LinkStack S;
	BiTree p;

	//根指针进栈
	InitStack(&S); Push(&S,T);

	while(!StackEmpty(S)){

		//遍历当前结点的左子树
		while(GetTop(&S,&p) &&p) Push(&S, p->lchild);

		//空指针退栈
		Pop(&S,&p);

		//输出最左子树结点，然遍历右子树
		if(!StackEmpty(S)){
			Pop(&S,&p); 
			printf("%c",p->data);
			Push(&S,p->rchild);
			}
		}
	return OK;
	}

Status posTraverse(BiTree T){
	/*
	*     非递归后序遍历二叉树-----------算法描述如下
	*  根据后序遍历可知，根结点在左孩子和右孩子访问之后才能访问，
	*  因此对于任一结点P:
	*		(1)先将其入栈。如果P不存在左孩子和右孩子,则可以直接访问它；或者
	*    P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可
	*	 以直接访问该结点。
	*	    (2)若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了
	*	 每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在
	*	 根结点前面被访问。
	*      (3)直到栈为空，遍历结束。
	*/
	LinkStack S;
	BiTree p1,p2=NULL,temp;
	InitStack(&S);
	Push(&S,T);
	while(!StackEmpty(S))
		{
		GetTop(&S,&p1);

		//当前结点没有孩子结点或者孩子节点都已被访问过
		if((p1->lchild==NULL&&p1->rchild==NULL)||
			(p2!=NULL&&(p2==p1->lchild||p2==p1->rchild)))   //为什么这里表示的是两个孩子结点都被访问过了
			{
			printf("%c",p1->data); 

			// p2存先前被访问的结点
			Pop(&S,&temp);p2=p1; 
			}
		else
			{   
			//左或右孩子没有被访问，则该结点入栈
			if(p1->rchild!=NULL)
				Push(&S,(p1->rchild));
			if(p1->lchild!=NULL)    
				Push(&S,p1->lchild);
			}
		}    

	return OK;
	}

Status LevelOrderTraverse(BiTree T){
	/*
	*    层次遍历二叉树---------算法描述如下
	*  根据层次遍历的思想是从左到右，然后从上到下
	*    对于任一结点p:
	*		(1) 根结点出队，并访问；
	*      (2) 根结点的左右孩子不能为空，然后依次入队；
	*      (3) 队列为空，则遍历结束。
	*/
	LinkQueue Q; BiTree p;

	//若是空树则直接返回 
	if ( !T) return OK;

	//创建并初始化队列Q
	InitQueue( Q );     
	EnQueue( Q, T); 
	while ( !IsEmptyQueue( Q ) ) { 
		DeQueue( Q, p ); 
		printf("%c", p->data);

		//左右孩子不为空，分别入队
		if ( p->lchild ) EnQueue( Q, p->lchild );  
		if ( p->rchild) EnQueue( Q, p->rchild);
		} 
	return OK;
	}

/*-----------------------------------二叉树的基本运用----------------------*/
void preOrderLeaf(BiTree T){
	/*
	*        先序遍历输出二叉树的叶子结点----算法描述如下
	*  对于每个当前结点P:
	*		(1) 判断P是否存在左结点和右结点为空且P不为空，若存在，访问结点P，反之亦然；
	*      (2) 运用该方法访问P的左子树;
	*		(3) 运用该方法访问P的右子树。
	*/
	if(T){
		//结点T的左结点或右结点为空
		if(T->lchild==NULL || T->rchild==NULL) printf("结点P的值为:%d",T->data);

		//否则递归依次访问结点T的左孩子、右孩子
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}

	}

int leafCount=0;
void leaf_one(BiTree T){
	/*
	*        用全局变量先序遍历输出二叉树的叶子的数目----算法描述如下
	*  对于每个当前结点P:
	*		(1) 判断P是否存在左结点和右结点为空且P不为空，若存在，结点数目加一，反之亦然；
	*      (2) 运用该方法访问P的左子树;
	*		(3) 运用该方法访问P的右子树。
	*/
	if(T){
		//结点T的左结点或右结点为空，叶子数目加一
		if(T->lchild==NULL || T->rchild==NULL) ++leafCount;

		//否则递归依次访问结点T的左孩子、右孩子
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}

	}

int leaf_two(BiTree T){
	/*
	*        用全局变量先序遍历输出二叉树的叶子的数目----算法描述如下
	*  对于每个当前结点P:
	*		(1) 判断P是否存在左结点和右结点为空且P不为空，若存在，结点数目加一，反之亦然；
	*      (2) 运用该方法访问P的左子树;
	*		(3) 运用该方法访问P的右子树。
	*/
	static int leafCount_two = 0;
	if(T){
		//结点T的左结点或右结点为空，叶子数目加一
		if(T->lchild==NULL || T->rchild==NULL) ++leafCount_two;

		//否则递归依次访问结点T的左孩子、右孩子
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}
	return leafCount_two;
	}

int leaf_three(BiTree T){
	/*
	*     递归计算叶子结点数目-------算法描述如下
	*  对于任意结点P:
	*    (1)  当结点P为空时，叶子的数目是0；
	*    (2)  当结点P的左右孩子都为空的时候，叶子的数目是1；
	*    (3)  否则当前结点的叶子的数目是左孩子结点叶子数目加上右孩子结点叶子的数目
	*/
	int leafCount;
	if(!T) leafCount = 0;
	else if((T->lchild==NULL) && (T->rchild == NULL)) leafCount = 1;
	else leafCount = leaf_three(T->lchild) + leaf_three(T->rchild);
	return leafCount;
	}

int postTreeDepth(BiTree T){
	/*
	*  递归计算树的深度----------算法描述如下
	* 对于任意结点P:
	*		(1) 当结点P为空，深度为0；
	*		(2) 否则，结点p的深度左子树和右子树的较大值加一
	*/
	int depth,Rdepth,Ldepth;
	if(!T) depth=0;
	else { 
		//左子树的深度
		Rdepth = postTreeDepth(T->lchild); 
		//右子树的深度
		Ldepth=postTreeDepth(T->rchild); 
		//最大深度
		depth = Rdepth > Ldepth ? Rdepth : Ldepth;
		}
	return depth;
	}