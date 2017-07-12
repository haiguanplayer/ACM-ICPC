#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,ans;
int k[N],fa[N],p[N],f[N],dep[N];
vector<int> G[N];//fssdfs
void dfs(int u)
{
    f[u] = dep[u]-k[u]+1;
    p[u] = 1e9;
    for(int i = 0;i < G[u].size();i++)
    {
        dep[G[u][i]]= dep[u]+1;
        dfs(G[u][i]);
        f[u] = min(f[u],f[G[u][i]]);
        p[u] = min(p[u],p[G[u][i]]);
    }
    if(p[u] > dep[u])
    {
        ans++;
        p[u] = f[u];
    }
}
int main()
{
    cin >> n;
    for(int i = 2;i <= n;i++)
    {
        scanf("%d",&fa[i]);
        G[fa[i]].push_back(i);
    }
    for(int i = 1;i <= n;i++)
        scanf("%d",&k[i]);
    dep[1] = 1;
    dfs(1);
    cout << ans << endl;
    return 0;
}
