#include<cstdio>
#include<cmath>
using namespace std;
double a[10005];
int n,k;
bool check(double x)
{
    int num = 0;
    for(int i = 0;i < n;i++)
        num += (int)(a[i]/x);
    return num >= k;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(int i = 0;i < n;i++)
            scanf("%lf",&a[i]);
        double left = 0,right = 1e5+5,mid;
        int cnt = 0;
        while(cnt++ < 105)
        {
            mid = (left+right)/2;
            if(check(mid))
                left = mid;
            else
                right = mid;
        }
        printf("%.2f\n",floor(left*100)/100);
    }
    return 0;
}
