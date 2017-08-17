#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
int sum[N];

struct node
{
    int l,r;//,num;
    operator < (const node & p)const
    {
        if(l == p.l)
            return r < p.r;
        return l < p.l;
    }
}p[N],q[N];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].l,&p[i].r);
        sort(p+1,p+n+1);

        int cnt = 0;
        for(int i = 1;i <= n;i++)
            if(cnt && q[cnt].r+1 >= p[i].l)
                q[cnt].r = max(q[cnt].r,p[i].r);
            else
                q[++cnt] = p[i];

        for(int i = 1;i <= cnt;i++)
            sum[i] = sum[i-1] + q[i].r-q[i].l+1;
        int pos = 1,ans = 0;
        for(int i = 1;i <= cnt;i++)
        {
            while(q[i].r-q[pos].l+1 - (sum[i]-sum[pos-1]) > m)
                pos++;
            ans = max(ans,sum[i]-sum[pos-1]+m);
        }
        printf("%d\n",ans);
    }
    return 0;
}
