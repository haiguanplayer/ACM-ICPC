#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100000;
typedef long long ll;
ll a[N+5],dp[N+5];
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&x);//a[i
        a[x] += x;
    }
    dp[1] = a[1];
    for(int i = 2;i <= N+4;i++)
        dp[i] = max(dp[i-1],dp[i-2]+a[i]);
    printf("%lld\n",dp[N]);
    return 0;
}
//1 3
//1 3 6
//
