#include <stdio.h>
#include <stdlib.h>

void AddToQue(int *Que,int *start,int *end,int QueSize)
{
    int number;
    system("cls");
    if((*end)==(*start)&&(*start)!=-1)
    {
        printf("Que is full\n");
        system("pause");
    }
    else
    {
        printf("Write the number to add:\n\n");
        scanf("%d",&number);
        if((*start)==(*end)&&(*start)==-1)
        {
            (*start)=0;
            Que[(*start)]=number;
            (*end)=1;
        }
        else
        {
            if((*end)<QueSize&&(*start)==0)
            {
                Que[(*end)]=number;
                (*end)++;
            }
            else
            if(((*end)+1)==QueSize)
            {
                Que[(*end)]=number;
                (*end)=0;
            }
        }
    }
}

void DeleteFromQue(int *start,int *end)
{
    if((*start)==(*end)-1)
    {
        (*start)=(*end)=-1;
    }
    else
        (*start)++;
}

void ShowQue(int *Que,int start,int end,int QueSize)
{
    system("cls");
    int i=start;
    printf("%d - %d\n\n",start,end);
    if((end+1)==start)
    {
        printf("Que is empty.\n");
    }
    else
        if(i<end)
            for(i;i<end;i++)
            printf("%d ",Que[i]);
        if(i>end)
        {
            for(i=start;i<QueSize;i++)
            {
                printf("%d ",Que[i]);
            }
            for(i=0;i<end;i++)
                printf("%d ",Que[i]);
        }
    printf("\n");
    system("pause");
}

void main()
{
    int choice,start=-1,end=-1,QueSize=5;
    int Que[QueSize];
    do
    {
        system("cls");
        printf("What do you want to do?:\n---------\n");
        printf("\n[1]-Add a digit.\n[2]-Remove a digit.\n[3]-Show the Que.\n[4]-Exit.\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            AddToQue(&Que,&start,&end,QueSize);
            break;
        case 2:
            DeleteFromQue(&start,&end);
            break;
        case 3:
            ShowQue(Que,start,end,QueSize);
            break;
        case 4:
            exit(1);
        default:
        system("pause");
            break;
        }
    }
    while(1);
}
