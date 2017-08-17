#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;
struct Edge
{
	int from,to,next,w;
}edge[400005],E[100005];
int n,m,st,ed;
int cnt,head[maxn],pre[2][maxn];
int dis[2][maxn],level[maxn];
bool inq[maxn];

void addedge(int u,int v,int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	swap(u,v);
	edge[cnt].to = v;
	edge[cnt].w = 0;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void addedge1(int u,int v,int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = pre[0][u];
	pre[0][u] = cnt++;
}

void addedge2(int u,int v,int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = pre[1][u];
	pre[1][u] = cnt++;
}

void build()
{
	int u,v,w;
	memset(head,-1,sizeof(head));
	for(int i = 1; i <= m; i++)
	{
		u = E[i].from, v = E[i].to, w = E[i].w;
		if(dis[0][u] + w + dis[1][v] == dis[0][ed])
			addedge(u,v,1);
	}
}

void spfa(int src,int des,int idx)
{
	queue<int> q;
	memset(dis[idx],inf,sizeof(dis[idx]));
	memset(inq,false,sizeof(inq));
	dis[idx][src] = 0;
	q.push(src);
	inq[src] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = pre[idx][u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if(dis[idx][v] > dis[idx][u] + edge[i].w)
			{
				dis[idx][v] = dis[idx][u] + edge[i].w;
				if(inq[v] == false)
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int BFS(int src,int des){
    queue<int> q;
    memset(level,0,sizeof(level));
    level[src]=1;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==des) return 1;
        for(int k = head[u];k!=-1;k=edge[k].next){
            int v = edge[k].to,w=edge[k].w;
            if(level[v]==0 && w!=0){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int dfs(int u,int des,int increaseRoad){
    if(u==des) return increaseRoad;
    int ret=0;
    for(int k=head[u];k!=-1;k=edge[k].next){
        int v = edge[k].to,w=edge[k].w;
        if(level[v]==level[u]+1&&w!=0){
            int MIN = min(increaseRoad-ret,w);
            w = dfs(v,des,MIN);
			if(w > 0)
			{
				edge[k].w -=w;
				edge[k^1].w+=w;
				ret+=w;
				if(ret==increaseRoad) return ret;
			}
			else level[v] = -1;
        }
    }
    return ret;
}
int Dinic(int src,int des){
    int ans = 0;
    while(BFS(src,des)!=-1) ans+=dfs(src,des,inf);
    return ans;
}

int main()
{
	int t,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		cnt = 0;
		memset(pre,-1,sizeof(pre));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			E[i].from = u,E[i].to = v,E[i].w = w;
			addedge1(u,v,w);
			addedge2(v,u,w);
		}
		scanf("%d%d",&st,&ed);
		spfa(st,ed,0);
		spfa(ed,st,1);
		build();
		int maxflow = Dinic(st,ed);
		printf("%d\n",maxflow);
	}
	return 0;
}
