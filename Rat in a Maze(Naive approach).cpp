#include <bits/stdc++.h>

using namespace std;
int i,j,count1=0;
 int mazesafe(int mat[4][4],int x,int y)
 {
     if(x>=0&&x<4&&y>=0&&y<4&&mat[x][y]==1)
        return 1;
     else
        return 0;
 }
void maze(int mat[4][4],int x,int y)
{
    if(x==3&&y==3)
    {
        count1++;
    }
    else if(mazesafe(mat,x,y)==1)
    {
        maze(mat,x+1,y);
        maze(mat,x,y+1);
    }
}
int main()
{
     int mat[4][4]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
     };
    maze(mat,0 ,0);
    cout<<"Count of Ways are"<<count1;
    return 0;
}
