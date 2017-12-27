#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num,mat[3][3]={{1,1,1},{0,1,1},{0,1,0}},original[3][3]={{1,1,1},{0,1,1},{0,1,0}};

void mul(ll a[3][3],ll b[3][3])
{
  ll sum[3][3];
  memset(sum,0,sizeof(sum));
  for(int i=0;i<3;i++)
  {
      for(int j=0;j<3;j++)
      {
          for(int k=0;k<3;k++)
            sum[i][j]+=a[i][k]*b[k][j];
      }
  }
  for(int i=0;i<3;i++)
  {
      for(int j=0;j<3;j++)
        mat[i][j]=sum[i][j];
  }
}

int yo(int n)
{
    if(n==1)
        return mat[0][0]*4+mat[0][1]*2+mat[0][2]*1;
        yo(n/2);
    mul(mat,mat);
    if(n%2!=0)
        mul(mat,original);
    return mat[0][0]*4+mat[0][1]*2+mat[0][2]*1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>num;
    cout<<yo(num-3);
    return 0;
}
