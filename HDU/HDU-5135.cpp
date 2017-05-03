/*
max,so daxiao xianglin de san bian
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[15];
int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        double ans = 0.0,L;
        for(int i = n;i >= 3;i--)
        {
            int x = a[i],y = a[i-1],z = a[i-2];
            if(x+y > z && x-y < z)
            {
                L = (x+y+z) / 2.0;//º£Â×¹«Ê½
                ans += sqrt(L*(L-x)*(L-y)*(L-z));
                i -= 2;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
