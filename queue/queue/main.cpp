#include "queue.h"

int main()
{
    int choice,jk,i=0,j=0;
    SqQueue s;
	LinkQueue S;
    QElemType e;
    while(1)
    {
		printf("541507120151-Ԭ����-�������\n");
        printf("����1������\n");
        printf("����2��ѭ������\n");
        printf("����3���˳�����\n");
        printf("ѡ����Ĳ�����");
        scanf("%d",&jk);
        switch(jk)
        {
        case 1:
            while(1)
            {
                Linkmenu();
                printf("ѡ����Ĳ�����");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    if(InitQueue(S))
                        printf("��������ӳɹ�\n");
                    else
                        printf("�����ջʧ��\n");
                    break;
                case 2:
					printf("��������ӵ�Ԫ��:");
                    scanf("%d", &e);
                    if(EnQueue(S,e))
					//if(1)
                        printf("��ӳɹ�\n");
                    else
                        printf("���ʧ��\n");
                    break;
                case 3:
                    printf("���ӵ�Ԫ��:");
                    if(DeQueue(S,e))
                        printf("%d\n",e);
                    else
                        printf("��ջʧ��\n");
                    break;
                case 0:
                    i = 1;
                    break;
                default:
                    printf("�����������������\n");
                }

                if(i == 1)
                    break;
            }
            break;
        case 2:
            while(1)
            {
                Sqmenu();
                printf("ѡ����Ĳ�����");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    if(InitSqQueue(s))
                        printf("����նӳɹ�\n");
                    else
                        printf("����ն�ʧ��\n");
                    break;
                case 2:
                    printf("��������ӵ�Ԫ�أ�");
                    scanf("%d", &e);
                    if(EnSqQueue(s,e))
                        printf("��ӵ�Ԫ�سɹ�\n");
                    else
                        printf("��ӵ�Ԫ��ʧ��\n");
                    break;
                case 3:
                    printf("���ӵ�Ԫ��:");
                    if(DeSqQueue(s,e))
                        printf("���ӳɹ�%d\n",e);
                    else
                        printf("����ʧ��\n");
                    break;
                case 0:
                    j = 1;
                    break;
                default:
                    printf("�����������������\n");
                }
                if(j == 1)
                    break;
            }
            break;
        case 3:
            return 0;
        default:
            printf("�����������������\n");
        }
    }
}
