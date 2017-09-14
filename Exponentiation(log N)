#include <iostream>
using namespace std;
typedef long long int ll;

ll pow(ll n,ll x)
{
    if(x==1)
        return n;
    else
        return pow(n*n,x/2);
}

int main()
{
    ll n,x,op;
    cin>>n>>x;
    if(x%2!=0)
        op=n*pow(n,x-1);
    else
        op=pow(n,x);
       cout<<op;
    return 0;
}
