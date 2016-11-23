/*
Ьтвт
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
    int t,x;
    bool operator < (node p)
    {
        return t < p.t;
    }
}p[10005];
int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].t,&p[i].x);
        sort(p+1,p+1+n);
        printf("Case #%d: ",ca);
        double maxn = -1;
        for(int i = 1;i < n;i++)
            maxn = max(maxn,1.0*abs(p[i+1].x-p[i].x) / (p[i+1].t-p[i].t));
        printf("%.2f\n",maxn);
    }
}
