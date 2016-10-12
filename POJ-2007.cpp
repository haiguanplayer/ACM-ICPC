
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Vector
{
    double x,y;
    Vector(int xx,int yy):x(xx),y(yy){}
    Vector(){}
    double operator ^ (const Vector & v)const
    {
        return x*v.y - y*v.x;
    }
};
#define Point Vector
//从p2指向p1
Vector operator - (const Point & p1,const Point & p2)
{
    return Vector(p1.x-p2.x,p1.y-p2.y);
}
//利用定理：叉积大于0，则前一个向量可以逆时针旋转小于180度得到第二个向量
bool operator < (const Point & p1,const Point & p2)
{//先将点转化为向量
    if((Vector(p2-Point(0,0)) ^ Vector(p1-Point(0,0)))>0)
        return true;
    return false;
}
Point ps[55];
int main()
{
    int n = 0;
    //while(scanf("%lf%lf",&ps[n].x,&ps[n].y) != EOF)
    while(cin>>ps[n].x>>ps[n].y)
        n++;
    sort(ps+1,ps+n);
    printf("(0,0)\n");
    for(int i = n-1;i > 0;i--)
        printf("(%.0f,%.0f)\n",ps[i].x,ps[i].y);
    return 0;
}
