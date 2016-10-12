/*
UVA-247
Kruskal
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 30;
map<string,int> G;
string S[N];
int num,n,m;
int d[N][N],vis[N];

int ID(string s)
{
    if(G.count(s))
        return G[s];
    G[s] =  ++num;
    S[num] = s;
    return num;
}

int main()
{
    int ca = 0;
    while(~scanf("%d%d",&n,&m) && (n || m))
    {
        G.clear();
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        num = 0;

        string a,b;
        int u,v;
        for(int i = 1;i<= m;i++)
        {
            cin >> a >> b;
            int u = ID(a);
            int v = ID(b);
            d[u][v] = 1;
        }
        if(ca)
            printf("\n");
        printf("Calling circles for data set %d:\n",++ca);

        //Floyd
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                d[i][j] = d[i][j] || (d[i][k] && d[k][j]);

        for(int i = 1;i <= n;i++)
        {
            if(vis[i])  continue;
            cout<<S[i];
            for(int j = i+1;j <= n;j++)
            {
                if(!vis[j] && d[i][j] && d[j][i])
                {
                    vis[j] = 1;
                    cout<<", "<<S[j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
