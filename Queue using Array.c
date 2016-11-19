#include <stdio.h>
#include <stdlib.h>
int j;
int ar[10],front=0,rear=0;

 void dequeue()
 {
     front=front+1;
 }
 int enqueue(int j)
 {

   ar[rear]=j;

 }
int main()
{   int i,n,m,rear=0;
    printf("enter initial elements of queue");
    for(i=rear;i<7;i++)
    {
        scanf("%d",&ar[i]);
    }

    printf("you can add up to max three element.how much you wanna add");
    scanf("%d",&n);
    for(i=rear;i<(rear+n);i++)
   {
       enqueue(ar[i]);
   }
   printf("how much you  wanna dequeue");
   scanf("%d",&m);
   for(i=0;i<m;i++)
   {
      dequeue();
   }










    return 0;
}
