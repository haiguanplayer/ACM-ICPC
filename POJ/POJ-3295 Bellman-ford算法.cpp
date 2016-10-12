/*
要求判断有向连通图(图中有重边）中是否存在负权环
110MS  O(n*(m+w))
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,w;
const int INF = 0x3f3f3f3f;
struct node
{
    int s,e,w;
    node(int ss,int ee,int ww):s(ss),e(ee),w(ww){}
    node(){}
};
vector<node> edge;
int dis[1005];
bool Bellman_ford(int t)
{
    for(int i = 1;i <= n;i++)
        dis[i] = INF;
    dis[t] = 0;
    for(int i = 1;i < n;i++)
        for(int j = 0;j < edge.size();j++)
        {
            int s = edge[j].s;
            int e = edge[j].e;
            if(dis[s] + edge[j].w < dis[e])
                dis[e] = dis[s] + edge[j].w;
        }

    for(int i = 0;i <edge.size();i++)
    {
        int s = edge[i].s;
        int e = edge[i].e;
        if(dis[s] + edge[i].w < dis[e])
            return true;
    }
    return false;
}
int main()
{
    int f;
    cin >> f;
    while(f--)
    {
        edge.clear();
        cin >> n >> m >> w;
        int s,e,t;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&s,&e,&t);
            edge.push_back(node(s,e,t));
            edge.push_back(node(e,s,t));
        }
        for(int i = 0;i < w;i++)
        {
            scanf("%d%d%d",&s,&e,&t);
            edge.push_back(node(s,e,-t));
        }
        if(Bellman_ford(1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
