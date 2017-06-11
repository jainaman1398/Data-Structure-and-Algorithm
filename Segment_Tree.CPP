#include <bits/stdc++.h>
using namespace std;
int ar[]={1,2,3,4,5};
int aj[10];

void update(int node,int start,int end,int idx,int val)
{
    if(start==end&&start==idx)
    {
        ar[idx]+=val;
        aj[node]+=val;
    }
    else
    {
   int mid=(start+end)/2;
   if(idx>=start&&idx<=mid)
   {
       update(2*node,start,mid,idx,val);
   }
   else
   {
       update(2*node+1,mid+1,end,idx,val);
   }
   aj[node]=aj[2*node]+aj[2*node+1];
    }
   
}
void build(int node ,int start,int end)
{
    if(start==end)
    {
        aj[node]=ar[start];
    }
    else
    {
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    aj[node]=aj[2*node]+aj[2*node+1];
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(l<=start&&r>=end)
    return aj[node];
    if(r<start||l>end)
    return 0;
    else
    {
        int p,p1,p2,mid;
        mid=(start+end)/2;
        p1=query(2*node,start,mid,l,r);
        p2=query(2*node+1,mid+1,end,l,r);
        p=p1+p2;
        return p;
        
    }
}

int main() {
  build(1,0,4);
  int i;
  for(i=1;i<=9;i++)
  cout<<aj[i]<<" ";
  cout<<endl;
  cout<<query(1,0,4,0,3)<<endl;
  update(1,0,4,2,4);
   for(i=1;i<=9;i++)
  cout<<aj[i]<<" ";
  cout<<endl;
   cout<<query(1,0,4,0,3);
  return 0;
}
