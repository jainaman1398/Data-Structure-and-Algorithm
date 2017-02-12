#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>v[20];
typedef vector<int>::iterator vit;
queue<int>q;
bool visted[20];
void start()
{

    v[1].pb(2);
    v[2].pb(1);

    v[3].pb(2);
    v[2].pb(3);

    v[4].pb(2);
    v[2].pb(4);

    v[1].pb(3);
    v[3].pb(1);

    v[5].pb(2);
    v[2].pb(5);

    v[1].pb(5);
    v[5].pb(1);
}
void show()
{
    for(int i=0;i<20;i++)
    {
        cout<<i<<" :";
        vector<int>::iterator it=v[i].begin();
        for(;it!=v[i].end();it++)
            cout<<" "<<*it;
        cout<<endl;
    }
}
void bfs(int x)
{
    if(!visted[x])
        {cout<<" "<<x;visted[x]=true;}
    for(vit it=v[x].begin();it!=v[x].end();it++)
    {
        if(visted[*it]==0)
        {
            visted[*it]=1;
            cout<<" "<<*it;
            q.push(*it);
        }
    }
    if(q.empty())
        return;
    int temp=q.front();
    q.pop();
    bfs(temp);
}
int main()
{
        start();
        show();
        bfs(1);
}
//DEVELOPED BY AJ
