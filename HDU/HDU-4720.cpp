#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
}p[4];
double across(point c,point a,point b)
{
    return (a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x);
}
double dot(point c,point a,point b)
{
	return (a.x-c.x)*(b.x-c.x) + (a.y-c.y)*(b.y-c.y);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        for(int i = 1;i <= 3;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double x,y;
        scanf("%lf%lf",&x,&y);
        double a,b,r2;//圆心。半径^2
        //钝角的话，圆心就在最长边的中点
        if(dot(p[1],p[2],p[3]) < 0)//1所在是钝角
        {
            a = (p[2].x+p[3].x)/2.0;
            b = (p[2].y+p[3].y)/2.0;
            r2 = (p[2].x-a)*(p[2].x-a) + (p[2].y-b)*(p[2].y-b);
        }
        else if(dot(p[2],p[1],p[3]) < 0)
        {
            a = (p[1].x+p[3].x)/2.0;
            b = (p[1].y+p[3].y)/2.0;
            r2 = (p[3].x-a)*(p[3].x-a) + (p[3].y-b)*(p[3].y-b);
        }
        else if(dot(p[3],p[1],p[2]) < 0)
        {
            a = (p[2].x+p[1].x)/2.0;
            b = (p[2].y+p[1].y)/2.0;
            r2 = (p[1].x-a)*(p[1].x-a) + (p[1].y-b)*(p[1].y-b);
        }
        else//三角形是非钝角三角形，直接求外心
        {//cout<<"RRR"<<"\n";
            double x1 = p[1].x,y1 = p[1].y,x2 = p[2].x,y2 = p[2].y,x3 = p[3].x,y3 = p[3].y;
            a = ((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1) - (y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
            b = ((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1) - (x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1) - (y2-y1)*(x3-x1)));
            r2 = (x1-a)*(x1-a) + (y1-b)*(y1-b);
        }

        double sum = (x-a)*(x-a) + (y-b)*(y-b);
        //cout<<sum<<" "<<r2<<"\n";
        if(sum > r2)
            printf("Case #%d: Safe\n",ca);
        else
            printf("Case #%d: Danger\n",ca);
    }
    return 0;
}
