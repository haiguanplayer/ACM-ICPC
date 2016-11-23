#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int N = 100005;
ll a[N],pre[N];

int main()
{
    int t,n,k;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d%d",&n,&k);
        ll sum = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            sum += a[i];
            pre[i] = pre[i-1] + a[i];
        }

        printf("Case #%d: ",ca);
        if(sum % k != 0)
            printf("-1\n");
        else
        {
            ll aver = sum / k,cnt = 0;
            for(int i = 1;i < n;i++)
            {
                if(pre[i] % aver == 0)
                    cnt++;
            }
            //printf("%lld\n",cnt);
            ll ans = n - 1 + k - 1 - cnt * 2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
