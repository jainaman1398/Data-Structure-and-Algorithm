// ROD CUTTING
// DYNAMIC PROGRAMMING
// bottom up approach with memoization.
// credit- CLRS.
#include <stdio.h>
#include <stdlib.h>

int maximum(int q,int t,int i)
{

    if(q>t)
    return q;
    else
       return t;

}

void cutrod(int p[],int n)
{
    int r[11],q,i,j,s[11],b; // array r->price of rods
                             // array s->no of rods @ each level
    r[0]=0;
    s[0]=0,s[1]=1;
    for(i=1;i<=11;i++)
    {
        q=0;
        for(j=1;j<=i;j++)
        {
           int t=p[j]+r[i-j];
           if(q<maximum(q,t,i))
           {

           q=maximum(q,t,i);
           b=j;
           }
        }
          s[i]=s[i-b]+1;
          r[i]=q;            // at each level storing value for rod maximum price we can get.

    }
    for(i=1;i<=10;i++)
  printf("\n%d\n",r[i]);

 for(i=1;i<=10;i++)
  printf("\n%d\n",s[i]);

}

int main()
{

    int p[11]={0,1,5,8,9,10,17,17,20,24,30},n=10,r[11],i;
    cutrod(p,n);
    return 0;
}
