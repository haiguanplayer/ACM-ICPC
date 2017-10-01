#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
typedef long long ll;
int n,m;

struct node
{
    int v,w;
    node(int v=0,int w=0):v(v),w(w){}
};
vector<int> G[N];
int vis[N],d[N][N];
void bfs()
{
    for(int s = 1;s <= n;s++)
    {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty())
        {
            int u = q.front();q.pop();
            for(int i = 0;i < G[u].size();i++)
            {
                int v = G[u][i];
                if(!vis[v])
                {
                    vis[v] = 1;
                    d[s][v] = d[s][u]+1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s1,t1,l1,s2,t2,l2;
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    bfs();
    if(d[s1][t1] > l1 || d[s2][t2] > l2)
        return 0 * printf("-1\n");
    int minn = d[s1][t1]+d[s2][t2];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(d[s1][i]+d[i][j]+d[j][t1] <= l1 && d[s2][i]+d[i][j]+d[j][t2] <= l2)
                minn = min(minn, d[s1][i]+d[i][j]+d[j][t1]+d[s2][i]+d[j][t2]);
            if(d[s1][i]+d[i][j]+d[j][t1] <= l1 && d[t2][i]+d[i][j]+d[j][s2] <= l2)
                minn = min(minn, d[s1][i]+d[i][j]+d[j][t1]+d[t2][i]+d[j][s2]);
        }
    }
    printf("%d\n",m-minn);
}
