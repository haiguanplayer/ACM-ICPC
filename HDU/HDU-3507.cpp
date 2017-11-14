/*
g[i,j] = getUP(i,j) / getDOWN(i,j) < sum[i] i�ľ�������j�ľ���
б���Ż��ĵط���
��k<j<i�����g[i,j]<g[j,k]�����Ǽ���g[i,j]<sum[i]����ô����˵i��Ҫ��j���ţ��ų�j�㡣
���g[i,j]>=sum[i]����ôj���ʱ�Ǳ�i��Ҫ���ţ�����ͬʱg[j,k]>g[i,j]>sum[i]����˵������k����j����ţ�ͬ���ų�j�㡣

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
                head++;//g[b,a]<sum[i]����ô˵��b���a����ţ�����
            dp[i] = getDP(i,q[head]);
            while(head + 1 < tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2]) <= getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]))
                tail--;
            q[tail++] = i;//�ҵ��˸��ŵģ����
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
