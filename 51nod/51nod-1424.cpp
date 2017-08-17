#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int v[N];
long long dp[N][2];
vector<int> G[N];
int n;

int dfs(int u,int fa)
{
    for(int i = 0;i < G[u].size();i++)
    {
        int son = G[u][i];
        if(son == fa)
            continue;
        dfs(son,u);
        dp[u][1] = max(dp[u][1],dp[son][1]);
        dp[u][0] = max(dp[u][0],dp[son][0]);
    }
    int diff = v[u] + dp[u][1] - dp[u][0];
    dp[u][diff < 0] += abs(diff);
}
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i = 0;i < n-1;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1;i <= n;i++)
        scanf("%d",&v[i]);
    dfs(1,-1);
    printf("%lld\n",dp[1][0]+dp[1][1]);
    return 0;
}
