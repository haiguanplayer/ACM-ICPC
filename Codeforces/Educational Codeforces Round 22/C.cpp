#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
vector<int> G[N];
int n,d1[N],d2[N],vis[N];
struct node
{
    int u,v,w;
    node(int u = 0,int v = 0,int w = 0):u(u),v(v),w(w){}
};
void bfs(int *d,int x)
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    q.push(node(x,0,0));
    vis[x] = 1;
    node cur;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        d[cur.u] = cur.w;
        for(int i = 0;i < G[cur.u].size();i++)
        {
            if(G[cur.u][i] != cur.v && !vis[G[cur.u][i]])
            {
                vis[G[cur.u][i]] = 1;
                q.push(node(G[cur.u][i],cur.u,cur.w+1));
            }
        }
    }
}
int main()
{
    int x,u,v;
    cin >> n >> x;
    for(int i = 0;i < n-1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bfs(d1,1);
    bfs(d2,x);
    int maxn = 0;
    for(int i = 1;i <= n;i++)
        if(d1[i] > d2[i])
            maxn = max(maxn,d1[i]);
    printf("%d\n",maxn*2);
    return 0;
}
