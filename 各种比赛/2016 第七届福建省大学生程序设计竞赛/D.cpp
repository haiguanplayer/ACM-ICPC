#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 2e4+5;
int a[N],b[N];

int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        for(int i = 0;i < n;i++)
            scanf("%d",&b[i]);
        printf("Case %d: ",ca);
        sort(a,a+n);
        sort(b,b+n);
        double ans = 0;
        for(int i = 0;i < n;i++)
            ans += lower_bound(b,b+n,a[i])-b;
        printf("%.2f\n",ans/n);
    }
    return 0;
}

