#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a[1005];
void Init()
{
    double x = 0.5;
    for(int i = 0;i < 1005;i++)
        a[i] = 0.5 - x,x *= 0.5;
}

int main()
{
    int t;
    cin >> t;
    double k;
    Init();
    while(t--)
    {
        scanf("%lf",&k);
        int pos = lower_bound(a,a+1005,k) - a;
        if(a[pos] == k)
            printf("-1\n");
        else
            printf("%d\n",pos*4);
    }
    return 0;
}
