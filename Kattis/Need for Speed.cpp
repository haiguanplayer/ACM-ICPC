#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const int N = 1005;
int d[N],s[N];
int n,t;
bool judge(double m)
{
    double tt = 0;
    for(int i = 0;i < n;i++)
        tt += 1.0*d[i]/(1.0*s[i]+m);
    return tt <= t;
}
int main()
{
    cin >> n >> t;
    double l = -1e3,r = 1e6+1e3,mid;
    for(int i = 0;i < n;i++)
        scanf("%d%d",&d[i],&s[i]),l = max(l,(double)(-s[i]));

    while(r - l > eps)
    {
        mid = (l+r)/2;
        if(judge(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.9f\n",l);
    return 0;
}
