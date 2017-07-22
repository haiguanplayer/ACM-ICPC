#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2005;
int a[N],b[N],sum[N];

int main()
{
    int k,n;
    cin >> k >> n;
    for(int i = 1;i <= k;i++)
        cin >> a[i],sum[i] = sum[i-1] + a[i];
    for(int i = 1;i <= n;i++)
        cin >> b[i];

    sort(sum+1,sum+k+1);
    int m = unique(sum+1,sum+k+1) - sum - 1;
    int ans = m;
    for(int i = 1;i <= m;i++)
    {
        int tmp = b[1] - sum[i];
        for(int j = 1;j <= n;j++)
            if(!binary_search(sum+1,sum+m+1,b[j]-tmp))
            {
                ans--;
                break;
            }
    }
    cout << ans << endl;
    return 0;
}
//-5 +5 +20  15 10 -10
