#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll i,ar[100001],heap_size;

void heapify(ll ar[],ll n)
{
    ll largest=n;
    if(2*n<=heap_size&&ar[largest]<ar[2*n])
        largest=2*n;
    if((2*n+1)<=heap_size&&ar[largest]<ar[2*n+1])
    largest=2*n+1;
    if(largest!=n){
    swap(ar[n],ar[largest]);
    heapify(ar,largest);
    }
}


void heap_sort()
{
    for(int k=heap_size/2;k>=0;k--)
    heapify(ar,k);
    for(int j=heap_size;j>=0;j--)
    {
        swap(ar[j],ar[0]);
        heap_size--;
        heapify(ar,0);
    }
}

int main()
{
    ll yo;
    cin>>yo;
    heap_size=yo-1;
    for(i=0;i<yo;i++)
        cin>>ar[i];
        heap_sort();
        for(i=0;i<yo;i++)
            cout<<ar[i]<<" ";
    return 0;
}
