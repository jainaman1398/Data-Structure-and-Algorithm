// Author-> Aman Jain
// love to code :)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ii;
typedef pair<ii,ii> pi;
vector<pi> v[100000];
bool visited[100000];
ii min_cost=0,i;

void prims(ii n)
{
    priority_queue<pi,vector<pi>,greater<pi> > q;
    pi t;
    q.push({0,n});
    while(!q.empty())
    {
        t=q.top();
        q.pop();
        if(visited[t.second])
            continue;
        min_cost+=t.first;
                visited[t.second]=true;
        for(i=0;i<v[t.second].size();i++)
        {
            if(!visited[v[t.second][i].first])
            {
                q.push({v[t.second][i].second,v[t.second][i].first});
            }
        }

    }
    cout<<min_cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ii n,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        ii a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    prims(1);
    return 0;
}
