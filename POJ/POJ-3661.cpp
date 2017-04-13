/*
���⣺Bessie ��n����ʱ���ڣ�ÿ���ӿ���ѡ���ߺͲ��ߣ��ߵĻ�ƣ��ֵ+1�����ߵĻ�ƣ��ֵ-1�����ҽ���ƣ��ֵ����0ʱ����ƣ��ֵ���ܴ���m��Ҫ����Զ���롣
˼·:
if(j <= i)
    dp[i][0] = max(dp[i][0],dp[i-j][j]);
dp[i][j] = dp[i-1][j-1] + a[i];//max(dp[i-1][j-1] + a[i],dp[i-1][j+1]);

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4+5;
int a[N],dp[N][505];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);

    for(int i = 1;i <= n;i++)
    {
        dp[i][0] = dp[i-1][0];
        for(int j = 1;j <= m;j++)
        {
            if(j <= i)
                dp[i][0] = max(dp[i][0],dp[i-j][j]);
            dp[i][j] = dp[i-1][j-1] + a[i];//max(dp[i-1][j-1] + a[i],dp[i-1][j+1]);
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}
