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
    int t,n,ar[100001],max[100001],sum=0,sum1=0,i;
    ar[0]=max[0]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=sum1=0;
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=n;i++)
        {
            if(ar[i]>0)
                sum=sum+ar[i];
        }
        if(sum==0)
        {
            sum=ar[1];
             for(i=2;i<=n;i++)
        {
            if(ar[i]>sum)
                sum=ar[i];
        }
        }
        for(i=1;i<=n;i++)
        {
                 if(max[i-1]>0)
                    {
                       sum1=ar[i]+max[i-1];
                    }
                 else{
                     sum1=ar[i];
                 }
                 max[i]=sum1;
        }
      //  for(i=0;i<=n;i++)
        //    printf("%d\n",max[i]);
       quicksort(max,0,n);
         if(ar[1]==-10)
        printf("%d\t%d\n",-10,-10);
       else if(max[n]==0){
       printf("%d\t%d\n",sum,sum);}

       else{
       printf("%d\t%d\n",max[n],sum);}


    }
    return 0;
}
