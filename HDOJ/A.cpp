#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    double L;
    cin>>T;
    while(T--)
    {
        scanf("%lf",&L);
        double A = acos(5.0*sqrt(2) / 8.0);
        double B = asin(2.0 * sin(A));
        //cout<<A<<endl<<B<<endl;
        double S1 = 1/2.0 * 2.0 * A *L*L;
        double S2 = 1/2.0 * 2.0 * B *(L/2)*(L/2);
        //cout<<S1<<endl<<S2<<endl;
        //计算三角形的面积
        double a = L,b = L/2,c = L*sqrt(2.0)/2;
        double p = (a+b+c)/2.0;
        double S3 = sqrt(p*(p-a)*(p-b)*(p-c));
        //cout<<S3<<endl;
        double S = S2+2*S3-S1;
        printf("%.2f\n",S*2);
    }
}
