#include "queue.h"

int main()
{
    int choice,jk,i=0,j=0;
    SqQueue s;
	LinkQueue S;
    QElemType e;
    while(1)
    {
		printf("541507120151-袁书泽-软件工程\n");
        printf("操作1是链队\n");
        printf("操作2是循环队列\n");
        printf("操作3是退出程序\n");
        printf("选择你的操作：");
        scanf("%d",&jk);
        switch(jk)
        {
        case 1:
            while(1)
            {
                Linkmenu();
                printf("选择你的操作：");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    if(InitQueue(S))
                        printf("构造空链队成功\n");
                    else
                        printf("构造空栈失败\n");
                    break;
                case 2:
					printf("请输入入队的元素:");
                    scanf("%d", &e);
                    if(EnQueue(S,e))
					//if(1)
                        printf("入队成功\n");
                    else
                        printf("入队失败\n");
                    break;
                case 3:
                    printf("出队的元素:");
                    if(DeQueue(S,e))
                        printf("%d\n",e);
                    else
                        printf("出栈失败\n");
                    break;
                case 0:
                    i = 1;
                    break;
                default:
                    printf("输入错误，请重新输入\n");
                }

                if(i == 1)
                    break;
            }
            break;
        case 2:
            while(1)
            {
                Sqmenu();
                printf("选择你的操作：");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    if(InitSqQueue(s))
                        printf("构造空队成功\n");
                    else
                        printf("构造空队失败\n");
                    break;
                case 2:
                    printf("请输入入队的元素：");
                    scanf("%d", &e);
                    if(EnSqQueue(s,e))
                        printf("入队的元素成功\n");
                    else
                        printf("入队的元素失败\n");
                    break;
                case 3:
                    printf("出队的元素:");
                    if(DeSqQueue(s,e))
                        printf("出队成功%d\n",e);
                    else
                        printf("出队失败\n");
                    break;
                case 0:
                    j = 1;
                    break;
                default:
                    printf("输入错误，请重新输入\n");
                }
                if(j == 1)
                    break;
            }
            break;
        case 3:
            return 0;
        default:
            printf("输入错误，请重新输入\n");
        }
    }
}
