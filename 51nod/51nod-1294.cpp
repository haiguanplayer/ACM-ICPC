//similar with HDU 5256
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1000005;
int a[N],dp[N];
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        a[i] -= i;
        if(a[i] > 0)
            v.push_back(a[i]);
    }
    fill(dp,dp+n,INF);
    for(int i = 0;i < v.size();i++)
        *upper_bound(dp,dp+n,v[i]) = v[i];
    printf("%d\n",n - (lower_bound(dp,dp+n,INF)-dp));
    return 0;
}
