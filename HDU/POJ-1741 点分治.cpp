#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 10005;
struct edge
{
    int to,nxt,d;
    edge(int t = 0,int n = 0,int d = 0):to(t),nxt(n),d(d){}
}E[N*5];
int n,k,root,ans,sum;
int head[N*5],num[N],dp[N],d[N],deep[N],vis[N],tot;

void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    tot = root = ans = sum = 0;
}
void add_edge(int s,int t,int d)
{
    E[tot] = edge(t,head[s],d);
    head[s] = tot++;
}
void dfs(int u,int fa)
{
    num[u] = 1;
    dp[u] = 0;
    for(int i = head[u];~i;i = E[i].nxt)
    {
        int v = E[i].to;
        if(v == fa || vis[v])
            continue;
        dfs(v,u);
        num[u] += num[v];
        dp[u] = max(dp[u],num[v]);
    }
    dp[u] = max(dp[u],sum-num[u]);
    if(dp[u] < dp[root])
        root = u;
}
void getdeep(int u,int fa)
{
    deep[++deep[0]] = d[u];
    for(int i = head[u];~i;i = E[i].nxt)
    {
        int v = E[i].to,w = E[i].d;;
        if(v == fa || vis[v])
            continue;
        d[v] = d[u]+w;
        getdeep(v,u);
    }
}
int cal(int u,int w)
{
    d[u] = w;
    deep[0] = 0;
    getdeep(u,0);
    sort(deep+1,deep+deep[0]+1);
    int l= 1,r = deep[0],sum = 0;
    while(l < r)
    {
        if(deep[l] + deep[r] <= k)
        {
            sum += r-l;
            l++;
        }
        else
            r--;
    }
    return sum;
}
void solve(int u)
{
    ans += cal(u,0);
    vis[u] = 1;
    for(int i = head[u];~i;i = E[i].nxt)
    {
        int v = E[i].to,w = E[i].d;
        if(vis[v])
            continue;
        ans -= cal(v,w);
        sum = num[v];
        root = 0;
        dfs(v,0);
        solve(root);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k) && (n || k))
    {
        init();
        int u,v,w;
        for(int i = 1;i <= n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        dp[0] = INF;
        sum = n;
        dfs(1,0);
        solve(root);
        printf("%d\n",ans);
    }
    return 0;
}
