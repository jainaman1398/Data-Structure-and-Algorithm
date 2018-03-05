#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,ar[100001],ans=INT_MIN,maxi=0,aj=INT_MIN;
#define null 0
#define length 32

struct Trie
{
    int value;
    Trie* link[2];
}*root;


Trie* initialize()
{
    Trie* temp=new Trie;
    temp->value=0;
    temp->link[0]=temp->link[1]=null;
    return temp;
}

void insert_into(int n)
{
    Trie* temp=root;
    for(int i=length-1;i>=0;i--)
    {
        bool bit=n&(1<<i);
        if(temp->link[bit]==null)
            temp->link[bit]=initialize();
        temp=temp->link[bit];
    }
    temp->value=n;
}

void maxi_count(int n)
{
    Trie *temp=root;
    for(int i=length-1;i>=0;i--)
    {
        bool bit=(n&(1<<i));
        if(temp->link[1-bit]){
            temp=temp->link[1-bit];
        }
            else
        temp=temp->link[bit];
    }
    maxi=n^temp->value;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    root=initialize();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
        insert_into(ar[0]);
        for(int i=1;i<n;i++)
        {
            insert_into(ar[i]);
            maxi=0;
            maxi_count(ar[i]);
             ans=max(ans,maxi);
        }
     cout<<ans;
    return 0;
}
