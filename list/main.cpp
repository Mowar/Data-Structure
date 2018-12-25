#include "list.h"

int main()
{
	int choice, n, i, x,length;
	SqList L, La, Lb, Lc;
	LinkList LL, LLa, LLb, LLc;

	while(1)
	{	
		//system("cls");
		printf("\t\t\t   线性表的基本操作\n\n");
		printf("\t\t\t1:顺	序  表  操  作\n");
		printf("\t\t\t2:单  链  表  操  作\n");
		printf("\t\t\t0:退   出   程    序\n");
		printf("请选择你的操作:");
		scanf_s("%d",&choice);
		if(choice == 0) break;
		//system("cls");
		switch(choice)
		{
		case 1:
			while(1)
			{
				Sqmenu();
				printf("选择你的操作：");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(CreateList_Sq(L))
						printf("顺序表创建成功\n");
					else
						printf("顺序表创建失败\n");
					break;
				case 2:
					PrintList_Sq(L);
					break;
				case 3:
					printf("请输入删除元素的位置：");
					scanf_s("%d", &i);
					if(DeleteList_Sq(L, i, x))
						printf("被删除元素值为：%d\n",x);
					else
						printf("删除失败\n");
					break;
				case 4:
					printf("请输入删除元素值：");
					scanf_s("%d", &x);
					if(DeleteListX_Sq(L, x))
						printf("删除成功\n");
					else
						printf("删除失败\n");
					PrintList_Sq(L);
					break;
				case 5:
					AdjustList_Sq(L);
					printf("新链表为：\n");
					PrintList_Sq(L);
					break;
				case 6:
					printf("请输入顺序表长度：");
					scanf_s("%d", &n);
					if(OrderList_sq(L, n))
					{
						printf("值有序顺序表为：\n");
						PrintList_Sq(L);
					}
					else
						printf("顺序表创建失败\n");
					break;
				case 7:
					printf("请输入顺序表La的长度：");
					scanf_s("%d", &n);
					OrderList_sq(La, n);
					printf("请输入顺序表Lb的长度：");
					scanf_s("%d", &n);
					OrderList_sq(Lb, n);
					MergeList_Sq(La, Lb, Lc);
					printf("合并后的顺序表为：\n");
					PrintList_Sq(Lc);
					break;
				default:
					printf("输入错误，请重新输入\n");
				}
			}
			break;
		case 2:
			while(1)
			{
			//	system("cls");
				Linkmenu();
				printf("选择你的操作：");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(Creat_Linklist(LL))
						printf("单链表创建成功\n");
					else
						printf("单链表创建失败\n");
					break;
				case 2:
					Disp_Linklist(LL);
					break;
				case 3:
					length = length_Linklist(LL);
					printf("单链表长度为：%d\n",length);
					break;
				case 4:
					Reverse_Linklist(LL);
					printf("逆置后的链表为：\n");
					Disp_Linklist(LL);
					break;
				case 5:
					DelEven_Linklist(LL);
					printf("新链表为：\n");
					Disp_Linklist(LL);
					break;
				case 6:
					if(CreatOrder_Linklist(LL))
					{
						printf("值有序链表为：\n");
						Disp_Linklist(LL);
					}
					else
						printf("单链表创建失败\n");
					break;
				case 7:
					CreatOrder_Linklist(LLa);
					CreatOrder_Linklist(LLb);
					MergeDescend_Linklist(LLa, LLb, LLc);
					printf("合并后的新链表为：\n");Disp_Linklist(LLc);
					break;
				case 8:
					CreatOrder_Linklist(LLa);
					CreatOrder_Linklist(LLb);
					MergeAscend_Linklist(LLa, LLb, LLc);
					printf("合并后的新链表为：\n");Disp_Linklist(LLc);
					break;
				case 9:
					Creat_Linklist(LL);
					Split_Linklist(LL, LLb);
					printf("分裂后的新链表为：\n");
					Disp_Linklist(LL);
					Disp_Linklist(LLb);
					break;
				default:
					printf("输入错误，请重新输入\n");
				}
			}
			break;
		case 0:
			return 0;
		default :
			printf("输入错误，请重新输入\n");

		}
	}
}