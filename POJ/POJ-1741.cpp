#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e4 + 5;

struct node{
    int v,w;
};
int n,k,root,maxn,ans;
int sz[N],maxv[N];
vector<node> tree[N];
vector<int> dis;
bool vis[N];

void init(){
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++)
        tree[i].clear();
}
void dfs_size(int u,int fa){
    sz[u] = 1;maxv[u] = 0;
    for(auto x : tree[u]){
        int v = x.v;
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
    for(auto x : tree[u]){
        int v = x.v;
        if(v == fa || vis[v])
            continue;
        dfs_root(r,v,u);
    }
}
void dfs_dis(int u,int fa,int d){
    dis.push_back(d);
    for(auto x : tree[u]){
        int v = x.v,w = x.w;
        if(v == fa || vis[v])
            continue;
        dfs_dis(v,u,d+w);
    }
}
int cal(int u,int d){
    int ans = 0;
    dis.clear();
    dfs_dis(u,-1,d);
    sort(dis.begin(),dis.end());
    int i = 0,j = dis.size()-1;
    while(i < j){
        while(dis[i]+dis[j] > k && i < j)
            --j;
        ans += j-i;
        ++i;
    }
    return ans;
}
void dfs(int u)
{
    maxn = n;
    dfs_size(u,-1);
    dfs_root(u,u,-1);
    ans += cal(root,0);
    vis[root] = true;
    int rt = root;
    for(auto x : tree[rt]){
        int v = x.v,w = x.w;
        if(vis[v]) continue;
        ans -= cal(v,w);
        dfs(v);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k) && (n || k)){
        init();
        int u,v,w;
        for(int i = 1;i < n;i++){
            scanf("%d%d%d",&u,&v,&w);
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
        }
        ans = 0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
