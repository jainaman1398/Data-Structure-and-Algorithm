#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
vector<ll>g[100001];
vector<ll>l[100001];
ll mod=1000000007;
typedef vector<ll>::iterator vit;
ll low_time[100001],curr_time[100001],c=0,j,parent[100001],child[100001];
ll low_time1[100001],curr_time1[100001],d=0,parent1[100001],count2=0;
bool is_point[100001],visited[1000000];
bool is_bridge[100001],visited1[1000000];
vector<ll>h[10000001];

void bridge(ll n)
{
    low_time1[n]=curr_time1[n]=++d;
    visited1[n]=true;
    for(j=0;j<g[n].size();j++)
    {
        ll curr1=g[n][j];
        if(curr1==parent1[n]){
            continue;
        }
            else if(!visited1[curr1])
            {
                parent1[curr1]=n;
                bridge(curr1);
                low_time1[n]=min(low_time1[n],low_time1[curr1]);
                if(low_time1[curr1]>=curr_time1[n]){
                    ll r,s;
                    count2++;
                    r=min(n,curr1);
                    s=max(n,curr1);
                    h[r].push_back(s);
                }
            }
            else{
                low_time1[n]=min(low_time1[n],curr_time1[n]);
            }
    }
}

void articulation(ll n)
{
    low_time[n]=curr_time[n]=++c;
    visited[n]=true;
    for(j=0;j<g[n].size();j++)
    {
        ll curr=g[n][j];
        if(curr==parent[n])
            continue;
            else if(!visited[curr])
            {
                child[n]++;
                parent[curr]=n;
                articulation(curr);
                low_time[n]=min(low_time[n],low_time[curr]);
                if(low_time[curr]>=curr_time[n])
                    is_point[n]=true;
            }
            else{
                low_time[n]=min(low_time[n],curr_time[n]);
            }
    }
}

int main()
{
    ll n,m,p,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    parent[1]=-1;
    articulation(1);
    if(child[1]>=2){
        is_point[1]=true;}
        ll count1=0;
       for(i=0;i<n;i++)
    {
        if(is_point[i]==true){
            count1++;
        }
    }
    cout<<count1<<endl;
    for(i=0;i<n;i++)
    {
        if(is_point[i])
            cout<<i<<" ";
    }
    parent1[1]=-1;
    bridge(1);
    cout<<endl<<count2<<endl;
    ll aj;
    for(i=0;i<n;i++)
    {
        if((h[i].size())>0){
          sort(h[i].begin(),h[i].end());
          for(aj=0;aj<h[i].size();aj++)
            cout<<i<<" "<<h[i][aj]<<endl;
        }
    }
    return 0;
}
