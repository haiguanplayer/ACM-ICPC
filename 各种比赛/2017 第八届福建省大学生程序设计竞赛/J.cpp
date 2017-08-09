
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int  d[105][105];
bool vis[105][105],v[105][105];

void floyd(int n)
{
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(d[i][j] >= d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    vis[i][j] = true;
                }
}
int main()
{
    int t,n,m;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        int ans = 0;
        memset(v,false,sizeof(v));
        memset(vis,false,sizeof(vis));
        memset(d,0x3f,sizeof(d));
        scanf("%d%d",&n,&m);
        int x,y,s;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&s);
            v[x][y] = v[y][x] = true;
            if(d[x][y] < INF)
                ans++;
            d[x][y] = d[y][x] = min(d[x][y],s);
        }
        floyd(n);
        printf("Case %d: ",ca);
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                if(v[i][j] && vis[i][j])
                    ans++;

        printf("%d\n",ans);
    }
    return 0;
}
