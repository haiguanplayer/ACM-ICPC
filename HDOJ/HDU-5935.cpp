#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int N = 100005;
ll a[N],b[N],c[N];

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);

        memset(b,0,sizeof(b));
        for(int i = 1;i <= n;i++)
            c[i] = 1;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            b[i] = a[i] - a[i-1];
        }
        printf("Case #%d: ",ca);
        for(int i = n;i > 1;i--)
        {
            if(b[i]*c[i-1] < b[i-1]*c[i])
                c[i-1] = ceil(1.0*b[i-1]*c[i]/b[i]);
        }
        ll sum = 0;
        for(int i = 1;i <= n;i++)
            sum += c[i];
        printf("%lld\n",sum);
    }
    return 0;
}

