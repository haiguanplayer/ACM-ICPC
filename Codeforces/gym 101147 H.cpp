#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 15;
int e[N][N][N],dp[N][N][N];
int main()
{
    freopen("commandos.in", "r", stdin);
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(e,0,sizeof(e));
        int t1,t2,t3,t4;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
            e[t1][t2][t3] = t4;
        }

        for(int i = 10;i >= 1;i--)
        {
            for(int j = 1;j <= 10;j++)
            {
                for(int k = 1;k <= 10;k++)
                    dp[i][j][k] = max(max(dp[i+1][j][k],dp[i][j-1][k]),dp[i][j][k-1]) + e[i][j][k];
            }
        }
        printf("%d\n",dp[1][10][10]);
    }
    return 0;
}
