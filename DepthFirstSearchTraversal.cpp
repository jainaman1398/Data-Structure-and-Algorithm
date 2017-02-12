#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> v[100];
bool visited[100];
stack<int>q;
typedef vector<int>::iterator vit;

void create()
{
    v[1].pb(2);
    v[1].pb(4);
    v[2].pb(3);
    v[2].pb(4);
    v[3].pb(5);

}
void show()
{
    int i,j;
     cout<<"Graph representation";
    for(i=1;i<=5;i++)
    {
        for(vit it=v[i].begin();it<v[i].end();it++)
        {
            cout<<" "<<*it;
        }
        cout<<endl;

    }

}
void dfs(int x)
{

    if(!visited[x])
    {
        cout<<x<<endl;
        visited[x]=true;
    }
    q.push(x);
    for(vit it=v[x].begin();it!=v[x].end();it++)
    {
     
        dfs(*it);
    }
}
int main()
{
    cout << "DFS IMPLEMENTATION \t" << endl;
    create();
    show();
    dfs(1);

    return 0;
}
//DEVELOPED BY AJ.
