#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,k;
    double n,m;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%lf%lf%d",&n,&m,&k);
        double ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                double p = 0;
                p += (i-1)*(j-1)*(n-i+1)*(m-j+1);
                p += (i-1)*(m-j)*(n-i+1)*j;
                p += (j-1)*(n-i)*(m-j+1)*i;
                p += (n-i)*(m-j)*i*j;
                p += n*m;
                p += (i-1)*m*(n-i+1);
                p += (m-j)*n*j;
                p += (n-i)*m*i;
                p += (j-1)*n*(m-j+1);
                p = p/n/n/m/m;
                ans += 1-pow(1-p,k);
            }
        }
        printf("Case #%d: %d\n",ca,(int)round(ans));
    }
    return 0;
}
