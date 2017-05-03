#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> G[N];
int vis[N],used[N];
int dfs(int x)
{
    for(int i = 0;i < G[x].size();i++)
    {
        int u = G[x][i];
        if(!vis[u])
        {
            vis[u] = 1;
            if(!used[u] || dfs(used[u]))
            {
                used[u] = x;
                used[x] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0;i < N;i++)
            G[i].clear();
        memset(used,0,sizeof(used));
        int u,v;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(!used[i])
            {
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
