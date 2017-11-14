#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;


int n,k,root,maxn;
ll ans;
int sz[N],maxv[N],a[N];
ll Hash[1205];
vector<int> tree[N];
vector<int> status;
bool vis[N];

void init(){
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++)
        tree[i].clear();
}
void dfs_size(int u,int fa){
    sz[u] = 1;maxv[u] = 0;
    for(auto v : tree[u]){
        if(v == fa || vis[v])
            continue;
        dfs_size(v,u);
        sz[u] += sz[v];
        maxv[u] = max(maxv[u],sz[v]);
    }
}
void dfs_root(int r,int u,int fa){
    maxv[u] = max(maxv[u],sz[r] - sz[u]);
    if(maxn > maxv[u]){
        maxn = maxv[u];
        root = u;
    }
    for(auto v : tree[u]){
        if(v == fa || vis[v])
            continue;
        dfs_root(r,v,u);
    }
}
void dfs_status(int u,int fa,int s){
    status.push_back(s);
    for(auto v : tree[u]){
        if(v == fa || vis[v])
            continue;
        dfs_status(v,u,s | (1 << a[v]));
    }
}
ll cal(int u,int s){
    status.clear();
    dfs_status(u,-1,s);
    memset(Hash,0,sizeof(Hash));
    for(auto x : status)
        Hash[x]++;
    ll res = 0;
    for(auto x : status)
    {
        Hash[x]--;
        res += Hash[(1<<k)-1];
        for(int sta = x;sta != 0;sta = (sta-1) & x)
            res += Hash[((1<<k)-1) ^ sta];
        Hash[x]++;
    }
    return res;
}
void dfs(int u)
{
    maxn = n;
    dfs_size(u,-1);
    dfs_root(u,u,-1);
    ans += cal(root,(1<<a[root]));
    vis[root] = true;
    int rt = root;
    for(auto v : tree[rt]){
        if(vis[v]) continue;
        ans -= cal(v,(1<<a[rt]) | (1<<a[v]));
        dfs(v);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k)){
        init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            --a[i];
        }
        int u,v;
        for(int i = 1;i < n;i++){
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if(k == 1)
        {
            printf("%d\n",n*n);
            continue;
        }
        ans = 0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
