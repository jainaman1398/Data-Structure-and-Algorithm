#include <iostream>
#include <string>

using namespace std;

void kmp(string t,string p,int ar[])
{
    int k=t.size(),i=0,count1=0,j=0;
    int m=p.size();
   while(i<k&&j<m)
         {
            if(t[i]==p[j])
            {
                i++;
                j++;
            }
            else{
           if(j!=0){
                    j = ar[j-1];
                }else{
                    i++;
                }

            }
         }
         if(j==m)
            cout<<"1";
         else
            cout<<"0";
}

int main()
{
    int i;
    string t,p;
   getline(cin,t);
    getline(cin,p);
    int j=p.size(),q=0,ar[j];
    ar[0]=0;
    for(i=1;i<j;)
    {
        if(p[i]==p[q])
        {
            ar[i]=q+1;
            i++;
             q++;
        }
        else
        {
            if(q!=0)
                q=ar[q-1];
            else
            {
                ar[i]=0;
                i++;
            }


        }

    }
    kmp(t,p,ar);
    return 0;
}
