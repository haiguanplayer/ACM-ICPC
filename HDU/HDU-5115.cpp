//枚举左右边界
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 205;
int a[N],b[N],dp[N][N];
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)
            scanf("%d",&b[i]);
        b[0] = b[n+1] = 0;
        for(int i = 0;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(i > j) dp[i][j] = 0;
                else dp[i][j] = INF;
        for(int i = n;i >= 1;i--)
            for(int j = i;j <= n;j++)
                for(int k = i;k <= j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k-1]+ a[k]+b[i-1]+b[j+1] + dp[k+1][j]);
        printf("Case #%d: %d\n",ca,dp[1][n]);
    }
    return 0;
}
//枚举长度
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 205;
int a[N],b[N],dp[N][N];
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)
            scanf("%d",&b[i]);
        b[0] = b[n+1] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(i > j) dp[i][j] = 0;
                else dp[i][j] = INF;
        for(int len = 0;len <= n;len++)
            for(int i = 1,j;i + len <= n;i++)
            {
                j = i+len;
                for(int k = i;k <= j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k-1] + a[k]+b[i-1]+b[j+1] + dp[k+1][j]);
            }
        printf("Case #%d: %d\n",ca,dp[1][n]);
    }
    return 0;
}
