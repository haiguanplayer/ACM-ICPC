#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1005;
const int M = 10005;
int n,m,cnt;
int u[M],v[M],w[M];
int last[N],q[N],h[N],dis[N];
vector<int> G[N];

struct edge
{
    int to,next,v;
    edge(int to=0,int next=0,int v=0):to(to),next(next),v(v){}
}e[M];
void add_edge(int u,int v,int w)
{
    e[++cnt] = edge(v,last[u],w);
    last[u] = cnt;
    e[++cnt] = edge(u,last[v],0);
    last[v] = cnt;
}
void SPFA()
{
    int head = 0,tail = 1;
    for(int i = 1;i <= n;i++)
        dis[i] = -1;
    dis[1] = 0;
    q[0] = 1;
    while(head != tail)
    {
        int u = q[head];
        head++;
        for(int i = 0;i < G[u].size();i++)
        {
            int v = G[u][i];
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q[tail++] = v;
            }
        }
    }
}
bool bfs()
{
    int head = 0,tail = 1;
    for(int i = 1;i <= n;i++)
        h[i] = -1;
    q[0] = 1;
    h[1] = 0;
    while(head != tail)
    {
        int u =q[head];
        head++;
        for(int i = last[u];i;i = e[i].next)
        {
            if(e[i].v && h[e[i].to] == -1)
            {
                h[e[i].to] = h[u]+1;
                q[tail++] = e[i].to;
            }
        }
    }
    return h[n] != -1;
}
int dfs(int x,int f)
{
    if(x == n)
        return f;
    int w,used = 0;
    for(int i = last[x];i;i = e[i].next)
    {
        if(h[e[i].to] == h[x] + 1)
        {
            w = dfs(e[i].to,min(e[i].v,f-used));
            e[i].v -= w;
            e[i^1].v += w;
            used += w;
            if(used == f)
                return f;
        }
    }
    if(!used)
        h[x] = -1;
    return used;
}
int Dinic()
{
    int ans = 0;
    while(bfs())
        ans += dfs(1,INF);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        cnt = 1;
        for(int i = 1;i <= n;i++)
            G[i].clear();
        memset(last,0,sizeof(last));

        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }
        SPFA();
        for(int i = 1;i <= m;i++)
        {
            if(dis[u[i]] == dis[v[i]] + 1)
                add_edge(v[i],u[i],w[i]);
            else if(dis[u[i]] == dis[v[i]] - 1)
                add_edge(u[i],v[i],w[i]);
        }
        printf("%d\n",Dinic());
    }
}

