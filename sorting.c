#include<stdio.h>
void quicksort(int[10],int,int);
void main()
{
   int x[20],size,i;
   printf("enter the size of the array: ");
   scanf("%d",&size);
   printf("enter %d elements: ",size);
   for(i=0;i<size;i++)
   scanf("%d",&x[i]);
   quicksort(x,0,size-1);
   printf("sorted elements: ");
   for(i=0;i<size;i++)
   printf("%d\n",x[i]);
   printf("\b\b");
}
void quicksort(int x[10],int first,int last)
{
    int pivot,p,q,temp;
    if(first<last)
    {
        pivot=first;
        p=first;
        q=last;
        while(p<q)
        {
            while(x[q]>x[pivot])
            q--;
            if(p<q)
            {
                temp=x[p];
                x[p]=x[q];
                x[q]=temp;
            }
        }
        temp=x[pivot];
        x[pivot]=x[q];
        x[q]=temp;
        quicksort(x,first,q-1);
        quicksort(x,q+1,last);
    }
}
