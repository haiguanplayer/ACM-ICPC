#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5+5;
long long a[N];

int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        long long ans = 0,dp = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&x);
            dp += (i - a[x])*x;
            ans += dp;
            a[x] = i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
