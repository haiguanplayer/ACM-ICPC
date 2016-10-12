/*
给你一个n点m边的图，让你从1走到n，找到一条经过尽量多点的路径，
且路径边权和小于等于T,然后输出路径。

*/

1.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 5005;
int n,m,t;
int cnt,head[N],p[N][N],dp[N][N];
struct node
{
    int from,to,next,w;
}edge[N];

void addedge(int u,int v,int w)
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void print(int pos)
{
    printf("%d\n",pos);
    int id = n;
    vector<int> ans;
    ans.push_back(id);
    for(int i = pos;i > 1;i--)
    {
        ans.push_back(p[i][id]);
        id = p[i][id];
    }
    for(int i = ans.size()-1;i >= 0;i--)
        printf("%d ",ans[i]);
    printf("\n");
}
int main()
{
    memset(head,-1,sizeof(head));

    cin >> n >> m >> t;
    int x,y,z;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }

    for(int i = 0;i < n+1;i++)
        for(int j = 0;j < n+1;j++)
            dp[i][j] = t+1;
    dp[1][1] = 0;
    int u,v,w,pos = 1;
    for(int i = 2;i <= n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            u = edge[j].from, v = edge[j].to, w = edge[j].w;
            if(dp[i - 1][u] + w < dp[i][v])
            {
                dp[i][v] = dp[i - 1][u] + w;
                p[i][v] = u;
            }
        }
        if(dp[i][n] <= t)
            pos = i;
    }
    print(pos);
    return 0;
}




2.
//by  Farhod_Farmon
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

int d[N][N], p[N][N];
int n, m, T;
vector < pair < int, int > > v[N];
vector < int > order;
bool used[N];

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    for(int i = 0; i < v[x].size(); i++)
        dfs(v[x][i].fi);
    //printf("%d\n",x);
    order.pb(x);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> T;
    for(int i = 1; i <= m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        v[x].pb({y, l});
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = 1e9 + 1;
    d[1][1] = 0;
    dfs(1);
    reverse(order.begin(), order.end());
    for(int i = 0; i < order.size(); i++)
    {
        int x = order[i];
        for(int j = 1; j <= n; j++)
        {
            if(d[x][j] == 1e9 + 1)
                continue;
            for(int h = 0; h < v[x].size(); h++)
            {
                int y = v[x][h].fi,
                    l = v[x][h].se;
                if(d[x][j] + l < d[y][j + 1])
                {
                    d[y][j + 1] = d[x][j] + l;
                    p[y][j + 1] = x;
                }
            }
        }
    }
    int h;
    for(int i = n; i >= 1; i--)
    {
        if(d[n][i] <= T)
        {
            h = i;
            break;
        }
    }
    vector < int > ans;
    for(int i = h; i >= 1; i--)
    {
        ans.pb(n);
        n = p[n][i];
    }
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
