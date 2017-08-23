/// credits-> Anudeep's blog..
/// crafted by -> Aman Jain
/// Problem -> DQUERY(SPOJ).

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll block=555,yo=0,aj[1000001],ans[300001];
ll ar[1000001];

struct node{
    ll l,r,p;
}q[300000];

bool cmp(node x,node y)
{
    if(x.l/block!=y.l/block){
        return x.l/block<y.l/block;
    }
    return x.r<y.r;
}

void remove1(ll n)
{
    aj[ar[n]]--;
    if(aj[ar[n]]==0){
        yo--;}
}

void add(ll n)
{
    aj[ar[n]]++;
    if(aj[ar[n]]==1){
        yo++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&ar[i]);
    scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       ll a,b;
       scanf("%d%d",&a,&b);
       q[i].l=--a;q[i].r=--b;
       q[i].p=i;
   }
   sort(q,q+t,cmp);
 /*  for(i=0;i<t;i++)
    cout<<q[i].l<<" "<<q[i].r<<endl; */
    ll Current_left=0,Current_right=0;
   for(i=0;i<t;i++)
   {
       ll L=q[i].l,R=q[i].r;
       while(Current_left<L)
       {
           remove1(Current_left);
           Current_left++;
       }
       while(Current_left>L)
       {
           add(Current_left-1);
           Current_left--;
       }
       while(Current_right<=R)
       {
           add(Current_right);
           Current_right++;
       }
       while(Current_right>R+1)
       {
           remove1(Current_right-1);
           Current_right--;
       }
       ans[q[i].p]=yo;
   }
   for(i=0;i<t;i++)
     printf("%d\n",ans[i]);
    return 0;
}
