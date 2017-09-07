/*

*/
#include<bits/stdc++.h>
using namespace std;

//a^2+x^2�Ļ��ֹ�ʽ����
double f(double a,double x)
{
    double aa = a*a,xx = x*x;
    return (x*sqrt(aa+xx) + aa*log(fabs(x+sqrt(aa+xx))))/2;
}
//����������
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
        int n = (B+D-1)/D;//�����������ȡ��
        double len = 1.0*L/n;//����
        double width = 1.0*B/n;//���
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
