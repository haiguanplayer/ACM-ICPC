//递减函数
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double e = 2.718281828459;
double p,q,r,s,t,u;
double fun(double x)//p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0
{
    return p*pow(e,-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u))
    {
        if(fun(0) < 0 || fun(1) > 0)//没有等0的可能了，无解的情况
            printf("No solution\n");
        else
        {
            double r = 1,l = 0,mid = 0,cnt = 0;
            while(cnt++ < 1000)
            {
                mid = (r+l) / 2;
                if(fun(mid) > 0)
                    l = mid;
                else
                    r = mid;
            }
            printf("%.4f\n",mid);
        }
    }
    return 0;
}
