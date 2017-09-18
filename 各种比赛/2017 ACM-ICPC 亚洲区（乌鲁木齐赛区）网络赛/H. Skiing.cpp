#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 100005;
struct edge
{
    int to,nxt,d;
    edge(int t = 0,int n = 0,int d = 0):to(t),nxt(n),d(d){}
}E[N*5];
int n,m,maxn;
int head[N*5],deg[N],dp[N],tot;
queue<int> q;

void init()
{
    memset(head,-1,sizeof(head));
    memset(deg,0,sizeof(deg));
    memset(dp,0,sizeof(dp));
    while(!q.empty())
        q.pop();
    tot = maxn = 0;
}
void add_edge(int s,int t,int d)
{
    E[tot] = edge(t,head[s],d);
    head[s] = tot++;
}
void topsort()
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u];~i;i = E[i].nxt)
        {
            int v = E[i].to,w = E[i].d;
            //printf("%d %d\n",v,w);
            dp[v] = max(dp[v],dp[u]+w);
            maxn = max(maxn,dp[v]);
            --deg[v];
            if(!deg[v])
                q.push(v);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        int u,v,w;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            deg[v]++;
            add_edge(u,v,w);
        }
        for(int i = 1;i <= n;i++)
            if(!deg[i])
                q.push(i);
        topsort();
        printf("%d\n",maxn);
    }
    return 0;
}
