#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const int N = 100005;

int n,m;
double M;

struct node
{
    int u,v,t,f;
    double val;
    bool operator < (const node & p)const
    {
        return val < p.val;
    }
}p[N];

int f[N];
int getf(int t)
{
    return t == f[t]?t:f[t] = getf(f[t]);
}
bool judge(double k)
{
    for(int i = 1;i <= m;i++)
    {
        if(p[i].f)
            p[i].val = 1.0*p[i].t*k;
        else
            p[i].val = p[i].t;
    }
    sort(p+1,p+1+m);
    double res = 0;
    for(int i = 1;i <= n;i++)
        f[i] = i;
    for(int i = 1;i <= m;i++)
    {
        if(getf(p[i].u) == getf(p[i].v))//ÁªÍ¨
            continue;
        f[getf(p[i].u)] = getf(p[i].v);
        res += p[i].val;
        //if(res > M)
            //return false;
    }
    return res <= M;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%lf",&M);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d%d",&p[i].u,&p[i].v,&p[i].t,&p[i].f);
            //if(p[i].f)

        }
        //sort(p+1,p+1+m);
        double l = 1,r = 1e15,mid;
        int cnt = 0;
        while(cnt++ < 76)
        {
            mid = (l+r)/2;
            if(judge(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.6f\n",l);
    }
    return 0;
}

