#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6+5;
int d[N],vis[N];
vector<PII> edges;
vector<int> v,G[N];
int n,m;

void dfs(int x)
{
	for(auto i : G[x])
	{
		if(vis[i])
			continue;
		auto e = edges[i];
		if(e.first != x)
			vis[i] = 2;
		else
			vis[i] = 1;
		dfs(e.first == x ? e.second : e.first);
	}
}
int main()
{
    cin >> n >> m;
    int x,y;
    for(int i = 0;i < m;i++)
    {
    	scanf("%d%d",&x,&y);
    	edges.push_back(make_pair(x,y));
    	G[x].push_back(i);
    	G[y].push_back(i);
    	d[x]++,d[y]++;
    }
    for(int i = 1;i <= n;i++)
    	if(d[i]&1)
    		v.push_back(i);
    int mm = m;
    for(int i = 0;i < v.size();i+=2)
    {
    	x = v[i];;
    	y = v[i+1];
    	edges.push_back(make_pair(x,y));
    	m++;
    	G[x].push_back(m-1);
    	G[y].push_back(m-1);
    }
    for(int i = 1;i <= n;i++)
    	dfs(i);
    cout << n-v.size() << endl;
    for(int i = 0;i < mm;i++)
    	if(vis[i] == 1)
    	    putchar('0');
    	else
    	    putchar('1');
    putchar('\n');
    return 0;
}
