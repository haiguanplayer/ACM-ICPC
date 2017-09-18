#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 10005;
int n,m,s,t,tot;
int head[N],dep[N],cur[N];

struct edge
{
    int to,nxt,cap;
    edge(int t = 0,int n = 0,int c = 0):to(t),nxt(n),cap(c){}
}E[N];

void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
void add(int u,int v,int cap)
{
    E[tot] = edge(v,head[u],cap);
    head[u] = tot++;
}
bool bfs(int s,int t)
{
    memset(dep,-1,sizeof(dep));
    queue<int> q;
    dep[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i = head[u];~i;i = E[i].nxt)
        {
            int v = E[i].to;
                if(E[i].cap > 0 && dep[v] == -1)
                {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
        }
    }
    return dep[t] != -1;
}
int dfs(int u,int flow)
{
    if(u == t)
        return flow;
    int w ,used = 0;
    for(int i = head[u];~i;i = E[i].nxt)
    {
        int v = E[i].to;
        if(dep[v] == dep[u]+1)
        {
            w = flow - used;
            w = dfs(v,min(w,E[i].cap));
            E[i].cap -= w;
            E[i^1].cap += w;
            if(v) cur[u] = i;
            used += w;
            if(used == flow) return flow;
        }
    }
    if(!used) dep[u] = -1;
    return used;
}
int dinic(int s,int t)
{
    int res = 0;
    while(bfs(s,t))
    {
         for(int i = 1;i <= t;i++)
            cur[i] = head[i];
         res += dfs(s,INF);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        int u,v,w;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w*1000+1);
            add(v,u,0);
        }
        printf("%d\n",dinic(s,t)%1000);
    }
    return 0;
}
