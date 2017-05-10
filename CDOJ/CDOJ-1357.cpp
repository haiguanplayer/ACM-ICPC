#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 500005;
int a[N],b[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);

    int sumA = -INF,sumB = -INF,sum = -INF;
    b[n+1] = -INF;
    for(int i = n;i > 2;i--)
    {
        sumA = sumA > 0 ? sumA+a[i] : a[i];
        b[i] = max(b[i+1],sumA);
    }

    int ans = -INF;
    for(int i = 1;i <= n-2;i++)
    {
        sumB = sumB > 0 ? sumB+a[i] : a[i];
        sum = sumB > sum ? sumB : sum;
        ans = max(sum + b[i+2] , ans);
    }
    printf("%d\n",ans);
}
