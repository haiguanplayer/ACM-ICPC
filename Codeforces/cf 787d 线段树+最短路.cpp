#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3fLL;
const int N = 5*1e5+5;
bool vis[N];
int id[N][2];
vector<int> ans;
ll d[N];
int idx;

struct Edge{
    int to,weight;
    Edge(int _to = 0,int _weight = 0) : to(_to),weight(_weight){}
};
vector<vector<Edge> > G(N);

void add_edge(int from,int to,int weight){
    G[from].push_back(Edge(to,weight));
}

void build(int l,int r,int rt,int wh){  //wh0为从上到下的线段树，wh1为从下到上的线段树
    id[rt][wh] = ++idx;
    if(l == r){
        if(wh == 0){
            add_edge(id[rt][wh],l,0);
        } else {
            add_edge(l,id[rt][wh],0);
        }
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt << 1,wh);
    build(mid + 1,r,rt << 1 | 1,wh);
    if(wh == 0){
        add_edge(id[rt][wh],id[rt << 1][wh],0);
        add_edge(id[rt][wh],id[rt << 1 | 1][wh],0);
    } else {
        add_edge(id[rt << 1][wh],id[rt][wh],0);
        add_edge(id[rt << 1 | 1][wh],id[rt][wh],0);
    }
}

void query(int l,int r,int L,int R,int rt,int wh){
    if(L <= l && r <= R){
        ans.push_back(id[rt][wh]);
        return;
    }
    int m = l + r >> 1;
    if(m >= L){
        query(l,m,L,R,rt << 1,wh);
    }
    if(m < R){
        query(m + 1,r,L,R,rt << 1 | 1,wh);
    }
}
priority_queue< pair<ll,int> > Q;
void Dijkstra(int s,int n){
    for(int i = 1;i <= n;i++){
        vis[i] = false;
        d[i] = INF;
    }
    Q.push({-0,s});
    d[s] = 0;
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = true;
        for(int i = 0;i < G[u].size();i++){
            Edge e = G[u][i];
            int v = e.to,w = e.weight;
            if(w + d[u] < d[v]){
                d[v] = w + d[u];
                Q.push({-d[v],v});
            }
        }
    }
}

int main()
{
    int n,q,s;
    scanf("%d%d%d",&n,&q,&s);

    for(int i = 1;i <= n*5;i++){
        G[i].clear();
    }
    idx = n;
    build(1,n,1,0);
    build(1,n,1,1);
    while(q--)
    {
        int op,u,v,w,l,r;
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        else if(op == 2)
        {
            scanf("%d%d%d%d",&v,&l,&r,&w);
            ans.clear();
            query(1,n,l,r,1,0);
            for(auto i:ans)
                add_edge(v,i,w);
        }
        else
        {
            scanf("%d%d%d%d",&v,&l,&r,&w);
            ans.clear();
            query(1,n,l,r,1,1);
            for(auto i:ans)
                add_edge(i,v,w);
        }
    }
    Dijkstra(s,n*5);
    for(int i = 1;i <= n;i++)
        printf("%lld ",d[i] == INF ? -1 : d[i]);
    return 0;
}
