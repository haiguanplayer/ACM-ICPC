#include<bits/stdc++.h>
using namespace std;


int main()
{
    int m,ca = 0;
    while(~scanf("%d",&m))
    {
        double ans = log10(2.0)*m;
        printf("Case #%d: %d\n",++ca,(int)ans);
    }
    return 0;
}
