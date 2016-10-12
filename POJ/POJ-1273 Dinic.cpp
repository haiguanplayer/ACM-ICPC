/*
1.邻接表

*/

//HDU 4280
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





/*
2.邻接矩阵

*/

//Poj 1273 Drainage Ditches 的 Dinic算法
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>
using namespace std;
#define INFINITE 999999999
int G[300][300];
bool Visited[300];
int Layer[300]; int n,m; //1 是源点， m是汇点
//BFS分层
bool CountLayer() {
    int layer = 0;
    deque<int>q;
    memset(Layer,0xff,sizeof(Layer)); //都初始化成-1
    Layer[1] = 0;
    q.push_back(1);
    while( ! q.empty()) {
        int v = q.front();
        q.pop_front();
        for( int j = 1; j <= m; j ++ ) {
            if( G[v][j] > 0 && Layer[j] == -1 ) {
            //Layer[j] == -1 说明j还没有访问过
                Layer[j] = Layer[v] + 1;
                if( j == m ) //分层到汇点即可
                    return true;
                else
                    q.push_back(j);
            }
        }
    }
    return false;
}
int Dinic()
{
    int i, s;
    int nMaxFlow = 0;
    deque<int> q; //DFS用的栈
    while( CountLayer() ) { //只要能分层
        q.push_back(1); //源点入栈
        memset(Visited,0,sizeof(Visited));
        Visited[1] = 1;
        while( !q.empty()) {
            int nd = q.back();
            if( nd == m ) { // nd是汇点
                //在栈中找容量最小边
                int nMinC = INFINITE;
                int nMinC_vs; //容量最小边的起点
                    for( i = 1;i < q.size(); i ++ ) {
                    int vs = q[i-1];
                    int ve = q[i];
                    if( G[vs][ve] > 0 ) {
                        if( nMinC > G[vs][ve] ) {
                        nMinC = G[vs][ve];
                        nMinC_vs = vs;
                        }
                    }
                }
                //增广，改图
                nMaxFlow += nMinC;
                for( i = 1;i < q.size(); i ++ ) {
                    int vs = q[i-1];
                    int ve = q[i];
                    G[vs][ve] -= nMinC; //修改边容量
                    G[ve][vs] += nMinC; //添加反向边
                }
                //退栈到 nMinC_vs成为栈顶，以便继续dfs
                while( !q.empty() && q.back() != nMinC_vs ) {
                    Visited[q.back()] = 0; //没有这个应该也对
                    q.pop_back();
                }
            }
            else { //nd不是汇点
                for( i = 1;i <= m; i ++ ) {
                     if( G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 && ! Visited[i]) {
                        //只往下一层的没有走过的节点走
                        Visited[i] = 1;
                        q.push_back(i);
                        break;
                    }
                }
                if( i > m) //找不到下一个点
                    q.pop_back(); //回溯
            }
        }
    }
    return nMaxFlow;
}
int main()
{
    while (cin >> n >> m ) {
        int i,j,k;
        int s,e,c;
        memset( G,0,sizeof(G));
        for( i = 0;i < n;i ++ ) {
            cin >> s >> e >> c;
            G[s][e] += c; //两点之间可能有多条边
        }
        cout << Dinic() << endl;
    }
    return 0;
}
