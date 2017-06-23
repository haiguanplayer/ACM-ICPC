#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
double c[N],d[N];

int main()
{
    int n;
    double v,u;
    cin >> n >> v >> u;
    for(int i = 1;i <= n;i++)
        scanf("%lf",&c[i]);
    for(int i = 1;i <= n;i++)
        scanf("%lf",&d[i]);
    double ans = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            ans += u/(c[i]-(j-1)*d[i]-v);
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}