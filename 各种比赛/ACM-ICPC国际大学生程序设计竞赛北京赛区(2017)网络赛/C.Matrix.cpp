//by http://www.cnblogs.com/jianrenfang/p/7582502.html
#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define met(a,b) memset(a,b,sizeof a)
typedef long long ll;
const int N = 305;
int t,n,m;
int a[N][N],p,sum[N];
int mn[N],dp[N][2],len[N];
bool flag;
int solve()
{
    dp[0][0]=dp[0][1]=0;
    int ret=-inf;len[0]=0;
    for(int i=1;i<=m;i++)
    {
        if(dp[i-1][0]>0)
        {
            dp[i][0]=dp[i-1][0]+sum[i];
            len[i]=len[i-1]+1;
        }
        else
        {
            dp[i][0]=sum[i];
            len[i]=1;
        }
        if(i==1)
            dp[i][1]=sum[1]-mn[1]+p;
        else
        {
            dp[i][1]=max(sum[i]-mn[i]+p,dp[i-1][0]+sum[i]-mn[i]+p);
            dp[i][1]=max(dp[i][1],dp[i-1][1]+sum[i]);
        }
        ret=max(ret,dp[i][1]);
        if(flag&&len[i]==m)continue;//最大值为整个矩阵，没有修改，所以不考虑
        ret=max(ret,dp[i][0]);
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = -inf;
        for(int i = 1; i <= n; ++i)
        {
            met(sum,0);met(mn,inf);flag=false;
            for(int j = i; j <=n; ++j)
            {
                for(int k = 1; k <= m; ++k)
                {
                    sum[k]+=a[j][k];
                    mn[k]=min(mn[k],a[j][k]);
                }
                if(i==1&&j==n)flag=true;
                ans=max(ans,solve());
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
