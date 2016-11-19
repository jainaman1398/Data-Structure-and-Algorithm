#include <stdio.h>
#include <stdlib.h>
int j=0,i;
char s[51];
void push(char c)
{
  s[j++]=c;
}

void pop()
{
    j=j-1;
}
char top()
{
 return c;
}

void reverse(char c[],int n)
{

    for( i=0;i<n-1;i++){
        push(c[i]);}
        for( i=0;i<n-1;i++)
        {
            c[i]=top();
            pop();
        }
}

int main()
{
   char c[51],a[51];
   printf("enter a string");
   gets(c);
   s.puts(top());

   reverse(c,strlen(c));
   //printf("output=%s",c);
   puts(c);
     printf("output=%c",c);
    return 0;
}
