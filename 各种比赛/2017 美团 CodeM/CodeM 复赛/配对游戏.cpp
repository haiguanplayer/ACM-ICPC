#include<bits/stdc++.h>
using namespace std;

//typedef long long ll;
const int N = 2005;
double f[N][N],g[N][N];

int main()
{
    int n;
    cin >> n;
    g[0][0] = 1;
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= i;j++)
        {
            g[i+1][j+1] += g[i][j]/2;
            f[i+1][j+1] += f[i][j]/2;
            if(!j)
                f[i+1][j] += f[i][j]/2,g[i+1][j] += g[i][j]/2;
            else
                f[i+1][j-1] += f[i][j]/2 + g[i][j],g[i+1][j-1] += g[i][j]/2;
        }
    double ans = n;
    for(int i = 0;i <= n;i++)
        ans -= f[n][i];
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
