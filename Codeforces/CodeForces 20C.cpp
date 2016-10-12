#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int N = 100005;
typedef long long ll;

struct node
{
    int v;
    ll len;
    node(int vv = 0,int le = 0):v(vv),len(le){}
    bool operator < (const node & a)const
    {
        return len < a.len;
    }
};

bool vis[N];
ll minD[N];
int n,m,ba[N];
vector<node> G[N];
ll Dijkstra(int s,int t)
{
    minD[s] = 0;
    priority_queue<node> Q;
    for(int i = 0;i < G[s].size();i++)
    {
        int vex = G[s][i].v;
        Q.push(G[s][i]);
        minD[vex] = min(G[s][i].len,minD[vex]);
        ba[vex] = s;
        vis[vex] = 1;
    }

    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        vis[now.v] = 0;
        for(int i = 0;i < G[now.v].size();i++)
        {
            int vex = G[now.v][i].v;
            ll len = G[now.v][i].len;
            if(len + minD[now.v] < minD[vex])
            {
                 minD[vex] = len + minD[now.v];
                 ba[vex] = now.v;
                 if(!vis[vex])
                 {
                     vis[vex] = 1;
                     Q.push(G[now.v][i]);
                 }
            }
        }
    }
    return minD[t];
}

int main()
{
    while(~scanf("%d %d",&n, &m))
    {
        for(int i = 1;i <= n;i++)
            minD[i] = 1ll<<60;
        int a,b,len;
        for(int i = 0;i < m;i++)
        {
            scanf("%d %d %d",&a,&b,&len);
            G[a].push_back(node(b,len));
            G[b].push_back(node(a,len));
        }

        ll ans = Dijkstra(1,n);
        if(ans == 1ll<<60)
            printf("-1\n");
        else
        {
            stack<int>S;
            for(int i = n; i != 1; i = ba[i])
                S.push(i);

            S.push(1);
            while(!S.empty())
            {
                printf("%d ", S.top());
                S.pop();
            }
            printf("\n");
        }
    }
}

