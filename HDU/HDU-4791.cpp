#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
long long s[N],p[N],ps[N],minn[N],q;
int main()
{
    //ios_base::sync_with_stdio(0);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld%lld",&s[i],&p[i]);
            ps[i] = s[i]*p[i];
        }
        minn[n+1] = 1ll<<50;//就是因为这
        for(int i = n;i >= 1;i--)
            minn[i] = min(ps[i],minn[i+1]);
        long long sum;
        for(int i = 1;i <= m;i++)
        {
            scanf("%lld",&q);
            int pos = lower_bound(s+1,s+n+1,q) - s;
            //for(int j = pos;j <= n;j++)
            if(pos == 1)
            {
                printf("0\n");
                continue;
            }
            if(s[pos] == q)
                sum = min(q*p[pos],minn[pos]);
            else
                sum = min(q*p[pos-1],minn[pos]);
            printf("%lld\n",sum);
        }
    }
    return 0;
}
