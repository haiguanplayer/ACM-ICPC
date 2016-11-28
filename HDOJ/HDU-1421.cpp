/*
题意：有n件物品，要你从里面选p（p*2<n）对物品出来，使得每一对差的平法的和最小。
有n件物品，要你从里面选p（p*2<n）对物品出来，使得每一对差的平法的和最小。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[2005][2005],w[2005];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&w[i]);
        sort(w+1,w+1+n);
        memset(dp,INF,sizeof dp);
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        for(int i=1;i<=k;i++)
        {
            for(int j=2;j<=n;j++)
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-2] + (w[j]-w[j-1])*(w[j]-w[j-1]));
        }
        cout<<dp[k][n]<<endl;
    }
}
