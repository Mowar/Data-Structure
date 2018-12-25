#include "list.h"

int main()
{
	int choice, n, i, x,length;
	SqList L, La, Lb, Lc;
	LinkList LL, LLa, LLb, LLc;

	while(1)
	{	
		//system("cls");
		printf("\t\t\t   ���Ա�Ļ�������\n\n");
		printf("\t\t\t1:˳	��  ��  ��  ��\n");
		printf("\t\t\t2:��  ��  ��  ��  ��\n");
		printf("\t\t\t0:��   ��   ��    ��\n");
		printf("��ѡ����Ĳ���:");
		scanf_s("%d",&choice);
		if(choice == 0) break;
		//system("cls");
		switch(choice)
		{
		case 1:
			while(1)
			{
				Sqmenu();
				printf("ѡ����Ĳ�����");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(CreateList_Sq(L))
						printf("˳������ɹ�\n");
					else
						printf("˳�����ʧ��\n");
					break;
				case 2:
					PrintList_Sq(L);
					break;
				case 3:
					printf("������ɾ��Ԫ�ص�λ�ã�");
					scanf_s("%d", &i);
					if(DeleteList_Sq(L, i, x))
						printf("��ɾ��Ԫ��ֵΪ��%d\n",x);
					else
						printf("ɾ��ʧ��\n");
					break;
				case 4:
					printf("������ɾ��Ԫ��ֵ��");
					scanf_s("%d", &x);
					if(DeleteListX_Sq(L, x))
						printf("ɾ���ɹ�\n");
					else
						printf("ɾ��ʧ��\n");
					PrintList_Sq(L);
					break;
				case 5:
					AdjustList_Sq(L);
					printf("������Ϊ��\n");
					PrintList_Sq(L);
					break;
				case 6:
					printf("������˳����ȣ�");
					scanf_s("%d", &n);
					if(OrderList_sq(L, n))
					{
						printf("ֵ����˳���Ϊ��\n");
						PrintList_Sq(L);
					}
					else
						printf("˳�����ʧ��\n");
					break;
				case 7:
					printf("������˳���La�ĳ��ȣ�");
					scanf_s("%d", &n);
					OrderList_sq(La, n);
					printf("������˳���Lb�ĳ��ȣ�");
					scanf_s("%d", &n);
					OrderList_sq(Lb, n);
					MergeList_Sq(La, Lb, Lc);
					printf("�ϲ����˳���Ϊ��\n");
					PrintList_Sq(Lc);
					break;
				default:
					printf("�����������������\n");
				}
			}
			break;
		case 2:
			while(1)
			{
			//	system("cls");
				Linkmenu();
				printf("ѡ����Ĳ�����");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(Creat_Linklist(LL))
						printf("���������ɹ�\n");
					else
						printf("��������ʧ��\n");
					break;
				case 2:
					Disp_Linklist(LL);
					break;
				case 3:
					length = length_Linklist(LL);
					printf("��������Ϊ��%d\n",length);
					break;
				case 4:
					Reverse_Linklist(LL);
					printf("���ú������Ϊ��\n");
					Disp_Linklist(LL);
					break;
				case 5:
					DelEven_Linklist(LL);
					printf("������Ϊ��\n");
					Disp_Linklist(LL);
					break;
				case 6:
					if(CreatOrder_Linklist(LL))
					{
						printf("ֵ��������Ϊ��\n");
						Disp_Linklist(LL);
					}
					else
						printf("��������ʧ��\n");
					break;
				case 7:
					CreatOrder_Linklist(LLa);
					CreatOrder_Linklist(LLb);
					MergeDescend_Linklist(LLa, LLb, LLc);
					printf("�ϲ����������Ϊ��\n");Disp_Linklist(LLc);
					break;
				case 8:
					CreatOrder_Linklist(LLa);
					CreatOrder_Linklist(LLb);
					MergeAscend_Linklist(LLa, LLb, LLc);
					printf("�ϲ����������Ϊ��\n");Disp_Linklist(LLc);
					break;
				case 9:
					Creat_Linklist(LL);
					Split_Linklist(LL, LLb);
					printf("���Ѻ��������Ϊ��\n");
					Disp_Linklist(LL);
					Disp_Linklist(LLb);
					break;
				default:
					printf("�����������������\n");
				}
			}
			break;
		case 0:
			return 0;
		default :
			printf("�����������������\n");

		}
	}
}