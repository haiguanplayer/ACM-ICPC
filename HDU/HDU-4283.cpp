#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 105;
int d[N],dp[N][N],sum[N];
int main()
{
	int T,n;
	cin >> T;
	for(int ca = 1;ca <= T;ca++)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			scanf("%d",&d[i]),sum[i] = sum[i-1] + d[i];
        memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;i++)
			for(int j = i+1;j <= n;j++)
				dp[i][j] = INF;

		for(int l = 0;l <= n-1;l++)
		{
			for(int i = 1;i <= n-l;i++)
			{
				int j = i+l;
				for(int k = i;k <= j;k++)
					dp[i][j] = min(dp[i][j],dp[i+1][k]+dp[k+1][j]+d[i]*(k-i)+(sum[j]-sum[k])*(k-i+1));
			}
		}
		printf("Case #%d: %d\n",ca,dp[1][n]);
	}
	return 0;
}

