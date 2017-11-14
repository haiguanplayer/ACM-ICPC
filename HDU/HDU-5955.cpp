#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> G[N];
int vis[N][N],cnt[N],ans,n,m,s;

void dfs(int u,int k)
{
    if(k == s)
    {
        ans++;
        return;
    }
    for(auto v : G[u])
    {
        bool flag = true;
        for(int i = 1;i <= k;i++)
        if(vis[cnt[i]][v] == 0){
            flag = false;
            break;
        }
        if(!flag)
            continue;
        cnt[k+1] = v;
        dfs(v,k+1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < N;i++)
            G[i].clear();
        scanf("%d%d%d",&n,&m,&s);
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            G[min(u,v)].push_back(max(u,v));
            vis[u][v] = vis[v][u] = 1;
        }
        ans = 0;
        for(int i = 1;i <= n;i++)
        {
            cnt[1] = i;
            dfs(i,1);
        }
        printf("%d\n",ans);
    }
}
