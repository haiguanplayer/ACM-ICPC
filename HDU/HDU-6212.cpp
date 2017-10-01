#include<bits/stdc++.h>
using namespace std;

const int N = 205;

char str[N];
int cnt[N],dp[N][N];

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        int n = 0;
        scanf("%s",str);
        cnt[++n] = 1;
        for(int i = 1;str[i] != '\0';i++)
        {
            if(str[i] != str[i-1])
                cnt[++n] = 0;
            cnt[n]++;
        }
        for(int i = n;i > 0;i--)
        {
            for(int j = i;j <= n;j++)
            {
                if(i == j)
                {
                    dp[i][j] = 3-cnt[i];
                    continue;
                }
                dp[i][j] = n*2;
                for(int k = i;k < j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if((j-i) & 1)//间隔是奇数，i、j颜色不同
                    continue;
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]+(cnt[i]+cnt[j] == 2));//等中间消掉
                if(cnt[i] + cnt[j] < 4)//i、j存在有1和大于1，i,k,j同色
                {
                    for(int k = i+2;k < j;k+=2)
                        if(cnt[k] == 1)dp[i][j] = min(dp[i][j],dp[i+1][k-1]+dp[k+1][j-1]);
                }
            }
        }
        printf("Case #%d: %d\n",ca,dp[1][n]);
    }
}
