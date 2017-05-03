#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double pi = acos(-1);
int main()
{
    int n,d;
    while(~scanf("%d%d",&n,&d))
    {
        double ang,sum = 0.0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf",&ang);
            ang = ang / 180 * pi;
            sum += sin(ang);
        }
        printf("%.3f\n",sum*d*d*0.5);
    }
}
