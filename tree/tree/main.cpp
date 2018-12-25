#include "tree.h"
void menu(){
	printf("\t\t\t541507120151-袁书泽-软件工程\n");
	printf("操作1是建立二叉树\n");
	printf("操作2是递归先序遍历二叉树\n");
	printf("操作3是递归中序遍历二叉树\n");
	printf("操作4是递归后序遍历二叉树\n");
	printf("操作5是非递归先序遍历二叉树\n");
	printf("操作6是非递归中序遍历二叉树\n");
	printf("操作7是非递归后序遍历二叉树\n");
	printf("操作8是层次遍历二叉树\n");
	printf("操作0是退出\n");
}
int main()
{
	int choice;
	BiTree T;
	while(1)
	{
		menu();
		printf("选择你的操作：");
		scanf_s("%d",&choice);
		getchar();
		switch(choice)
		{
		case 0:
			return OK;
		case 1:
			if(CreateBiTree(T))
				printf("二叉树创建成功\n");
			else
				printf("二叉树创建失败\n");
			break;
		case 2:
			printf("递归先序遍历输出的元素如下:\n");preOrder(T);printf("\n");
			break;
		case 3:
			printf("递归中序遍历输出的的元素如下:\n");midOrder(T);printf("\n");
			break;
		case 4:
			printf("递归后序遍历输出的元素如下:\n"); posOrder(T);printf("\n");
			break;
		case 5:
			printf("非递归先序遍历输出的元素如下:\n");preTraverse(T);printf("\n");
			break;
		case 6:
			printf("非递归中序遍历输入的元素如下:\n");midTraverse(T);printf("\n");
			break;
		case 7:
			printf("非递归后序遍历输出的元素如下:\n");posTraverse(T);printf("\n");
			break;
		case 8:
			printf("层次遍历二叉树，输出如下:\n");LevelOrderTraverse(T);printf("\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	}
	return OK;
}
