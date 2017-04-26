#include<bits/stdc++.h>
using namespace std;


using namespace std;
#define MAXN 1005      // vertex
#define MAXM 20005      // edge
#define INF 0x3F3F3F3F

struct node
{
    int v, w, next;
}pnt[MAXM];

int head[MAXN];
int  dis[MAXN];
bool vis[MAXN];
int  cnt[MAXN];       // the number of the operation of push to Quque. negatvie cycle.
int num = 0;          // the index of the edge
int N ;               // the number of the vertex.
int M ;               // the number of edges
int src, sink;
void addedge(int  u, int v, int w)
{
    pnt[num].v = v; pnt[num].w= w;
    pnt[num].next = head[u]; head[u] = num++;
}

int SPFA()
{
    for(int i=0; i<=N; i++)
    {
        vis[i]=0; dis[i] = INF; cnt[i] = 0;
    }

    queue<int> Q;
    Q.push(src); vis[src] = 1; dis[src] = 0; ++cnt[src];
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();  vis[u] = 0;
        for(int i=head[u]; i!=-1; i=pnt[i].next)
        {
            int v = pnt[i].v;
            if( dis[v] > dis[u] + pnt[i].w  )
            {
                dis[v] = dis[u] + pnt[i].w;
                if(!vis[v]) {Q.push(v); vis[v] = 1;}
                if( ++cnt[v] > N) return -1; // negative cycle.
            }
        }
    }
    if(dis[sink] == INF) return -2; // can't from src to sink.
    return dis[sink];
}

int main()
{
    int ml,md;
    while(scanf("%d%d%d", &N , &ml, &md)!= EOF)
    {
        num = 0;
        memset(head, -1, sizeof(head));
        int a, b, c;
        for(int i=0; i<ml; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(a>b) swap(a,b);
            addedge(a, b,c);
        }
        for(int i=0; i<md; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(a<b) swap(a,b);
            addedge(a, b, -c);
        }
        src = 1; sink = N;
        printf("%d\n", SPFA());
    }
    return 0;
}
