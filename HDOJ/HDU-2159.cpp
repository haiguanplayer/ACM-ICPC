
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;
int v[N],w[N],dp[N][N];
int main()
{
    int n,m,k,s;
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for(int i = 1;i <= k;i++)
            scanf("%d%d",&v[i],&w[i]);

        memset(dp,0,sizeof(dp));
        bool flag = false;
        int ans;
        for(int i = 1;i <= m;i++)//枚举消耗的忍耐力
        {
            for(int j = 1;j <= k;j++)//枚举怪物种类
            {
                for(int h = 1;h <= s;h++)//枚举怪物个数
                {
                    int cnt = 1;
                    while(cnt * w[j] <= i && cnt <= h)//如果在忍耐度内并且在怪的个数内
                    {
                        dp[i][h] = max(dp[i][h], dp[i - cnt*w[j]][h - cnt] + cnt*v[j]);
                        cnt++;
                    }
                    if(dp[i][h] >= n)//升级的话
                    {
                        ans = m - i;
                        flag = true;
                        break;
                    }
                }
                if(flag)    break;
            }
            if(flag)    break;
        }
        if(flag)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
