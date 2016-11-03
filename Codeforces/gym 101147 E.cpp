#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 100005;
int dis[N];
vector<int> G[N];
struct node
{
    int v,d;
    node(int vv=0,int dd=0):v(vv),d(dd){}
};
void bfs(int n)
{
    queue<node> q;
    //从后向前
    q.push(node(n,0));
    node t,p;
    dis[n] = 0;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        p.d = t.d+1;
        for(int i = 0;i < G[t.v].size();i++)
        {
            p.v = G[t.v][i];
            if(dis[p.v] == -1)//未访问过
            {
                dis[p.v] = p.d;
                q.push(p);
            }
        }
    }
    return;
}
int main()
{
    freopen("jumping.in", "r", stdin);
    int t,n,m;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);

        for(int i = 1;i <= n;i++)
            G[i].clear();
        int x;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&x);
            if(i + x <= n)
                G[i+x].push_back(i);
            if(i - x >= 1)
                G[i-x].push_back(i);
        }
        memset(dis,-1,sizeof(dis));
        bfs(n);

        for(int i = 1;i <= n;i++)
            printf("%d\n",dis[i]);
    }
    return 0;
}
