#include <bits/stdc++.h>
using namespace std;
typedef long long int ii;

int main()
{
    ii k,n,i;
    cin>>n>>k;
    ii ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    deque<ii> dq;
    for(i=0;i<k;i++)
    {
        while(!dq.empty()&&ar[i]>ar[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<ar[dq.front()]<<" ";
    for(i=k;i<n;i++)
    {
        while(!dq.empty()&&dq.front()<=(i-k))
            dq.pop_front();
        while(!dq.empty()&&ar[i]>ar[dq.back()])
            dq.pop_back();
             dq.push_back(i);
          cout<<ar[dq.front()]<<" ";
    }
    return 0;
}
