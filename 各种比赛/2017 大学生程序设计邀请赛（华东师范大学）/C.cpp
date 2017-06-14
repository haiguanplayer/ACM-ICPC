#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n,m,gx,gy,k;
int vis[10][10];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
bool flag = false;
void dfs(int x,int y,int depth)
{
    int tx,ty,cnt = 0;
    for(int i = 0;i < 4;i++)
    {
        tx = x+dr[i];
        ty = y+dc[i];

        cnt += vis[tx][ty];
    }
    if(cnt > 1)
        return;
    if(x == gx && y == gy)
    {
        if(depth >= k)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= m;j++)
                    printf("%c",vis[i][j]?'.':'*');
                printf("\n");
            }
            flag = true;
        }
        return;
    }
    if(flag)
        return;
    for(int i = 0;i < 4;i++)
    {
        tx = x+dr[i];
        ty = y+dc[i];
        if(!vis[tx][ty] && tx >= 1 && tx <= n && ty >= 1 && ty <= m)
        {
            vis[tx][ty] = 1;
            dfs(tx,ty,depth+1);
            vis[tx][ty] = 0;
        }
    }
}
int main()
{
    cin>>n>>m;
    cin>>gx>>gy>>k;
    vis[1][1] = 1;
    dfs(1,1,0);
    return 0;
}
