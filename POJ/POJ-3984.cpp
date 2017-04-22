#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int e[6][6];
int go[2][4]={1,-1,0,0,0,0,-1,1};
int front = 0,index = 1;//模拟队列
int flag = 0;
struct node
{
    int x,y,pre;
    node(int xx=0,int yy=0,int pp=0):x(xx),y(yy),pre(pp){}
}s[55];
bool Judge(int x,int y)
{
    if(x >= 0 && x < 5 && y >= 0 && y < 5)
        return true;
    return false;
}

void Print(int t)
{
    if(s[t].pre != -1)
    {
        Print(s[t].pre);
        printf("(%d, %d)\n",s[t].x,s[t].y);
    }
}
void bfs(int x,int y)
{
    s[front] = node(x,y,-1);
    while(front < index)//非空
    {
        for(int i = 0;i < 4;i++)
        {
            int tx = s[front].x + go[0][i];
            int ty = s[front].y + go[1][i];
            if(Judge(tx,ty) && e[tx][ty]==0)
            {
                e[tx][ty] = 1;
                s[index++] = node(tx,ty,front);//入队
            }
            if(tx == 4 && ty == 4)
                Print(front);
        }
        front++;//出队
    }
}
int main()
{
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            scanf("%d",&e[i][j]);
    printf("(0, 0)\n");
    bfs(0,0);
    printf("(4, 4)\n");
}
