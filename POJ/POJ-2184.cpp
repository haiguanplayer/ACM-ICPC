#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 200000;
int dp[N*2];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i=0;i<=200000;i++)
            dp[i]=-INF;
        dp[100000]=0;
        int a,b;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a < 0 && b < 0)
                continue;
            if(a > 0)
            {
                for(int j = N;j-a >= 0;j--)
                {
                    if(dp[j-a] > -INF)
                        dp[j] = max(dp[j],dp[j-a]+b);
                }
            }
            else
            {
                for(int j = a;j <= N+a;j++)
                {
                    if(dp[j-a] > -INF)
                        dp[j] = max(dp[j],dp[j-a]+b);
                }
            }
        }
        int ans = -INF;
        for(int j = N/2;j <= N;j++)
            if(dp[j] >= 0)
                ans = max(ans,dp[j]+j-N/2);
        printf("%d\n",ans);
    }
    return 0;
}
