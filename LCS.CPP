///AJ
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ar[10001][10001],vihu[10001][10001];
string c,d;

void print(ll m,ll n)
{
    if(m==0||n==0)
        return;
    if(vihu[m][n]==0)
    {
        print(m-1,n-1);
        cout<<c[m-1];
    }
    else if(vihu[m][n]==1)
        print(m-1,n);
    else
        print(m,n-1);
}

void yo(string a,string b,ll m,ll n)
{
   ll i,j;
   for(i=0;i<=m;i++)
   {
       for(j=0;j<=n;j++)
       {
           if(i==0||j==0)
            ar[i][j]=0;
           else if(a[i-1]==b[j-1]){
            ar[i][j]=1+ar[i-1][j-1];
            vihu[i][j]=0;
           }
           else{
            ar[i][j]=max(ar[i-1][j],ar[i][j-1]);
             if(ar[i-1][j]>ar[i][j-1])
                vihu[i][j]=1;
             else
                vihu[i][j]=2;
           }
       }
   }
   cout<<(ar[m][n])<<"\n";
}

int main()
{
    memset(vihu,-1,sizeof(vihu));

     cin>>c>>d;
    ll m=c.size();
    ll n=d.size();
    yo(c,d,m,n);
    print(m,n);
    return 0;
}
