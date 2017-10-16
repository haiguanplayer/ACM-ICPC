#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m,q;
int ma[N][N],p[N][N];
int vis[N*N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct edge{
    int x,y;
    edge(int x=0,int y=0):x(x),y(y){}
}e[N*N*3];
int f[N*N],ans[N*10];
/*
#define isInside(x, y)  1 <= x && x <= n && 1 <= y && y <= m
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if(isInside(fx, fy) && vis[fx][fy] == 0 && ma[fx][fy] != 1)
            dfs(fx, fy);
    }
}
int cal()
{
    memset(vis,0,sizeof(vis));
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(vis[i][j] == 0 && ma[i][j] == 0)
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    return ans;
}*/
int tmp = 0;
int getf(int x)
{
    return x == f[x] ? x : f[x] = getf(f[x]);
}
void merge(int x,int y)
{
    if(x && y && vis[x] && vis[y])
    {
        int fx = getf(x);
        int fy = getf(y);
        if(fx != fy)
            --tmp,f[fy] = f[fx];
        return;
    }
}
void add(int x,int y)
{
    vis[p[x][y]] = 1;
    tmp++;
    merge(p[x][y],p[x-1][y]);
    merge(p[x][y],p[x+1][y]);
    merge(p[x][y],p[x][y-1]);
    merge(p[x][y],p[x][y+1]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    int x,y,u,v;
    int cnt = 0;
    for(int i = 1;i <= q;i++)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v);
        if(x == u)
        {
            for(int i = min(y,v);i <= max(y,v);i++)
            {
                if(ma[x][i] == 0)
                    e[++cnt] = edge(x,i);
                ma[x][i] = 1;
            }
        }
        else if(y == v)
        {
            for(int i = min(x,u);i <= max(x,u);i++)
            {
                if(ma[i][y] == 0)
                    e[++cnt] = edge(i,y);
                ma[i][y] = 1;
            }
        }

        e[++cnt] = edge(0,i);
    }

    int num = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            p[i][j] = ++num;
            f[num] = num;
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(ma[i][j] == 0) add(i,j);
        //printf("%d\n",cal());
    for(int i = cnt;i >= 1;i--)
    {
        if(e[i].x == 0)
            ans[e[i].y] = tmp;
        else
            add(e[i].x,e[i].y);
    }
    for(int i = 1;i <= q;i++)
        printf("%d\n",ans[i]);
    return 0;
}