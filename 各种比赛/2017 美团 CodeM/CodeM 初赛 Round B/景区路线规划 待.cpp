#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 25;

int G[N][N];
int n,m,q;
struct query
{
    int s,t,l,r;
}p[15];
vector< pair<int,int> > pp;
int main()
{
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i == j)  G[i][j] = 0;
            else        G[i][j] = INF;
	int u,v,w;
	while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(G[u][v] > w)
            G[u][v] = w;
    }
    for(int i = 0;i < q;i++)
        scanf("%d%d%d%d",&p[i].s,&p[i].t,&p[i].l,&p[i].r);
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);

    int maxn = 0;
    int cnt = (1<<q);
    //while(cnt--)
    for(int i = 0;i < cnt;i++)
    {
        pp.clear();
        pp.push_back(make_pair(1,0));
        for(int j = 0;j < q;j++)
        {
            if(i>>j&1)
            {
                pp.push_back(make_pair(p[j].s,p[j].l));
                pp.push_back(make_pair(p[j].t,p[j].r));
            }
        }
        sort(pp.begin(),pp.end());
        bool flag = true;
        for(int j = 1;j < pp.size();j++)
        {
            if(pp[j].second-pp[j-1].second < G[pp[j-1].first][pp[j].second])
            {
                flag = false;
                break
            }
        }
        if(flag)
            maxn = max(maxn,(int)pp.size()/2);
    }
    printf("%d\n",maxn);
    return 0;
}
