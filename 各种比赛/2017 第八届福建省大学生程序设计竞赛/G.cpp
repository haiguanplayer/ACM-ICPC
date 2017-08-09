#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{

    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        printf("Case %d: ",ca);
        int ans = 0;
        while(n > 0)
        {
            ans++;
            n >>= 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//1 2 4 8 16
