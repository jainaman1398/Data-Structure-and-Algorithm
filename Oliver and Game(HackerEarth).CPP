#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> g[600001];
ll n,i,q,jojo=0;
bool visited[600001];
ll s_time[600001],e_time[600001],g_time=0;

void dfs(ll v)
{
    visited[v]=true;
    s_time[v]=++g_time;
    for(int y=0;y<g[v].size();y++)
    {
        if(!visited[g[v][y]])
            dfs(g[v][y]);
    }
    e_time[v]=++g_time;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    dfs(1);
    cin>>q;
    while(q--)
    {
        ll u,v,z;
        cin>>u>>v>>z;
        if(u==0)
        {
            if(s_time[v]<s_time[z]&&e_time[v]>e_time[z])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            if(s_time[z]<s_time[v]&&e_time[z]>e_time[v])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
