#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ar[2000001],tree[2000001],lazy[2000001];

void build(ll node,ll start,ll end1)
{
    if(start==end1)
    {
        tree[node]=ar[start];
        return;
    }
    ll mid=((start+end1)>>1);
    build(2*node,start,mid);
    build(2*node+1,mid+1,end1);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(ll node,ll start,ll end1,ll a,ll b,ll value)
{
     if(lazy[node]!=0)
    {
        tree[node]+=(end1-start+1)*lazy[node];
        if(start!=end1)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
         lazy[node]=0;
    }
   if(a>end1||b<start)
        return ;
   if(a<=start&&b>=end1)
   {
       tree[node]+=(end1-start+1)*value;
       if(start!=end1)
       {
           lazy[2*node]+=value;
           lazy[2*node+1]+=value;
       }
       return;
   }
   ll mid=((start+end1)>>1);
   update(2*node,start,mid,a,b,value);
   update(2*node+1,mid+1,end1,a,b,value);
   tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(ll node,ll start,ll end1,ll a,ll b)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end1-start+1)*lazy[node];
        if(start!=end1)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
         lazy[node]=0;
    }
    if(a>end1||b<start)
    return 0;
    if(a<=start&&b>=end1)
        return tree[node];
    ll mid=((start+end1)>>1);
    ll p1=query(2*node,start,mid,a,b);
    ll p2=query(2*node+1,mid+1,end1,a,b);
    return (p1+p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,i;
    cin>>t;
    while(t--)
    {
        for(i=0;i<2000001;i++)
            ar[i]=tree[i]=lazy[i]=0;
        ll n,c;
        cin>>n>>c;
        build(1,1,n);
        for(i=1;i<=c;i++)
        {
            ll a,b,c,d;
            cin>>a;
            if(a==0)
            {
                cin>>b>>c>>d;
                update(1,1,n,b,c,d);
            }
            else
            {
                cin>>b>>c;
                cout<<query(1,1,n,b,c)<<"\n";
            }
        }
    }
    return 0;
}
