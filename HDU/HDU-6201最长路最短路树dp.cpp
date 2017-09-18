#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 100005;
struct edge
{
    int to,nxt,d;
    edge(int t = 0,int n = 0,int d = 0):to(t),nxt(n),d(d){}
}E[N*5];
int head[N*5],d[N<<1],tot;
bitset< N<<1 > vis;

void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
void add_edge(int s,int t,int d)
{
    E[tot] = edge(t,head[s],d);
    head[s] = tot++;
}
void SPFA(int s)
{
    memset(d,-0x3f,sizeof(d));
    vis.reset();
    d[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];~i;i = E[i].nxt)
        {
            int v = E[i].to;
            if(d[v] < d[u]+E[i].d)
            {
                d[v] = d[u]+E[i].d;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        int s = 0,t = n*2 + 1;
        int price;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&price);
            add_edge(i,i+n,0);//²ðµã
            add_edge(s,i,-price);
            add_edge(i+n,t,price);
        }
        int u,v,w;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u+n,v,-w);
            add_edge(v+n,u,-w);
        }
        SPFA(s);
        printf("%d\n",d[t]);
    }
}


树dp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;

struct edge
{
    int v,w;
};
vector<edge> G[N];
int maxn,dp[N][2],p[N];
void dfs(int u,int fa)
{
    dp[u][0] = -p[u];
    dp[u][1] = p[u];
    for(auto e : G[u])
    {
        int v = e.v,w = e.w;
        if(v == fa)
            continue;
        dfs(v,u);
        dp[u][0] = max(dp[u][0],dp[v][0]-w);
        dp[u][1] = max(dp[u][1],dp[v][1]-w);
    }
    maxn = max(maxn,dp[u][0]+dp[u][1]);
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            G[i].clear();
        for(int i = 1;i <= n;i++)
            scanf("%d",&p[i]);
        --n;
        while(n--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        maxn = -0x3f3f3f3f;
        dfs(1,-1);
        printf("%d\n",maxn);
    }
    return 0;
}
