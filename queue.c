#include<stdio.h>
void insert(int);
int del();
void display();
int queue[10],max_size=9,p=-1,k=-1,ele;
void main()
{
    int ch;         //case input
    do              //case code
    {
        fflush(stdin);
        printf("\n what do you want to perform :\n1.insert \n2.delete \n3.display \n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n enter the element you want to insert:");
            scanf("%d",&ele);
            insert(ele);
            break;

            case 2:
            //printf("\n enter the element you want to delete:");     // it is not work because
            //scanf("%d",&ele);                                       //queue use FIFO logic    
            ele=del();
            printf("\n the delected element is %d",ele);
            break;

            case 3:
            display();
            break;

            case 4:
            break;
        }
    }
    while(ch!=4);
}
//insertion code
void insert(int a)
{
    if(p==k+1)
    {
        printf("overflow !");
    }
    else
    {
        if(k==-1)
        {
            k=0;
            p=0;
        }
        else if(k==max_size)
        {
            k==0;
        }
        else
        {
            k++;
        }
        queue[k]=ele;
    }
}
//deletoion code
int del()
{
    int a;
    if(p==-1)
    {
        printf("underflow !");
        return -1;
    }
    else
    {
        a=queue[p];
        if(p==k)
        {
            p=-1;
            k=-1;
        }
        if(p==max_size)
        {
            p=0;
        }
        else
        {
            p++;
        }
        return a;
    }
}
//desplay code
void display()
{
    int i;
    for(i=p;i<k;i++)
    {
        if(i==max_size-1)
        {
            i=0;
        }
        printf("\n %d ",queue[i]);
    }
}
