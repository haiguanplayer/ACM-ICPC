#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e4 + 5;
const int M = 1e5 + 5;
int n,m,cnt,vis[N];
ll d[N],p[64],a[M*4];
struct node{
    int v;
    ll w;
};
vector<node> G[N];

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i].v;ll w = G[u][i].w;
        if(!vis[v])
        {
            d[v] = d[u]^w;
            dfs(v);
        }
        else
            a[++cnt] = d[v]^d[u]^w;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int u,v;ll w;
    while(m--)
    {
        scanf("%d%d%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(1);
    for(int i = 1;i <= cnt;i++)
    {
        for(int j = 62;j >= 0;j--)
        {
            if(!(a[i] >> j)) continue;
            if(!p[j]){
                p[j] = a[i];
                break;
            }
            a[i] ^= p[j];
        }
    }
    ll ans = d[n];
    for(int i = 62;i >= 0;i--)
        if((ans^p[i]) > ans)
            ans = ans ^ p[i];
    printf("%lld\n",ans);
    return 0;
}
