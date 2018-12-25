#include "BinaryTree.h"
#include "queue.h"
#include "stack.h"

/*------------------------------�������Ļ����㷨----------------------------*/
Status CreateBiTree(BiTree &T){
	/*
	*      �Զ���������������-------�㷨��������:
	*  ������Ԫ�أ��жϽ��Ԫ���Ƿ��ǿ�����ʶ�����ǣ�ִ�пղ�����
	* ��������ִ�����в���:
	*     (1) �����ý��Ԫ��
	*     (2) ���ո÷��������ý���������:T->Lchild�����ݹ���øú���
	*     (3) ���ո÷��������ý���������:T->Rchild�����ݹ���øú���
	*/
	char ch = getchar();
	if(ch ==' ') T=NULL;
	else{
		//���ɸ��ڵ�
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch;

		//����������
		CreateBiTree(T->lchild);

		//����������
		CreateBiTree(T->rchild);
		}
	return OK;
	}

void preOrder(BiTree T){
	/*
	*    �������������---------�㷨��������:
	* ��������Ϊ�գ�ִ�пղ�������������ִ�����µ�3������:
	*    (1) ����ý���ֵ
	*    (2) ������������ý���������
	*    (3) ������������ý���������
	*/
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
		}
	}

void midOrder(BiTree T){
	/*
	*      �������������---------�㷨��������:
	*  �жϵ�ǰ����Ƿ�Ϊ�գ����գ�ִ�пղ�������������ִ������3������:
	*      (1) �������������ǰ����������
	*		(2) �����ǰ���Ԫ�ص�ֵ
	*      (3) �������������ǰ����������
	*/
	if(T){
		midOrder(T->lchild);
		printf("%c",T->data);
		midOrder(T->rchild);
		}
	}

void posOrder(BiTree T){
	/*
	*     �������������---------�㷨��������:
	*  �жϵ�ǰ����Ƿ�Ϊ�����գ�ִ�пղ�������������ִ�����µ�3������:
	*        (1)���պ��������ǰ����������
	*        (2)���պ��������ǰ����������
	*        (3)�����ǰ���Ԫ�ص�ֵ
	*/
	if(T){
		posOrder(T->lchild);
		posOrder(T->rchild);
		printf("%c",T->data);
		}
	}

Status preTraverse(BiTree T){
	/*
	*        �ǵݹ��������������----------�㷨��������:	
	*  ��������������ʵ�˳�����ȷ��ʸ���㣬Ȼ���ٷֱ�������Ӻ��Һ�
	* �ӡ���������һ��㣬��ɿ����Ǹ���㣬��˿���ֱ�ӷ��ʣ�������֮��
	* �������Ӳ�Ϊ�գ�����ͬ���������������������������������ʱ���ٷ���
	* ����������������䴦��������£�
	*   ������һ���P��
	*     (1)���ʽ��P���������P��ջ;
	*     (2)�жϽ��P�������Ƿ�Ϊ�գ���Ϊ�գ���ȡջ����㲢���г�ջ����,
	*  ����ջ�������Һ�����Ϊ��ǰ�Ľ��P��ѭ����1;����Ϊ�գ���P������
	*  ��Ϊ��ǰ�Ľ��P;
	*     (3)ֱ��PΪNULL����ջΪ�գ������������
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
	*     �ǵݹ��������������---------------�㷨��������
	*   �������������˳�򣬶�����һ��㣬���ȷ��������ӣ������ӽ����
	* ���Կ���һ����㣬Ȼ��������������ӽ�㣬ֱ���������ӽ��Ϊ�յ�
	* ���Ž��з��ʣ�Ȼ����ͬ�Ĺ��������������������䴦��������£�
	* ������һ���P
	*    (1)�������Ӳ�Ϊ�գ���P��ջ����P��������Ϊ��ǰ��P��Ȼ��Ե�ǰ
	*  ���P�ٽ�����ͬ�Ĵ���
	*    (2)��������Ϊ�գ���ȡջ��Ԫ�ز����г�ջ���������ʸ�ջ����㣬Ȼ��
	*  ����ǰ��P��Ϊջ�������Һ��ӣ�
	*    3)ֱ��PΪNULL����ջΪ�����������
	*/
	LinkStack S;
	BiTree p;

	//��ָ���ջ
	InitStack(&S); Push(&S,T);

	while(!StackEmpty(S)){

		//������ǰ����������
		while(GetTop(&S,&p) &&p) Push(&S, p->lchild);

		//��ָ����ջ
		Pop(&S,&p);

		//�������������㣬Ȼ����������
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
	*     �ǵݹ�������������-----------�㷨��������
	*  ���ݺ��������֪������������Ӻ��Һ��ӷ���֮����ܷ��ʣ�
	*  ��˶�����һ���P:
	*		(1)�Ƚ�����ջ�����P���������Ӻ��Һ���,�����ֱ�ӷ�����������
	*    P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ����
	*	 ��ֱ�ӷ��ʸý�㡣
	*	    (2)�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��
	*	 ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ���
	*	 �����ǰ�汻���ʡ�
	*      (3)ֱ��ջΪ�գ�����������
	*/
	LinkStack S;
	BiTree p1,p2=NULL,temp;
	InitStack(&S);
	Push(&S,T);
	while(!StackEmpty(S))
		{
		GetTop(&S,&p1);

		//��ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ�
		if((p1->lchild==NULL&&p1->rchild==NULL)||
			(p2!=NULL&&(p2==p1->lchild||p2==p1->rchild)))   //Ϊʲô�����ʾ�����������ӽ�㶼�����ʹ���
			{
			printf("%c",p1->data); 

			// p2����ǰ�����ʵĽ��
			Pop(&S,&temp);p2=p1; 
			}
		else
			{   
			//����Һ���û�б����ʣ���ý����ջ
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
	*    ��α���������---------�㷨��������
	*  ���ݲ�α�����˼���Ǵ����ң�Ȼ����ϵ���
	*    ������һ���p:
	*		(1) �������ӣ������ʣ�
	*      (2) ���������Һ��Ӳ���Ϊ�գ�Ȼ��������ӣ�
	*      (3) ����Ϊ�գ������������
	*/
	LinkQueue Q; BiTree p;

	//���ǿ�����ֱ�ӷ��� 
	if ( !T) return OK;

	//��������ʼ������Q
	InitQueue( Q );     
	EnQueue( Q, T); 
	while ( !IsEmptyQueue( Q ) ) { 
		DeQueue( Q, p ); 
		printf("%c", p->data);

		//���Һ��Ӳ�Ϊ�գ��ֱ����
		if ( p->lchild ) EnQueue( Q, p->lchild );  
		if ( p->rchild) EnQueue( Q, p->rchild);
		} 
	return OK;
	}

/*-----------------------------------�������Ļ�������----------------------*/
void preOrderLeaf(BiTree T){
	/*
	*        ������������������Ҷ�ӽ��----�㷨��������
	*  ����ÿ����ǰ���P:
	*		(1) �ж�P�Ƿ����������ҽ��Ϊ����P��Ϊ�գ������ڣ����ʽ��P����֮��Ȼ��
	*      (2) ���ø÷�������P��������;
	*		(3) ���ø÷�������P����������
	*/
	if(T){
		//���T��������ҽ��Ϊ��
		if(T->lchild==NULL || T->rchild==NULL) printf("���P��ֵΪ:%d",T->data);

		//����ݹ����η��ʽ��T�����ӡ��Һ���
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}

	}

int leafCount=0;
void leaf_one(BiTree T){
	/*
	*        ��ȫ�ֱ���������������������Ҷ�ӵ���Ŀ----�㷨��������
	*  ����ÿ����ǰ���P:
	*		(1) �ж�P�Ƿ����������ҽ��Ϊ����P��Ϊ�գ������ڣ������Ŀ��һ����֮��Ȼ��
	*      (2) ���ø÷�������P��������;
	*		(3) ���ø÷�������P����������
	*/
	if(T){
		//���T��������ҽ��Ϊ�գ�Ҷ����Ŀ��һ
		if(T->lchild==NULL || T->rchild==NULL) ++leafCount;

		//����ݹ����η��ʽ��T�����ӡ��Һ���
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}

	}

int leaf_two(BiTree T){
	/*
	*        ��ȫ�ֱ���������������������Ҷ�ӵ���Ŀ----�㷨��������
	*  ����ÿ����ǰ���P:
	*		(1) �ж�P�Ƿ����������ҽ��Ϊ����P��Ϊ�գ������ڣ������Ŀ��һ����֮��Ȼ��
	*      (2) ���ø÷�������P��������;
	*		(3) ���ø÷�������P����������
	*/
	static int leafCount_two = 0;
	if(T){
		//���T��������ҽ��Ϊ�գ�Ҷ����Ŀ��һ
		if(T->lchild==NULL || T->rchild==NULL) ++leafCount_two;

		//����ݹ����η��ʽ��T�����ӡ��Һ���
		else {preOrderLeaf(T->lchild);preOrderLeaf(T->rchild);}
		}
	return leafCount_two;
	}

int leaf_three(BiTree T){
	/*
	*     �ݹ����Ҷ�ӽ����Ŀ-------�㷨��������
	*  ����������P:
	*    (1)  �����PΪ��ʱ��Ҷ�ӵ���Ŀ��0��
	*    (2)  �����P�����Һ��Ӷ�Ϊ�յ�ʱ��Ҷ�ӵ���Ŀ��1��
	*    (3)  ����ǰ����Ҷ�ӵ���Ŀ�����ӽ��Ҷ����Ŀ�����Һ��ӽ��Ҷ�ӵ���Ŀ
	*/
	int leafCount;
	if(!T) leafCount = 0;
	else if((T->lchild==NULL) && (T->rchild == NULL)) leafCount = 1;
	else leafCount = leaf_three(T->lchild) + leaf_three(T->rchild);
	return leafCount;
	}

int postTreeDepth(BiTree T){
	/*
	*  �ݹ�����������----------�㷨��������
	* ����������P:
	*		(1) �����PΪ�գ����Ϊ0��
	*		(2) ���򣬽��p��������������������Ľϴ�ֵ��һ
	*/
	int depth,Rdepth,Ldepth;
	if(!T) depth=0;
	else { 
		//�����������
		Rdepth = postTreeDepth(T->lchild); 
		//�����������
		Ldepth=postTreeDepth(T->rchild); 
		//������
		depth = Rdepth > Ldepth ? Rdepth : Ldepth;
		}
	return depth;
	}