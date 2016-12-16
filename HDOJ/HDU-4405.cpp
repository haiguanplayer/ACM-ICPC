/*
定义状态dp[i]表示处于i位置时所扔色子次数的期望
*/
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 100005;
double dp[N];
int fly[N];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        memset(dp,0,sizeof(dp));
        memset(fly,0,sizeof(fly));
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            fly[u] = v;
        }
        for(int i = n-1;i >= 0;i--)
        {
            if(fly[i])
                dp[i] = dp[fly[i]];
            else
            {
                for(int j = 1;j <= 6;j++)
                {
                    if(i+j >= n)
                        dp[i] += 1.0/6*dp[n];
                    else
                        dp[i] += 1.0/6*dp[i+j];
                }
                dp[i]++;
            }
        }
        printf("%.4f\n",dp[0]);
    }
    return 0;
}
