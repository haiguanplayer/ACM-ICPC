#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 305;

int n,C[N][N],dis[N],vis[N];
int spfa(int s,int t,int &res)
{
	queue<int> q;
	for(int i = 0;i <= n;i++)
		dis[i] = INF;
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s != u && i == s)
				res = min(res,C[u][i] + dis[u]);
			if(dis[i] > dis[u] + C[u][i])
			{
				dis[i] = dis[u] + C[u][i];
				if(!vis[i])
					q.push(i);
				vis[i] = 1;
			}
		}
	}
	return dis[t];
}

int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				scanf("%d",&C[i][j]);
		int res1 = INF;
		int ans = spfa(1,n,res1);
		int res2 = INF;
		spfa(n,1,res2);
		printf("%d\n",min(ans,res1+res2));
	}
}
