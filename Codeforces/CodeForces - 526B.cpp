#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;


const int N = 1<<12;

int a[N];

int main()
{
    int n;
    cin>>n;
    int sum = (1<<(n+1)) - 1;//总结点数
    for(int i = 2;i <= sum;i++)
        scanf("%d",&a[i]);
    int ans = 0;
    for(int i = sum/2;i >= 1;i--)
    {
        a[i] += max(a[i << 1],a[i << 1 | 1]);
        ans += abs(a[i << 1]-a[i << 1 | 1]);
    }
    cout<<ans<<endl;
    return 0;
}
