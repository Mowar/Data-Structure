#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "DST.h"

//�������
void midOrder(BiTree T){
	if(T){
		midOrder(T->lchild);
		printf("%d ",T->data);
		midOrder(T->rchild);
		}
	}
//�˵�
void menu(){
	printf("\t \t \t  �����������Ĳ���\n");
	printf("\t \t 1: ���������\n");
	printf("\t \t 2: ��������������,���������������������\n");
	printf("\t \t 3: ɾ��ָ����Ԫ��\n");
	printf("\t \t 0: �˳�����\n");
	printf("���������ѡ��:");
	}

//ϰ��1 �Ĳ���
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
		printf("���ɵ�10�������:");
     for (i=0;i<10;i++)
     {
        number[i] = (int)(rand()%10);
		printf("%d ",number[i]);
      }
    
      printf("\n");
	  break;
	case 2:
		//��������������
		for(i=0; i < 10; i++){
		  InsertBST(T,number[i]);
		  }
	  //��������������������
	  printf("�������������:");
	  midOrder(T);
	  printf("\n");
	  break;
	case 3:
		//ɾ��ָ����Ԫ��
	  printf("ɾ����Ԫ��:%d\n",number[0]);
	  DeleteBST(T,number[0]);
	  //�������ɾ��Ԫ�غ�Ķ���������
	  printf("ɾ��ָ��Ԫ�صĶ���������:");
	  midOrder(T);
	  printf("\n");
	  break;
	case 0:
		return ;
	default :
		printf("-----------���������������ѡ��------\n");

		}
		}
	}
int main()
{
    /* srand((int)time(0));
     int i;
	 ElemType number[10];
	 //���������
	 
	  //��������������
	  BiTree T=NULL;
	  for(i=0; i < 10; i++){
		  InsertBST(T,number[i]);
		  }
	  //��������������������
	  printf("�������������:");
	  midOrder(T);
	  printf("\n");
	  //ɾ��ָ����Ԫ��
	  printf("ɾ����Ԫ��:%d\n",number[0]);
	  DeleteBST(T,number[0]);
	  //�������ɾ��Ԫ�غ�Ķ���������
	  printf("ɾ��ָ��Ԫ�صĶ���������:");
	  midOrder(T);
	  printf("\n");
	  */
	test1();
}