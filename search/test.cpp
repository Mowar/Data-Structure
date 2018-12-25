#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "DST.h"

//中序遍历
void midOrder(BiTree T){
	if(T){
		midOrder(T->lchild);
		printf("%d ",T->data);
		midOrder(T->rchild);
		}
	}
//菜单
void menu(){
	printf("\t \t \t  二叉排序树的操作\n");
	printf("\t \t 1: 生成随机数\n");
	printf("\t \t 2: 创建二叉排序树,并输出二叉排序树的内容\n");
	printf("\t \t 3: 删除指定的元素\n");
	printf("\t \t 0: 退出程序\n");
	printf("请输入你的选择:");
	}

//习题1 的测试
void test1(){

	srand((int)time(0));
     int i,choice;
	 ElemType number[10];
	 BiTree T=NULL;
	while(1){
		menu();
	scanf_s("%d",&choice);
	switch(choice){
	case 1:
		printf("生成的10个随机数:");
     for (i=0;i<10;i++)
     {
        number[i] = (int)(rand()%10);
		printf("%d ",number[i]);
      }
    
      printf("\n");
	  break;
	case 2:
		//建立二叉排序树
		for(i=0; i < 10; i++){
		  InsertBST(T,number[i]);
		  }
	  //中序遍历输出二叉排序树
	  printf("中序遍历二叉树:");
	  midOrder(T);
	  printf("\n");
	  break;
	case 3:
		//删除指定的元素
	  printf("删除的元素:%d\n",number[0]);
	  DeleteBST(T,number[0]);
	  //中序遍历删除元素后的二叉排序树
	  printf("删除指定元素的二叉排序树:");
	  midOrder(T);
	  printf("\n");
	  break;
	case 0:
		return ;
	default :
		printf("-----------输入错误，重新输入选择------\n");

		}
		}
	}
int main()
{
    /* srand((int)time(0));
     int i;
	 ElemType number[10];
	 //产生随机数
	 
	  //建立二叉排序树
	  BiTree T=NULL;
	  for(i=0; i < 10; i++){
		  InsertBST(T,number[i]);
		  }
	  //中序遍历输出二叉排序树
	  printf("中序遍历二叉树:");
	  midOrder(T);
	  printf("\n");
	  //删除指定的元素
	  printf("删除的元素:%d\n",number[0]);
	  DeleteBST(T,number[0]);
	  //中序遍历删除元素后的二叉排序树
	  printf("删除指定元素的二叉排序树:");
	  midOrder(T);
	  printf("\n");
	  */
	test1();
}