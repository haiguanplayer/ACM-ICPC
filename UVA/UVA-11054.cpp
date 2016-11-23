#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,x;
    while(~scanf("%d",&n) && n)
    {
        long long ans = 0,last = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&x);
            ans += abs(last);
            last += x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
