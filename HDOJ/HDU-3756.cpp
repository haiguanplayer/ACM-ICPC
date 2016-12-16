//learn from http://www.cnblogs.com/nanke/archive/2012/02/12/2348041.html
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double pi = acos(-1);
const double eps = 1e-8;
double x,y,l,w;
double cal(double a)
{
    double s = l*cos(a) + w*sin(a) - x;
    double h = s*tan(a) + w*cos(a);
    return h;
}
double TernarySearch(double l,double r)
{
    while(r - l > eps)
    {
        double ll = (l*2 + r) / 3;
        double rr = (l + r*2) / 3;
        double t1 = cal(ll),t2 = cal(rr);
        if(t1 < t2)
            l = ll;
        else
            r = rr;
    }
    return l;
}
int main()
{
    while(~scanf("%lf%lf%lf%lf",&x,&y,&l,&w))
    {
        double l = 0.0,r = pi / 2;
        double s = TernarySearch(l,r);
        if(cal(s) <= y)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
