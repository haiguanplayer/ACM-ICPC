
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;


const int N = 1100;
int C[N][N];
int lowbit[N];
int s;

void add(int y,int x,int a)
{
    while(y <= s)
    {
        int tmpx = x;
        while(tmpx <= s)
        {
            C[y][tmpx] += a;
            tmpx += lowbit[tmpx];
        }
        y += lowbit[y];
    }
}

int Query(int y, int x)//查询第1 行到第y行，第1 列到第x列的和
{
    int nSum = 0;
    while(y > 0)
    {
        int tmpx = x;
        while(tmpx > 0)
        {
            nSum += C[y][tmpx];
            tmpx -= lowbit[tmpx];
        }
        y -= lowbit[y];
    }
    return nSum;
}

int main()
{
    for(int i = 1;i <= N;i++)
        lowbit[i] = i &(-i);

    int choice,x,y,a,l,b,r,t;
    while(scanf("%d",&choice) && choice != 3)
    {
        switch(choice)
        {
        case 0:
            scanf("%d",&s);
            memset(C,0,sizeof(C));
            break;
        case 1:
            scanf("%d%d%d",&x ,&y,&a);
            add(y + 1,x + 1,a);
            break;
        case 2:
            scanf("%d%d%d%d",&l,&b,&r,&t);
            l++,b++,r++,t++;
            printf("%d\n",Query(t,r)+Query(b-1,l-1)-Query(t,l-1)-Query(b-1,r));
            break;
        }
    }
    return 0;
}
