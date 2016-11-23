#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b == 0?a:gcd(b,a%b);
}
int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        int x,y;
        int c = gcd(a,b);
        int temp = a*a - 4*b*c;
        int delta = sqrt(temp);
        bool flag = true;
        if(temp < 0)
            flag = false;
        if(delta*delta != temp || (a-delta)%2 != 0)
            flag = false;
        if(flag)
        {
            x = (a-delta) / 2;
            y = a - x;
            printf("%d %d\n",x,y);
        }
        else
            printf("No Solution\n");
    }
    return 0;
}
