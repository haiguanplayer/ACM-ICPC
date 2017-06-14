#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;;
const ll INF = 1ll*1e18;
const int N = 20005*3;

struct node
{
    int v,cost;
    node(int v,int c):v(v),cost(c){}
    node(){}
    bool operator<(const node&p)const
    {
        return cost > p.cost;
    }
};
vector<node> G[N];
//vector<int> H[N];
//int dis[N],vis[N];
int vis[N];
ll dis[N];
int n,m;

//priority_queue<node> pq;

void Dijkstra(int x)
{
    for(int i = 0; i <= n; i++)
        dis[i] = INF;
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    dis[x] = 0;
    q.push(node(x,0));
    node cur;
    while(!q.empty())
    {
        cur = q.top();
        q.pop();
        int u = cur.v;
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i = 0;i < G[u].size();i++)
        {
            int v = G[cur.v][i].v;
            int cost = G[u][i].cost;
            if(!vis[v]&&dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                q.push(node(v,dis[v]));
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int k,x;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&x);
            G[x].push_back(node(i+n,0));
            G[i+n+m].push_back(node(x,0));
        }
    }
    /*
    G.clear();
    G.resize(n+1);*/
    int m1,m2,y,w;
    scanf("%d",&m1);
    for(int i = 1;i <= m1;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        G[x].push_back(node(y,w));
        G[y].push_back(node(x,w));
    }
    scanf("%d",&m2);
    for(int i = 1;i <= m2;i++)
    {
        scanf("%d%d%d",&x,&y,&w);/*
        for(int j = 0;j < H[x].size();j++)
        {
            for(int k = 0;k < H[y].size();k++)
            {
                G[j].push_back(node(k+l,w));
                G[k].push_back(node(j+l,w));
            }
        }*/
        G[x+n].push_back(node(y+n+m,w));
        G[y+n].push_back(node(x+n+m,w));
    }

    int s,t;
    scanf("%d%d",&s,&t);
    n = n + m*2;
    Dijkstra(s);
    if(dis[t] == INF)
        printf("-1\n");
    else
        printf("%lld\n",dis[t]);
    /*
    //dijkstra
    pq.push(node(s,0));//第一个人
    node p,q;
    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();
        if(vis[p.v])
            continue;
        vis[p.v] = 1;
        if(p.v == t)
            break;
        int num = G[p.v].size();
        for(int i = 0;i < num;i++)
        {
            q.v = G[p.v][i].v;
            if(vis[q.v])
                continue;
            q.w = p.w + G[p.v][i].w;
            pq.push(q);

        }
    }
    if(p.w == INF)
        printf("-1\n");
    else
        printf("%d\n",p.w);*/
    return 0;
}
