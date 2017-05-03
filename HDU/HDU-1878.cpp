#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 1005;
vector<int> G[N];
int vis[N];
int n,m;
void Init()
{
    for(int i = 1;i <= n;i++)
        G[i].clear(),vis[i] = 0;
}

void dfs(int x)
{
    if(vis[x])
        return;
    vis[x] = 1;
    for(int i = 0;i < G[x].size();i++)
        dfs(G[x][i]);
}
int main()
{
    while(~scanf("%d",&n) && n)
    {
        Init();
        scanf("%d",&m);
        int x,y,degree[N]={0};
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }
        bool flag = true;
        for(int i = 1;i <= n;i++)
        {
            if(degree[i] % 2)//ÓÐÆæ¶È¶¥µã
            {
                flag = false;
                break;
            }
        }

        dfs(1);

        for(int i = 1;i <= n;i++)
        {
            if(!vis[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
            printf("1\n");
        else
            printf("0\n");
    }
}
