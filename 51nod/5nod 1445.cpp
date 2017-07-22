#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 55;
vector<int> G[N];
int n,dis[N],vis[N];

struct node
{
    int v,w;
    node(int v=0,int w=0):v(v),w(w){}
    bool operator < (const node & p)const
    {
        return w > p.w;
    }
};
void Dijkstra()
{
    priority_queue<node> q;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    q.push(node(1,0));
    while(!q.empty())
    {
        node cur = q.top();
        q.pop();
        int u = cur.v;
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i = 0;i < G[u].size();i++)
        {
            int v = G[u][i];
            if(!vis[v] && dis[v] > dis[u]+ i)
            {
                dis[v] = dis[u] + i;
                q.push(node(v,dis[v]));
            }
        }
    }
}
int main()
{
    int t;
    char c;
    cin >> t;
    while(t--)
    {
        for(int i = 0;i < N;i++)
            G[i].clear();
        scanf("%d",&n);
        getchar();
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                cin >> c;
                if(c == 'Y')
                    G[i].push_back(j);
            }

        Dijkstra();
        if(dis[n] == INF)
            printf("-1\n");
        else
            printf("%d\n",dis[n]);
    }
    return 0;
}
