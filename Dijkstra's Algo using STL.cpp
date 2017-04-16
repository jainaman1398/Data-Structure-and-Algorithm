#include <bits/stdc++.h>
using namespace std;
typedef long long int ii;
typedef pair<int,int> pi;
vector<pi> g[10001];
typedef vector<pi>::iterator vit;
bool visited[10001];
ii dis[10001];

void logic()
{
    ii x,y,i;
   for(i=0;i<=10000;i++)
    dis[i]=9999999999;
    vit it;
    dis[1]=0;
    multiset<pi> m;
    m.insert(make_pair(0,1));
    while(!m.empty())
    {
         pair <int , int> p = *m.begin();
         x=p.first; y=p.second;
         m.erase(m.begin());
         if(visited[y])
            continue;
            visited[y]=true;

        for(i=0;i<g[y].size();i++)
        {
            ii e,w;
           e=g[y][i].first;
           w=g[y][i].second;
          if(dis[e]>w+dis[y])
          {
             dis[e]=w+dis[y];
              m.insert(make_pair(dis[e],e));
          }
        }
    }
}
int main()
{
    ii n,m,i;
    cin>>n>>m;
    while(m--)
    {
        ii a,b,w;
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b,w));
    }
     logic();
    for(i=2;i<=n;i++)
            cout<<dis[i]<<" ";
       

    return 0;
}
