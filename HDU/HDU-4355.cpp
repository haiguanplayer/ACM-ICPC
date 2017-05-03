#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-4;
const int N = 50005;
double x[N],w[N];
int n;
double cal(double d)
{
    double ans = 0;
    for(int i = 0;i < n;i++)
    {
        double S = fabs(x[i]-d);
        ans += w[i]*S*S*S;
    }
    return ans;
}
double TernarySearch(double l,double r)
{
    while(r - l > eps)
    {
        double ll = (l*2 + r) / 3;
        double rr = (l + r*2) / 3;
        double t1 = cal(ll),t2 = cal(rr);
        if(t1 > t2)
            l = ll;
        else
            r = rr;
    }
    return l;
}
int main()
{
    int t;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&x[i],&w[i]);
        double l = x[0],r = x[n-1];
        double s = TernarySearch(l,r);
        printf("Case #%d: %.0f\n",ca,cal(s));
    }
    return 0;
}
