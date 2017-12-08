#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mat[2][2]={{1,1},{1,0}};
ll fix[2][2]={{1,1},{1,0}};

void matrix_mul(ll a[2][2],ll b[2][2])
{
   ll aj[2][2];
   memset(aj,0,sizeof(aj));
   for(int i=0;i<2;i++)
   {
       for(int j=0;j<2;j++)
       {
           for(int k=0;k<2;k++)
           {
               aj[i][j]+=(a[i][k]*b[k][j]);
           }
       }
   }
   for(int i=0;i<2;i++)
   {
       for(int j=0;j<2;j++)
        mat[i][j]=aj[i][j];
   }
}

ll yo(ll n)
{
    if(n==1)
        return (mat[0][1]+mat[0][0]);
        yo(n/2);
        matrix_mul(mat,mat);
        if(n%2!=0)
            matrix_mul(fix,mat);
        return (mat[0][1]+mat[0][0]);
}

int main()
{
    ll n,t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    if(n==1||n==2)
    cout<<"1"<<endl;
    else
    cout<<yo(n-2)<<endl;
    mat[0][0]=1;
    mat[0][1]=1;
    mat[1][0]=1;
    mat[1][1]=0;
    }
    return 0;
}
