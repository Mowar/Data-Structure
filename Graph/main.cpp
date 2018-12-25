#include "graph.h"

/*int main()
{
	ALGraph G;
	int length,sum = 0;
	int choice;

	while(1)
	{	
		system("cls");
		menu();
		scanf_s("%d",&choice);
		if(choice == 0) break;
		system("cls");
		switch(choice)
		{
		case 1:
			while(1)
			{
				UDGmenu();
				printf("选择你的操作：");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(CreateG(&G,1))
						printf("无向图创建成功\n");
					else
						printf("无向图创建失败\n");
					break;
				case 2:
					PrintG(G,1);
					break;
				case 3:
					DFSTraverse(G);
					break;
				case 4:
					BFSTraverse(G);
					break;
				default:
					printf("输入错误，请重新输入\n");
				}
			}
			break;
		case 2:
			while(1)
			{
				DGmenu();
				printf("选择你的操作：");
				scanf_s("%d",&choice);
				if(choice == 0) break;
				switch(choice)
				{
				case 1:
					if(CreateG(&G,2))
						printf("有向图创建成功\n");
					else
						printf("有向图创建失败\n");
					break;
				case 2:
					PrintG(G,2);
					break;
				case 3:
					length = ComputingDegree(G);
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
}*/