#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,s;
struct status
{
    int x,v,dir;
}p[N];
bool check(double time)
{
    long long ll = 1e6,lr = 0,rl = 1e6,rr = 0,fl = 0,fr = 0;
    for(int i = 1;i <= n;i++)
    {
        if(p[i].dir == 1)//left
        {
            if(p[i].x-(p[i].v+s)*time >= 0)//can't arrive 0
                continue;
            fl = 1;
            if(p[i].x - p[i].v*time <= 0)//arrive
            {
                ll = 0;
                lr = 1e6;
                continue;
            }
            double t = (p[i].x-p[i].v*time)/(1.0*s);
            long long dx = (long long)(p[i].x+floor((s-p[i].v)*(time-t)));
            ll = min(ll,(long long)p[i].x);
            lr = max(lr,dx);
        }
        else
        {
            if(p[i].x+(p[i].v+s)*time <= 1e6)
                continue;
            fr = 1;
            if(p[i].x + p[i].v*time >= 1e6)
            {
                rl = 0;
                rr = 1e6;
                continue;
            }
            double t = (1e6-p[i].x-p[i].v*time)/(1.0*s);
            long long dx = (long long)(p[i].x-floor((s-p[i].v)*(time-t)));
            rl = min(rl,dx);
            rr = max(rr,(long long)p[i].x);
        }
    }
    if(!fl || !fr)
        return false;
    if(ll > lr || rl > rr)
        return false;
    return ll <= rr && lr >= rl;
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i = 1;i <= n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].v,&p[i].dir);
    double l = 0,r = 1e6,mid;
    int cnt = 0;
    while(cnt++ < 80)
    {
        mid = (l+r)/2;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.7f\n",r);
    return 0;
}
