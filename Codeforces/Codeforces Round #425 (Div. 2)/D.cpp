#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;
int father[N][20];
vector<int> G[N];
int deep[N];
int n,q;

void dfs(int u,int fa,int d)
{
    deep[u] = d;
    for(auto v : G[u])
    {
        if(v == fa)continue;
        father[v][0] = u;
        dfs(v,u,d+1);
    }
}
void Init()
{
    for(int i = 1;i <= 19;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            father[j][i] = father[father[j][i-1]][i-1];
        }
    }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])
        swap(a,b);
    for(int i = 19;i >= 0;i--)
        if(deep[father[a][i]] >= deep[b])
            a = father[a][i];
    if(a==b)
        return a;
    for(int i = 19;i >= 0;i--)
    {
        if(father[a][i] != father[b][i])
        {
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}
int dis(int u,int v)
{
    return deep[u] + deep[v] - 2*deep[LCA(u,v)];
}
int main()
{
    scanf("%d%d",&n,&q);
    int x;
    for(int i = 2;i <= n;i++)
    {
        scanf("%d",&x);
        G[i].push_back(x);
        G[x].push_back(i);
    }
    dfs(1,0,0);
    Init();
    int a,b,c;
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int l1 = dis(a,b);
        int l2 = dis(a,c);
        int l3 = dis(b,c);
        int len1 = (l1+l2-l3)/2+1;
        int len2 = (l1+l3-l2)/2+1;
        int len3 = (l2+l3-l1)/2+1;
        int ans = max(len1,max(len2,len3));
        printf("%d\n",ans);
    }
    return 0;
}
