#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

const int MAXN = 500500;
const int MAXM = 1010;

struct edge
{
    int to,next,cap,flow,cost;
}e[500010];

int n, m, a, b, c, d, u, v, w;
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;

void Init(int n) {
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u,int v,int cap,int cost)
{
    e[tol].to = v;e[tol].cap = cap;e[tol].cost = cost;e[tol].flow = 0;e[tol].next = head[u];head[u] = tol++;
    e[tol].to = u;e[tol].cap = 0;e[tol].cost = -cost;e[tol].flow = 0;e[tol].next = head[v];head[v] = tol++;
}

bool SPFA(int s,int t)
{
    queue<int> q;
    for(int i = 0; i < N; ++i)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(e[i].cap>e[i].flow && dis[v]>dis[u]+e[i].cost)
            {
                dis[v] = dis[u]+e[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1) return false;
    else return true;
}
int MinCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(SPFA(s,t))
    {
        int Min = INF;
        for(int i=pre[t]; ~i; i=pre[e[i^1].to])
        {
            if(Min > e[i].cap-e[i].flow)
                Min = e[i].cap-e[i].flow;
        }
        int costtmp = 0;
        for(int i = pre[t]; ~i; i = pre[e[i^1].to]) {
            e[i].flow += Min;
            e[i^1].flow -= Min;
            // cost += e[i].cost*Min;
            costtmp += e[i].cost;
        }
        if(costtmp > 0) return flow;
        cost += costtmp*Min;
        flow += Min;
    }
    return flow;
}

int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        Init(n+2);
        int s = 0, t = n+1;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            add_edge(s, i, b, a);
            add_edge(i, t, d, -c);
        }
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u, v, INF, w);
            add_edge(v, u, INF, w);
        }
        int cost = 0;
        int flow = MinCostMaxflow(s, t, cost);
        printf("%d\n", -cost);
    }
    return 0;
}
