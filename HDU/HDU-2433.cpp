#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 105;
int e[N][N],pre[N][N],a[N*30],b[N*30],cnt[N],vis[N],dis[N];
int n,m;

int bfs(int x,bool flag = true)
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    int cnt = 1,sum = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 1;i <= n;i++)
        {
            if(!vis[i] && e[u][i])
            {
                vis[i] = 1;
                if(flag)
                    pre[x][i] = u;
                dis[i] = dis[u]+1;
                sum += dis[i];
                cnt++;
                q.push(i);
            }
        }
    }
    if(cnt == n) return sum;
    else return -1;

}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(e,0,sizeof(e));
        memset(cnt,0,sizeof(cnt));
        memset(pre,0,sizeof(pre));
        for(int i = 1;i <= m;i++)
            scanf("%d%d",&a[i],&b[i]),e[a[i]][b[i]]++, e[b[i]][a[i]]++;
        int sum = 0,flag = 1;
        for(int i = 1;i <= n;i++)
        {
            cnt[i] = bfs(i);
            if(cnt[i] == -1)//不联通
            {
                flag = 0;
                break;
            }
            else
                sum += cnt[i];
        }
        if(!flag)
        {
            while(m--) puts("INF");
            continue;
        }
        for(int i = 1;i <= m;i++)
        {
            if(e[a[i]][b[i]] > 1)//重边，随便删，无影响
                printf("%d\n",sum);
            else
            {
                int u = a[i],v = b[i],ans = 0,j;
                for(j = 1;j <= n;j++)
                {
                    if(pre[j][v] == u || pre[j][u] == v)//要删除的u-v边在第j棵bfs上
                    {
                        e[u][v] = e[v][u] = 0;
                        int tmp = bfs(j,false);
                        if(tmp == -1)//不联通，退出扫描就行了
                        {
                            e[u][v] = e[v][u] = 1;
                            break;
                        }
                        ans += tmp;
                        e[u][v] = e[v][u] = 1;
                    }
                    else
                        ans += cnt[j];
                }
                if(j <= n)
                    puts("INF");
                else
                    printf("%d\n",ans);
            }
        }
    }
    return 0;
}
