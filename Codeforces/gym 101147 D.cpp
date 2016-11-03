#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll C(int n,int m)
{
    if(m == 0)
        return 1;
    return C(n,m-1) * (n-m+1) / m;
}
int main()
{
    freopen("popcorn.in", "r", stdin);
    int t,n,m;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);

        printf("%lld\n",C(n,m));
    }
    return 0;
}
