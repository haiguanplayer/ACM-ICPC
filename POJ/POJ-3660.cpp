#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100+5;
int a[N],d[N][N];

void floyd(int n)
{
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            d[i][j] = 0;
    int u,v;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&u,&v);
        d[u][v] = 1;
    }
    floyd(n);
    int ans = 0,cnt;
    for(int i = 1;i <= n;i++)
    {
        cnt = 0;
        for(int j = 1;j <= n;j++)
            if(d[i][j] || d[j][i])
                cnt++;
        if(cnt == n-1)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
