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
        int ans = 0;
        for(int i = 0;i < n;i++)
            if(a[i] + b[i] > 10)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
