//1.Sap 模板
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int MAXN = 100010;//点数的最大值
const int MAXM = 400010;//边数的最大值
const int INF = 0x3f3f3f3f;

struct Node
{
    int from,to,next;
    int cap;
}edge[MAXM];
int tol;
int head[MAXN];
int dep[MAXN];
int gap[MAXN];//gap[x]=y :说明残留网络中dep[i]==x的个数为y

int n;//n是总的点的个数，包括源点和汇点

void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}

void add_edge(int u,int v,int w)
{
    edge[tol].from = u;
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].from = v;
    edge[tol].to = u;
    edge[tol].cap = w;
    edge[tol].next = head[v];
    head[v] = tol++;
}
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0] = 1;
    int que[MAXN];
    int front,rear;
    front = rear = 0;
    dep[end] = 0;
    que[rear++] = end;
    while(front != rear)
    {
        int u = que[front++];
        if(front == MAXN)front = 0;
        for(int i = head[u];i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if(dep[v] != -1)continue;
            que[rear++] = v;
            if(rear == MAXN)rear = 0;
            dep[v] = dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int SAP(int start,int end)
{
    int res = 0;
    BFS(start,end);
    int cur[MAXN];
    int S[MAXN];
    int top = 0;
    memcpy(cur,head,sizeof(head));
    int u = start;
    int i;
    while(dep[start]<n)
    {
        if(u == end)
        {
            int temp = INF;
            int inser;
            for(i = 0;i < top;i++)
               if(temp > edge[S[i]].cap)
               {
                   temp = edge[S[i]].cap;
                   inser = i;
               }
            for(i = 0;i < top;i++)
            {
                edge[S[i]].cap -= temp;
                edge[S[i]^1].cap += temp;
            }
            res += temp;
            top =inser;
            u = edge[S[top]].from;
        }
        if(u != end && gap[dep[u]-1] == 0)//出现断层，无增广路
          break;
        for(i = cur[u];i != -1;i = edge[i].next)
           if(edge[i].cap != 0 && dep[u] == dep[edge[i].to]+1)
             break;
        if(i != -1)
        {
            cur[u] = i;
            S[top++] = i;
            u = edge[i].to;
        }
        else
        {
            int min = n;
            for(i = head[u];i != -1;i = edge[i].next)
            {
                if(edge[i].cap == 0)continue;
                if(min > dep[edge[i].to])
                {
                    min = dep[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dep[u]];
            dep[u] = min+1;
            ++gap[dep[u]];
            if(u != start)u = edge[S[--top]].from;
        }
    }
    return res;
}
int main()
{
    int cn;
    int m;
    cin>>cn;
    int t1,t2,t3;
    while(cn--)
    {
        int maxn = -INF;
        int minn = INF;
        int maxi;
        int mini;
        cin>>n>>m;
        init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&t1,&t2);
            if(maxn < t1)
            {
                maxn = t1;
                maxi = i;
            }
            if(minn > t1)
            {
                minn = t1;
                mini = i;
            }
        }
        while(m--)
        {
            scanf("%d %d %d", &t1, &t2, &t3);
            add_edge(t1, t2, t3);
        }
        printf("%d\n", SAP(mini, maxi));
    }
 return 0;
}




#include<iostream>//Dinic模拟队列，STL会超时
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int N = 100010;
const int INF =  0x3f3f3f3f;

struct edge
{
    int next,v,c;
}e[N<<1];
int n,m;
int tot,head[N],d[N];
int q[N];

int min(int a,int b)
{
   return a < b?a:b;
}

void add(int u,int v,int c)
{
    e[tot].v = v;  e[tot].c = c;
    e[tot].next = head[u];  head[u] = tot++;

    e[tot].v = u;  e[tot].c = c;
    e[tot].next = head[v];  head[v] = tot++;
}

int bfs(int s,int t)
{
   memset(d,-1,sizeof(d));
   int f = 0,r = 0;
   q[r++] = s;
   d[s] = 0;

   while (f < r)
   {
         int u=q[f++];
         if (u==t) return 1;
         for (int i = head[u];i != -1;i = e[i].next)
         {
            int v=e[i].v;
            if (d[v]==-1&&e[i].c>0)
            {
                d[v]=d[u]+1;
                q[r++]=v;
            }
         }
   }
   return 0;
}

int dfs(int s,int t,int b)
{
    int r = 0;
   if (s == t) return b;
   for (int i = head[s];i != -1 && r < b;i = e[i].next)
   {
      int v=e[i].v;
      if (e[i].c > 0 && d[v] == d[s]+1)
      {
        int x=min(e[i].c,b-r);
        x=dfs(v,t,x);
        r+=x;
        e[i].c-=x;
        e[i^1].c+=x;
      }
   }
   if (!r) d[s]-=2;
   return r;
}

int Dinic(int s,int t)
{
   int ans=0,tmp;
   while (bfs(s,t))
   {
      while (tmp=dfs(s,t,INF)) ans+=tmp;
   }
   return ans;
}

int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
       memset(head,-1,sizeof(head));
       tot=0;
       int s,t;
       scanf("%d%d",&n,&m);
       int xx = -INF,yy = INF;
       for (int i = 1;i <= n;i++)
       {
          int x,y;
          scanf("%d%d",&x,&y);
          if (xx < x) xx = x,t = i;
          if (yy > x) yy = x,s = i;
       }

       while (m--)
       {
          int x,y,c;
          scanf("%d%d%d",&x,&y,&c);
          add(x,y,c);
       }

       printf("%d\n",Dinic(s,t));
    }
    return 0;
}
