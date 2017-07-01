// code like a pro,wanna be developer
// code your way to success.
// Aman Jain
#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;

void Manacher(string s)
{
    ii r,c,ar[s.size()],i,l,lp;
    r=1;c=1;
    memset(ar,0,sizeof(ar));
    for(i=1;i<s.size();i++)
    {
        ii mirror=c-(i-c);
        if(r>i){
            ar[i]=min(r-i,ar[mirror]);
        }
        while((s[i+1+ar[i]]==s[i-1-ar[i]])&&((i-1-ar[i])>=0)&&((i+1+ar[i])<s.size()))
              {
        ar[i]++;
        }
        if(ar[i]+i>r)
        {
            r=i+ar[i];
            c=i;
        }

    }
   ii max1=ar[0],jk=0;
    for(i=1;i<s.size();i++)
    {
        if(ar[i]>max1){
        max1=ar[i];
        jk=i;
        }
    }
    cout<<max1<<endl;
        for(lp=(jk-(max1-1));lp<=(jk+(max1-1));lp+=2)
            cout<<s[lp];

}

int main()
{
    string s,o;
    ii i;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
       o+="#"+s.substr(i,1);
    }
    o+="#";
    Manacher(o);

}
