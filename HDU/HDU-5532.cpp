/*
题意；给你一段序列，让你判断其是否是 almost sorted ，如果是的话就输出YES，else NO
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N = 100005;
int a[N],dp[N];
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);//,dp[i] = 1;
        int num = 1,pos;dp[1] = a[1];
        for(int i = 2;i <= n;i++)
            if(a[i] >= dp[num])
                dp[++num] = a[i];
            else
            {
                pos = upper_bound(dp+1,dp+num,a[i])-dp;
                dp[pos] = a[i];
            }

        int len = 1;dp[1] = a[n];
        for(int i = n-1;i >= 1;i--)
            if(a[i] >= dp[len])
                dp[++len] = a[i];
            else
            {
                pos = upper_bound(dp+1,dp+len,a[i])-dp;
                dp[pos] = a[i];
            }

        if(num >= n-1 || len >= n-1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
