#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 50005*2;
const int N = 1005;
int t,n,m,k;

struct edge
{
    int u,v,w;
}e[M];

int d[N],p[N],inq[N],head[N],Next[M],ee[M];

inline void add_edge(int u,int v,int w)
{
    e[k].u=u;
    e[k].v=v;
    e[k].w=w;
    Next[k]=head[u];
    head[u]=k++;
}
void spfa(bool flag)
{
    int i;
    for(i=0;i<=n;i++)
        d[i]=INF;
    d[1]=0;
    memset(inq,0,sizeof(inq));
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inq[x]=0;
        int y;
        for(y=head[x];y!=-1;y=Next[y])
        {
            int v=e[y].v;
            if(d[v]>d[x]+e[y].w)
            {
                d[v]=d[x]+e[y].w;
                if(!inq[v])
                {
                    inq[v]=1;
                    q.push(v);
                }
                if(flag)
                {
                    p[v]=x;
                    ee[v]=y;
                }
            }
        }
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);

        memset(p,0,sizeof(p));
        memset(head,-1,sizeof(head));
        memset(Next,-1,sizeof(Next));
        memset(ee,0,sizeof(ee));
        int u,v,w;
        k = 0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        spfa(1);
        int maxn=d[n];
        if(d[n]==INF)
        {
            printf("-1\n");
            continue;
        }
        for(int i=n;i!=1;i=p[i])
        {
            int tt=e[ee[i]].w;
            e[ee[i]].w=INF;
            spfa(0);
            if(d[n]>maxn)
                maxn=d[n];
            e[ee[i]].w=tt;
        }
        if(maxn>=INF)
            printf("-1\n");
        else
            printf("%d\n",maxn);
    }
    return 0;
}
