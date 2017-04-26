#include<bits/stdc++.h>
using namespace std;
const int N = 30005;
const int INF = 0x3f3f3f3f;

struct node
{
    int v,w;
    node(int v,int w):v(v),w(w){}
    node(){}
    bool operator<(const node&p)const
    {
        return w > p.w;
    }
};

vector< vector<node> > G;
priority_queue<node> pq;
int vis[N];

int main()
{
    int n,m;
    cin>>n>>m;
    G.clear();
    G.resize(n+1);
    int x,y,w;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        G[x].push_back(node(y,w));
    }

    //dijkstra
    pq.push(node(1,0));//第一个人
    node p,q;
    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();
        if(vis[p.v])
            continue;
        vis[p.v] = 1;
        if(p.v == n)
            break;
        int num = G[p.v].size();
        for(int i = 0;i < num;i++)
        {
            q.v = G[p.v][i].v;
            if(vis[q.v])
                continue;
            q.w = p.w + G[p.v][i].w;
            pq.push(q);

        }
    }
    printf("%d\n",p.w);
    return 0;
}
