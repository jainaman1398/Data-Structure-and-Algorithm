// copyright-> Aman Jain (jainaman1398)
//this is useful for long range.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ii;
 
ii ar[1000001],vihu[1000001];

void initial()
{
    ii i,j;
    for(i=2;i*i<=(1000000);i++)
    {
        if(ar[i]==0)
        {
             for(j=2*i;j<=(1000000);j+=i)
              {
                 ar[j]=1;
              }
        }
    }
    for(i=1;i<=1000000;i++)
    vihu[i]=i;
    for(i=2;i*i<=1000000;i++)
    {
        if(ar[i]==0)
          {
              for(j=2*i;j<=1000000;j+=i)
                {
                   vihu[j]=(vihu[j]/i)*(i-1);
                }
          }
    }
     for(i=1;i<=1000000;i++)
   {
      if(vihu[i]==i)
      vihu[i]-=1;
   }
}
 
int main() {
    int n;
    initial();
    cin>>n;
    cout<<vihu[n];
    return 0;
}
 
   
