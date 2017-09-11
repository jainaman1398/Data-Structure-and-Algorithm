#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0,i,j;
        cin>>n;
        ll ar[n+1];
        for(i=1;i<=n;i++){
            cin>>ar[i];
            sum+=ar[i];
        }
         bool table[n+1][sum/2+1];
        if(sum%2!=0){

            cout<<"NO"<<endl;
        }
        else
        {

            for(i=0;i<=sum/2;i++)
                table[0][i]=false;
                for(i=0;i<=n;i++)
                table[i][0]=true;

                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=sum/2;j++)
                    {
                        if(ar[i]<=j)
                        {
                            table[i][j]=table[i-1][j-ar[i]]||table[i-1][j];
                        }
                        else if(ar[i]>j)
                        {
                            table[i][j]=table[i-1][j];
                        }
                    }
                }

                if(table[n][sum/2]==true)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
        }
    }
    return 0;
}
