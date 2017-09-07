/*

*/
#include<bits/stdc++.h>
using namespace std;

//a^2+x^2的积分公式代入
double f(double a,double x)
{
    double aa = a*a,xx = x*x;
    return (x*sqrt(aa+xx) + aa*log(fabs(x+sqrt(aa+xx))))/2;
}
//弧长定积分
double getlen(double width,double h)
{
    double a = 4.0*h/(width*width);
    double b = 1.0/(2*a);
    return (f(b,width/2)-f(b,0))*4*a;
}
int main()
{
    int T,D,H,B,L;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;ca++)
    {
        scanf("%d%d%d%d",&D,&H,&B,&L);
        int n = (B+D-1)/D;//间隔数，向上取整
        double len = 1.0*L/n;//长度
        double width = 1.0*B/n;//宽度
        double l = 0,r = H,mid;
        while(r-l > 1e-5)
        {
            mid = (l+r)/2;
            if(getlen(width,mid) < len)
                l = mid;
            else
                r = mid;
        }
        if(ca > 1)
            printf("\n");
        printf("Case %d:\n%.2f\n",ca,H-l);
    }
    return 0;
}
