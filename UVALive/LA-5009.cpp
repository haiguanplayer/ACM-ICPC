/*

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int n,a[N],b[N],c[N];
double f(double x)
{
    double maxn = a[0]*x*x+b[0]*x+c[0];
    for(int i = 1;i < n;i++)
        maxn = max(maxn,a[i]*x*x+b[i]*x+c[i]);
    return maxn;
}
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int cnt = 0;
        double l = 0,r = 1000,m1,m2;
        while(cnt++ < 100)
        {
            m1 = l+(r-l)/3;
            m2 = r-(r-l)/3;
            if(f(m1) < f(m2))
                r = m2;
            else
                l = m1;
        }
        printf("%.4f\n",f(m1));
     }
     return 0;
}

