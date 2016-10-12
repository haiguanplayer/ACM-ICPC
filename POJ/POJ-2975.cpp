/*
给定一种Nim状态（相当于含N堆石头），求能有几种方法能通过调整某
一堆石头的状态（只准取出），使新的Nim状态为必败态。
（或者说求出所给的Nim游戏状态有多少种方法能够赢）
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1005];
int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            ans ^= a[i];
        }
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if((ans ^ a[i]) < a[i])
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
