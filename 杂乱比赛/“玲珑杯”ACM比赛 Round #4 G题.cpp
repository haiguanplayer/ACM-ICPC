#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100005;
double x[N],y[N],z[N];//zhu yi double
int main()
{
    int t,n;
    double a,b;
    cin >> t;
    while(t--)
    {
        scanf("%lf%lf%d",&a,&b,&n);
        int num = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            if(x[i] > a && y[i] > b)
                z[num++] = (y[i]-b)/(x[i]-a);
        }
        sort(z,z+num);
        int m = unique(z,z+num) - z;
        printf("%d\n",m);
    }
}
