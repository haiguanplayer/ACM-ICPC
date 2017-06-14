#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 3005;
const int M = 70005;

struct Edge
{
    int v, w, next;
}et[M];
int n,m,num;
int eh[N],dis[N],in[N],mt[N];
bool vis[N];
vector<int> G[N];
typedef pair <int,int> pii;

void add(int u, int v, int w){
    Edge e = {v, w, eh[u]};
    et[num] = e;
    eh[u] = num++;
}
int Dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    dis[s] = 0;
    Q.push(pii(dis[s], s));
    while(!Q.empty())
    {
        pii cur = Q.top();
        Q.pop();
        int u = cur.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            in[v]--;
            mt[v] = max(mt[v], dis[u]);
            if(dis[v] != INF && !in[v])
            {
                dis[v] = max(dis[v], mt[v]);
                Q.push(pii(dis[v], v));
            }
        }
        for(int i = eh[u]; i != -1; i = et[i].next)
        {
            int v = et[i].v, w = et[i].w;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = max(dis[u] + w, mt[v]);
                if(!in[v]) Q.push(pii(dis[v], v));
            }
        }
    }
    return dis[n];
}
int main()
{
    int t, a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);

        num = 0;
        for(int i = 1; i <= n; i++)
        {
            dis[i] = INF;
            vis[i] = false;
            mt[i] = 0;
            eh[i] = -1;
            G[i].clear();
        }

        while(m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&in[i]);
            for(int j = 0;j < in[i];j ++)
            {
                scanf("%d", &a);
                G[a].push_back(i);
            }
        }
        printf("%d\n", Dijkstra(1));
    }
    return 0;
}
