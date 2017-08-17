#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 1e5+5;
int x[N];
long long dp[N][2];
vector<int> G[N];
int n;

int dfs(int u,int fa)
{
    if(x[u])
        dp[u][1] = 1;
    else
        dp[u][0] = 1;
    for(int i = 0;i < G[u].size();i++)
    {
        int son = G[u][i];
        if(son == fa)
            continue;
        dfs(son,u);
        dp[u][1] = (dp[u][1]*(dp[son][0]+dp[son][1]) + dp[u][0]*dp[son][1])%MOD;
        dp[u][0] = (dp[u][0]*(dp[son][0]+dp[son][1]))%MOD;
    }
}
int main()
{
    scanf("%d",&n);
    int y;
    for(int i = 0;i < n-1;i++)
    {
        scanf("%d",&y);
        G[y].push_back(i+1);
        G[i+1].push_back(y);
    }
    for(int i = 0;i < n;i++)
        scanf("%d",&x[i]);
    dfs(0,-1);
    printf("%lld\n",dp[0][1]);
    return 0;
}
