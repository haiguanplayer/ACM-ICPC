/*
g[i,j] = getUP(i,j) / getDOWN(i,j) < sum[i] i的决策优于j的决策
斜率优化的地方：
设k<j<i，如果g[i,j]<g[j,k]，我们假设g[i,j]<sum[i]，那么就是说i点要比j点优，排除j点。
如果g[i,j]>=sum[i]，那么j点此时是比i点要更优，但是同时g[j,k]>g[i,j]>sum[i]。这说明还有k点会比j点更优，同样排除j点。

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
int n,M;
int dp[N],sum[N],q[N];
int head,tail;

int getUP(int j,int k)
{
    return dp[j] + sum[j]*sum[j] - (dp[k] + sum[k]*sum[k]);
}
int getDOWN(int j,int k)
{
    return (sum[j] - sum[k])*2;
}
int getDP(int i,int j)
{
    return dp[j] + M + (sum[i] - sum[j])*(sum[i] - sum[j]);
}
int main()
{
    while(~scanf("%d%d",&n,&M))
    {
        int x;
        for(int i = 1;i <= n;i++)
            scanf("%d",&x),sum[i] = sum[i-1] + x;
        head = tail = 0;
        q[tail++] = 0;
        dp[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            while(head + 1 < tail && getUP(q[head+1],q[head]) <= getDOWN(q[head+1],q[head])*sum[i])
                head++;//g[b,a]<sum[i]，那么说明b点比a点更优，出队
            dp[i] = getDP(i,q[head]);
            while(head + 1 < tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2]) <= getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]))
                tail--;
            q[tail++] = i;//找到了更优的，入队
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
