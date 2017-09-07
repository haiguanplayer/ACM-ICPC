#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N];
int b[N];

bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n,cmp);
        int sum = 0;
        for(int i = 0;i < n;i++)
            sum += (a[i] + b[i]-m) <= 0? 0 : (a[i] + b[i]-m);
        printf("%d\n",sum);
    }
    return 0;


}
