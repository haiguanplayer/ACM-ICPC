#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

#define V 10100
#define E 1000100
#define inf 99999999
int vis[V];
int dist[V];
int pre[V];

struct Edge{
    int u,v,c,cost,next;
}edge[E];
int head[V],cnt;

void Init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int c,int cost)
{
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].cost=cost;
    edge[cnt].c=c;edge[cnt].next=head[u];head[u]=cnt++;

    edge[cnt].u=v;edge[cnt].v=u;edge[cnt].cost=-cost;
    edge[cnt].c=0;edge[cnt].next=head[v];head[v]=cnt++;
}

bool spfa(int begin,int end){
    int u,v;
    queue<int> q;
    for(int i=0;i<=end+2;i++){
        pre[i]=-1;
        vis[i]=0;
        dist[i]=inf;
    }
    vis[begin]=1;
    dist[begin]=0;
    q.push(begin);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            if(edge[i].c>0){
                v=edge[i].v;
                if(dist[v]>dist[u]+edge[i].cost){
                    dist[v]=dist[u]+edge[i].cost;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return dist[end]!=inf;
}

int MinCostMaxflow(int begin,int end){
    int ans=0,flow;
    int flow_sum=0;
    while(spfa(begin,end)){
        flow=inf;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u])
            if(edge[i].c<flow)
                flow=edge[i].c;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u]){
            edge[i].c-=flow;
            edge[i^1].c+=flow;
        }
        ans+=dist[end];
        flow_sum += flow;
    }
    //cout << flow_sum << endl;
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Init();
    add_edge(0,1,2,0);
    add_edge(n,n+1,2,0);
    int a,b,c;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,1,c);
        add_edge(b,a,1,c);
    }
    printf("%d\n", MinCostMaxflow(0, n+1));
}
