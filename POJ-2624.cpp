#include <iostream>
#include<cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-6;
struct Point
{
    double x,y;
    Point(){};
    Point(double a,double b){
        x=a;y=b;
    }
};
Point operator - (const Point a,const Point b)
{
        return Point(a.x-b.x,a.y-b.y);
}

Point operator + (const Point a,const Point b)
{
       return Point(a.x+b.x,a.y+b.y);
}
int sgn(double d)
{
  return (d>+EPS)-(d<-EPS);
}


int iszero(Point a,Point b)
{
    if (sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0) return 1;
    else return 0;
}
Point p,q,r,s,t;
int main()
{//p,r,t,q
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&r.x,&r.y,&t.x,&t.y,&q.x,&q.y))
    {
        if(iszero(p,t))
            s = p + r - p + q -t;
        if(iszero(p,q))
            s = p + r - p + t - q;
        if(iszero(r,t))
            s = r + p - r + q - t;
        if(iszero(r,q))
            s = r + p - r + t - q;
        printf("%.3f %.3f\n",s.x,s.y);
    }
    return 0;
}
