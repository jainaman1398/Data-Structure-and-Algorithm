// AMAN JAIN
// HEAP-SORT
#include <stdio.h>
#include <stdlib.h>
int heap_size;
void heapify(int ar[],int i)
{
   int l,r,temp=ar[i],v;
   l=ar[2*i];
   r=ar[2*i+1];
   if(2*i<=heap_size&&ar[i]<ar[2*i]) {
   temp=ar[2*i];
   v=2*i;
   }
    if((2*i+1)<=heap_size&&ar[i]<ar[2*i+1]) {
   temp=ar[2*i+1];
   v=2*i+1;
    }
   if(temp!=ar[i])
   {
      ar[v]=ar[i];
      ar[i]=temp;
      heapify(ar,v);
   }

}
void max_heap(int ar[],int n)
{
    int b,temp,i;
    b=n/2;
    for(i=b-1;i>=0;i--)
    {
        heapify(ar,i);
    }
    for(i=n-1;i>=0;i--)
    {
       temp=ar[i];
       ar[i]=ar[0];
       ar[0]=temp;
       heap_size--;
       heapify(ar,0);
    }

}

int main()
{
    int n ,*ar,i;
    printf(" \n\n ***** Heap-Sort ***** \n\n");
   printf("Enter the no of elements to be sorted \n");
   scanf("%d",&n);
   heap_size=n;
   ar=(int*)malloc(n*sizeof(int));
   printf("Enter the Elements to be sorted");
   for(i=0;i<n;i++)
   {
       scanf("%d",&ar[i]);
   }
   max_heap(ar,n);
   printf("\n sorted array is");
   for(i=0;i<n;i++)
   {
       printf("%d \n",ar[i]);
   }
   printf("Developed by AJ");
    return 0;
}
