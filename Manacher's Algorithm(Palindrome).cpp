//MANACHER'S ALGORITHM.
//DEVELOPED BY AMAN JAIN
#include <iostream>
#include <string>

using namespace std;

void manacher(string t)
{
    int l=t.size();
    int pal[l],c,r,i;
    for(i=0;i<l;i++)
        pal[i]=0;
    c=1,r=1;
    for(i=1;i<l-1;i++)
    {
        int mirror=2*c-i;
        if(i<r)
            pal[i]=min(r-i,pal[mirror]);
       while(t[i+1+pal[i]]==t[i-1-pal[i]])
       {
            pal[i]++;
       }
       if(i+pal[i]>r)
       {
           c=i;
           r=i+pal[i];

       }


    }
    int max=0;
    for(i=1;i<l;i++)
    {
        if(max<pal[i])
            max=pal[i];

    }

    cout<<max;

}

int main()
{
    int i;
    string str1,str2;
    cout<<"Enter the String";
    getline(cin,str1);
    str2="@"+str1+"&";
    int m=str1.size();
    for(i=1;i<=m;i++)
        str2.insert(i+i,"#");
        str2.insert(1,"#");
     // cout<<str2;
      manacher(str2);
    return 0;
}
// AMAN JAIN


