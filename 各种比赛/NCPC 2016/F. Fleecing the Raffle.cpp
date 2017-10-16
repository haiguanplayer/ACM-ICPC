#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin >> n >> p;
    double maxn = 1.0*p/(n+1),cur;
    for(int i = 2; ;i++)
    {
        cur = maxn*i/(i-1) * (n-p+i)/(n+i);
        if(cur >= maxn)
            maxn = cur;
        else
            break;
    }
    cout << fixed << setprecision(8) << maxn << "\n";
    return 0;
}