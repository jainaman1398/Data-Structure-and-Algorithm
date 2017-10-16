#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> g[100001];
vector<ll> v;
ll n,m,level[100001],dp[100001][19];

void dfs(ll n,ll yo)
{
    level[n]=yo;
    yo++;
    for(ll y=0;y<g[n].size();y++)
    {
        dp[g[n][y]][0]=n;
        dfs(g[n][y],yo);
    }
}

ll lca(ll a,ll b)
{
    if(level[a]<level[b])
        swap(a,b);
        ll lg=0;
    for(;((1<<lg)<=level[a]);lg++);
    lg--;
    for(ll k=lg;k>=0;k--)
    {
        if((level[a])-(1<<k)>=level[b])
            a=dp[a][k];
    }
    if(a==b)
        return a;
    for(ll k=lg;k>=0;k--)
    {
        if(dp[a][k]!=-1&&dp[a][k]!=dp[b][k]){
            a=dp[a][k];b=dp[b][k];
        }
    }
    return dp[a][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    ll i,a,b,j;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a;
        g[a].push_back(i);
    }
    dfs(0,0);
    for(i=0;i<n;i++)
    {
        for(j=1;j<19;j++)
        {
            if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>b;
        v.push_back(b);
    }
    ll aj=v[0];
    for(i=1;i<v.size();i++)
    {
        aj=lca(aj,v[i]);
    }
    cout<<aj;
    return 0;
}

