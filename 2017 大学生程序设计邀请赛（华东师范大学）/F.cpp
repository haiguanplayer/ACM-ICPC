#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int a[1005];
struct node
{
    int l,r,t;
    bool operator < (const node &p)const
    {/*
        if(r == p.r)
            return l < p.l;
        else*/
            return r < p.r;
    }
}p[1005];
int main()
{
    int t,n,m,k;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&k);
        int x;
        for(int i = 1;i <= k;i++)
        {
            scanf("%d",&x);
            a[x] = 1;
        }
        for(int i = 1;i <= m;i++)
            scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].t);
        sort(p+1,p+1+m);
        long long ans = 0;
        int sum;
        bool flag = false;
        for(int i = 1;i <= m;i++)
        {
            if(p[i].r-p[i].l+1 < p[i].t)
            {
                flag = true;
                break;
            }
            else
            {
                sum = 0;
                for(int j = p[i].l;j <= p[i].r;j++)
                {
                    if(a[j])
                        sum++;
                }

                if(sum < p[i].t)
                {
                    ans += 1ll*(p[i].t-sum);
                    int cnt = 0;
                    for(int j = p[i].r;j >= p[i].l;j--)
                    {
                        if(a[j] == 0)
                        {
                            a[j] = 1;
                            cnt++;
                            if(cnt == p[i].t-sum)
                                break;
                        }
                    }
                }
            }
        }
        printf("Case %d: ",ca);
        if(flag)
            printf("-1\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}
