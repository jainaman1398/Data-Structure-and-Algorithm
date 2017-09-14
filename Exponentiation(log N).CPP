#include <iostream>
using namespace std;
typedef long long int ll;

ll pow(ll n,ll x)
{
    if(x==1)
        return n;
    else{
        if(x%2==0)
        return pow(n*n,x/2);
        else
            return n*pow(n*n,(x-1)/2);
    }
}

int main()
{
    ll n,x,op;
    cin>>n>>x;
        op=pow(n,x);
       cout<<op;
    return 0;
}
