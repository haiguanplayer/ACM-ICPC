#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int main()
{
    int T,n,m,x,y;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                scanf("%d",&dp[i][j]);
        int maxn = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                if(i >= x && j >= y)
                    maxn = max(maxn,dp[i][j]-dp[i-x][j]-dp[i][j-y]+dp[i-x][j-y]);
            }
        }
        printf("%d\n",maxn);
    }
}
