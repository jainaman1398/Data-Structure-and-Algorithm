// QuickSort
// AMAN JAIN
#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int start,int end)
{
    int pivot=a[end], p_index=start,temp,i;
    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
           temp=a[i];
           a[i]=a[p_index];
           a[p_index]=temp;
           p_index=p_index+1;
        }
    }
    temp=a[p_index];
    a[p_index]=a[end];
    a[end]=temp;
    return p_index;

}
void quicksort(int ar[],int start ,int end)
{
   if(start<end)
   {
       int partition_index=partition(ar,start,end);
       quicksort(ar,start,partition_index-1);
       quicksort(ar,partition_index+1,end);

   }
}

int main()
{
    int ar[100],i;
    printf(" ******* QuickSort ******** \n");
    printf("Enter the array elements \n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&ar[i]);
    }
     quicksort(ar,0,9);
     for(i=0;i<10;i++)
    {
        printf("%d \n",ar[i]);
    }
    printf("\n $$$$$$$ Developed by AJ $$$$$$$");

    return 0;
}
