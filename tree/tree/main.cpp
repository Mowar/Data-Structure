#include "tree.h"
void menu(){
	printf("\t\t\t541507120151-Ԭ����-�������\n");
	printf("����1�ǽ���������\n");
	printf("����2�ǵݹ��������������\n");
	printf("����3�ǵݹ��������������\n");
	printf("����4�ǵݹ�������������\n");
	printf("����5�Ƿǵݹ��������������\n");
	printf("����6�Ƿǵݹ��������������\n");
	printf("����7�Ƿǵݹ�������������\n");
	printf("����8�ǲ�α���������\n");
	printf("����0���˳�\n");
}
int main()
{
	int choice;
	BiTree T;
	while(1)
	{
		menu();
		printf("ѡ����Ĳ�����");
		scanf_s("%d",&choice);
		getchar();
		switch(choice)
		{
		case 0:
			return OK;
		case 1:
			if(CreateBiTree(T))
				printf("�����������ɹ�\n");
			else
				printf("����������ʧ��\n");
			break;
		case 2:
			printf("�ݹ�������������Ԫ������:\n");preOrder(T);printf("\n");
			break;
		case 3:
			printf("�ݹ������������ĵ�Ԫ������:\n");midOrder(T);printf("\n");
			break;
		case 4:
			printf("�ݹ������������Ԫ������:\n"); posOrder(T);printf("\n");
			break;
		case 5:
			printf("�ǵݹ�������������Ԫ������:\n");preTraverse(T);printf("\n");
			break;
		case 6:
			printf("�ǵݹ�������������Ԫ������:\n");midTraverse(T);printf("\n");
			break;
		case 7:
			printf("�ǵݹ������������Ԫ������:\n");posTraverse(T);printf("\n");
			break;
		case 8:
			printf("��α������������������:\n");LevelOrderTraverse(T);printf("\n");
			break;
		default:
			printf("�����������������\n");
		}
	}
	return OK;
}
