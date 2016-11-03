/*
题意：将两个所给点用两点连起的直线分开
思路：看是否横坐标相同，判断即可
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    int w,h,x1,y1,x2,y2;
    while(~scanf("%d%d",&w,&h))
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1 == x2)
            printf("%d %d %d %d\n",0,y1,w,y2);
        else
            printf("%d %d %d %d\n",x1,0,x2,h);
    }
    return 0;
}
