#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int a[N],vis[N],minn;

void dfs(int x,int d)
{
	if(d >= minn)
		return;
	if(x == 10)
	{
		minn = d;
		return;
	}

	for(int i = 1;i < 10;i++)
	{
		if(vis[i])
			continue;
		vis[i] = 1;
		for(int j = i+1;j <= 10;j++)
			if(!vis[j])
			{
				dfs(x+1,d+abs(a[i]-a[j]));
				break;
			}
		vis[i] = 0;
	}
	return;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		for(int i = 0;i < 10;i++)
		{
			scanf("%d",&x);
			a[x] = i;
		}
		memset(vis,0,sizeof(vis));
		minn = 100;
		dfs(1,0);
		printf("%d\n",minn);
	}
	return 0;
}
