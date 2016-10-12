
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
//��p2ָ��p1
Vector operator - (const Point & p1,const Point & p2)
{
    return Vector(p1.x-p2.x,p1.y-p2.y);
}
//���ö����������0����ǰһ������������ʱ����תС��180�ȵõ��ڶ�������
bool operator < (const Point & p1,const Point & p2)
{//�Ƚ���ת��Ϊ����
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
